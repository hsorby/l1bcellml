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
import subprocess

from setuptools import setup, Extension
from setuptools.dist import Distribution
from setuptools.command.install import install
from setuptools.command.build_ext import build_ext


doclines = __doc__.split("\n")


# This is a fake module to trick setuptools into creating a wheel.
_module_name = "libcellml"


class CMakeExtension(Extension):
    def __init__(self, name, cmake_lists_dir='.', sources=[], **kwa):
        Extension.__init__(self, name, sources=sources, **kwa)
        self.cmake_lists_dir = os.path.abspath(cmake_lists_dir)


class CMakeBuild(build_ext):

    def build_extensions(self):
        """
        This doesn't do anything but it fools setuptools into thinking that it does?
        Manylinux started to install libraries into a purelib folder which didn't pass muster.
        """
        for ext in self.extensions:

            extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
       

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
    ext_modules=[CMakeExtension(_module_name)],
    cmdclass={'build_ext': CMakeBuild},
    package_data={'libcellml': [@SETUP_PY_PACKAGE_FILES_STR@]},
    include_package_data=True,
    zip_safe=False,
)

