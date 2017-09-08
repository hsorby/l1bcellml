#!/usr/bin/env python
#
# Tests the Python bindings for libcellml
#
# How to run tests
# ----------------
# - Run all tests:
#       $ python run
#   In bash, simply "./run" is enough.
#
# - Run a specific set of tests
#       $ python run test1 test2 etc.
#
# How to write tests
# ------------------
# - All tests must be inside the 'test' folder, with names like `test*.py`.
# - Tests must be grouped in classes extending `unittest.TestCase`
# - Individual tests are methods with a name of the form `test_*(self)`.
# - Don't use asserts etc. but use methods like `self.assertEqual()`.
#   See: https://docs.python.org/3/library/unittest.html#assert-methods
#
import os
import sys
import unittest

# Current directory
ROOT = os.path.abspath(os.path.dirname(__file__))

# All tests
TEST = os.path.join(ROOT, 'tests')

# Load selected tests or discover all
loader = unittest.TestLoader()
tests = sys.argv[1:]
if tests:
    # Load selected tests
    # Make sure test module names start with 'test.'
    tests = [x if x[:5] == '.test' else 'test.' + x for x in tests]
    suite = loader.loadTestsFromNames(tests)
else:
    # Discover all tests
    loader = unittest.TestLoader()
    suite = loader.discover(TEST)

# Run!
unittest.TextTestRunner().run(suite)
