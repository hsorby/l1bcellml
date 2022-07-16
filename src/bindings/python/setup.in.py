""" libCellML Library: A library for the parsing, printing, and manipulation
of CellML 2.0 compliant models.

"""

classifiers = """\
Development Status :: 5 - Production/Stable
Intended Audience :: Developers
Intended Audience :: Education
Intended Audience :: Science/Research
License :: OSI Approved :: Apache Software License
Programming Language :: Python
Operating System :: Microsoft :: Windows
Operating System :: Unix
Operating System :: MacOS :: MacOS X
Topic :: Software Development :: Libraries :: Python Modules
"""

import os
from setuptools import setup
from setuptools.dist import Distribution
from setuptools.command.install import install

doclines = __doc__.split("\n")


try:
    from wheel.bdist_wheel import bdist_wheel as _bdist_wheel

    class bdist_wheel(_bdist_wheel):

        def finalize_options(self):
            _bdist_wheel.finalize_options(self)
            # Mark us as not a pure python package
            self.root_is_pure = False

        def get_tag(self):
            python, abi, plat = _bdist_wheel.get_tag(self)
            # We don't contain any python source
            #python, abi = 'py2.py3', 'none'
            print("=============")
            print("python:", python)
            print("abi:", abi)
            print("plat:", plat)
            return python, abi, plat

except ImportError:
    bdist_wheel = None


class BinaryDistribution(Distribution):
    def is_pure(self):
        return False

    def has_ext_modules(self):
        return True


setup(
    name='@PYPI_PACKAGE_NAME@',
    version='@PYPI_PACKAGE_VERSION@@PYPI_PACKAGE_DEVELOPER_VERSION@',
    author='libCellML developers',
    author_email='libcellml@googlegroups.com',
    packages=['libcellml'],
    #package_data={'libcellml': [@SETUP_PY_PACKAGE_FILES_STR@]},
    url='@PYPI_PACKAGE_URL@',
    license='Apache Software License',
    description=doclines[0],
    classifiers=classifiers.split("\n"),
    long_description=open('README.rst').read(),
    long_description_content_type='text/x-rst',
    distclass=BinaryDistribution,
    cmdclass={'bdist_wheel': bdist_wheel},
    include_package_data=True,
    zip_safe=False,
)
