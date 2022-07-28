

from skbuild import setup

setup(
    name="libcellml",
    version="0.1.0",
    description="libCellML is a library for manipulating CellML models.",
    author="libCellML contributors",
    url="https://libcellml.org",
    license="Apache 2.0",
    packages=["libcellml"],
    package_dir={"": "src/bindings/python"},
    #cmake_args=["-DPYTHON_BINDINGS=ON", "-DSHARED_LIBS=OFF"],
    cmake_install_dir="src/bindings/python/libcellml",
    exclude_package_data={"": ["bin/*", "cmake/*", "include/*", "lib/*"]},
)
