
import cibuildwheel.linux


def patched_build_in_container(
    *,
    options: Options,
    platform_configs: list[PythonConfiguration],
    container: OCIContainer,
    container_project_path: PurePath,
    container_package_dir: PurePath,
) -> None:
    container_output_dir = PurePosixPath("/output")

    log.step("Copying project into container...")
    container.copy_into(Path.cwd(), container_project_path)

    print("====================================")
    print(options)
    print(dir(options))

    before_all_options_identifier = platform_configs[0].identifier
    before_all_options = options.build_options(before_all_options_identifier)

    if before_all_options.before_all:
        log.step("Running before_all...")

        env = container.get_environment()
        env["PATH"] = f'/opt/python/cp38-cp38/bin:{env["PATH"]}'
        env["PIP_DISABLE_PIP_VERSION_CHECK"] = "1"
        env = before_all_options.environment.as_dictionary(
            env, executor=container.environment_executor
        )

        before_all_prepared = prepare_command(
            before_all_options.before_all,
            project=container_project_path,
            package=container_package_dir,
        )
        container.call(["sh", "-c", before_all_prepared], env=env)

    built_wheels: list[PurePosixPath] = []

    for config in platform_configs:
        log.build_start(config.identifier)
        build_options = options.build_options(config.identifier)

        dependency_constraint_flags: list[PathOrStr] = []

        if build_options.dependency_constraints:
            constraints_file = build_options.dependency_constraints.get_for_python_version(
                config.version
            )
            container_constraints_file = PurePath("/constraints.txt")

            container.copy_into(constraints_file, container_constraints_file)
            dependency_constraint_flags = ["-c", container_constraints_file]

        log.step("Setting up build environment...")

        env = container.get_environment()

        # put this config's python top of the list
        python_bin = config.path / "bin"
        env["PATH"] = f'{python_bin}:{env["PATH"]}'

        env = build_options.environment.as_dictionary(env, executor=container.environment_executor)

        # check config python is still on PATH
        which_python = container.call(["which", "python"], env=env, capture_output=True).strip()
        if PurePosixPath(which_python) != python_bin / "python":
            print(
                "cibuildwheel: python available on PATH doesn't match our installed instance. If you have modified PATH, ensure that you don't overwrite cibuildwheel's entry or insert python above it.",
                file=sys.stderr,
            )
            sys.exit(1)

        which_pip = container.call(["which", "pip"], env=env, capture_output=True).strip()
        if PurePosixPath(which_pip) != python_bin / "pip":
            print(
                "cibuildwheel: pip available on PATH doesn't match our installed instance. If you have modified PATH, ensure that you don't overwrite cibuildwheel's entry or insert pip above it.",
                file=sys.stderr,
            )
            sys.exit(1)

        compatible_wheel = find_compatible_wheel(built_wheels, config.identifier)
        if compatible_wheel:
            log.step_end()
            print(
                f"\nFound previously built wheel {compatible_wheel.name}, that's compatible with {config.identifier}. Skipping build step..."
            )
            repaired_wheels = [compatible_wheel]
        else:

            if build_options.before_build:
                log.step("Running before_build...")
                before_build_prepared = prepare_command(
                    build_options.before_build,
                    project=container_project_path,
                    package=container_package_dir,
                )
                container.call(["sh", "-c", before_build_prepared], env=env)

            log.step("Building wheel...")

            temp_dir = PurePosixPath("/tmp/cibuildwheel")
            built_wheel_dir = temp_dir / "built_wheel"
            container.call(["rm", "-rf", built_wheel_dir])
            container.call(["mkdir", "-p", built_wheel_dir])

            verbosity_flags = get_build_verbosity_extra_flags(build_options.build_verbosity)

            if build_options.build_frontend == "pip":
                container.call(
                    [
                        "python",
                        "-m",
                        "pip",
                        "wheel",
                        container_package_dir,
                        f"--wheel-dir={built_wheel_dir}",
                        "--no-deps",
                        *verbosity_flags,
                    ],
                    env=env,
                )
            elif build_options.build_frontend == "build":
                config_setting = " ".join(verbosity_flags)
                container.call(
                    [
                        "python",
                        "-m",
                        "build",
                        container_package_dir,
                        "--wheel",
                        f"--outdir={built_wheel_dir}",
                        f"--config-setting={config_setting}",
                    ],
                    env=env,
                )
            else:
                assert_never(build_options.build_frontend)

            built_wheel = container.glob(built_wheel_dir, "*.whl")[0]

            repaired_wheel_dir = temp_dir / "repaired_wheel"
            container.call(["rm", "-rf", repaired_wheel_dir])
            container.call(["mkdir", "-p", repaired_wheel_dir])

            if built_wheel.name.endswith("none-any.whl"):
                raise NonPlatformWheelError()

            if build_options.repair_command:
                log.step("Repairing wheel...")
                repair_command_prepared = prepare_command(
                    build_options.repair_command, wheel=built_wheel, dest_dir=repaired_wheel_dir
                )
                container.call(["sh", "-c", repair_command_prepared], env=env)
            else:
                container.call(["mv", built_wheel, repaired_wheel_dir])

            repaired_wheels = container.glob(repaired_wheel_dir, "*.whl")

            for repaired_wheel in repaired_wheels:
                if repaired_wheel.name in {wheel.name for wheel in built_wheels}:
                    raise AlreadyBuiltWheelError(repaired_wheel.name)

        if build_options.test_command and build_options.test_selector(config.identifier):
            log.step("Testing wheel...")

            # set up a virtual environment to install and test from, to make sure
            # there are no dependencies that were pulled in at build time.
            container.call(["pip", "install", "virtualenv", *dependency_constraint_flags], env=env)
            venv_dir = (
                PurePath(container.call(["mktemp", "-d"], capture_output=True).strip()) / "venv"
            )

            container.call(["python", "-m", "virtualenv", "--no-download", venv_dir], env=env)

            virtualenv_env = env.copy()
            virtualenv_env["PATH"] = f"{venv_dir / 'bin'}:{virtualenv_env['PATH']}"

            if build_options.before_test:
                before_test_prepared = prepare_command(
                    build_options.before_test,
                    project=container_project_path,
                    package=container_package_dir,
                )
                container.call(["sh", "-c", before_test_prepared], env=virtualenv_env)

            # Install the wheel we just built
            # Note: If auditwheel produced two wheels, it's because the earlier produced wheel
            # conforms to multiple manylinux standards. These multiple versions of the wheel are
            # functionally the same, differing only in name, wheel metadata, and possibly include
            # different external shared libraries. so it doesn't matter which one we run the tests on.
            # Let's just pick the first one.
            wheel_to_test = repaired_wheels[0]
            container.call(
                ["pip", "install", str(wheel_to_test) + build_options.test_extras],
                env=virtualenv_env,
            )

            # Install any requirements to run the tests
            if build_options.test_requires:
                container.call(["pip", "install", *build_options.test_requires], env=virtualenv_env)

            # Run the tests from a different directory
            test_command_prepared = prepare_command(
                build_options.test_command,
                project=container_project_path,
                package=container_package_dir,
            )
            container.call(["sh", "-c", test_command_prepared], cwd="/root", env=virtualenv_env)

            # clean up test environment
            container.call(["rm", "-rf", venv_dir])

        # move repaired wheels to output
        if compatible_wheel is None:
            container.call(["mkdir", "-p", container_output_dir])
            container.call(["mv", *repaired_wheels, container_output_dir])
            built_wheels.extend(
                container_output_dir / repaired_wheel.name for repaired_wheel in repaired_wheels
            )

        log.build_end()

    log.step("Copying wheels back to host...")
    # copy the output back into the host
    container.copy_out(container_output_dir, options.globals.output_dir)
    log.step_end()


cibuildwheel.linux.build_in_container = patched_build_in_container

