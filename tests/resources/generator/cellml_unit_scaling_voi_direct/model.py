# The content of this file was generated using the Python profile of libCellML 0.3.3.

from enum import Enum
from math import *


__version__ = "0.3.0"
LIBCELLML_VERSION = "0.3.3"

STATE_COUNT = 2
VARIABLE_COUNT = 0


class VariableType(Enum):
    VARIABLE_OF_INTEGRATION = 1
    STATE = 2
    CONSTANT = 3
    COMPUTED_CONSTANT = 4
    ALGEBRAIC = 5


VOI_INFO = {"name": "t", "units": "ms", "component": "environment", "type": VariableType.VARIABLE_OF_INTEGRATION}

STATE_INFO = [
    {"name": "x", "units": "dimensionless", "component": "main", "type": VariableType.STATE},
    {"name": "y", "units": "dimensionless", "component": "main", "type": VariableType.STATE}
]

VARIABLE_INFO = [
]


def create_states_array():
    return [nan]*STATE_COUNT


def create_variables_array():
    return [nan]*VARIABLE_COUNT


def initialise_variables(states, variables):
    states[0] = 3.0
    states[1] = 5.0


def compute_computed_constants(variables):
    pass


def compute_rates(voi, states, rates, variables):
    rates[0] = voi/1.0
    rates[1] = 0.001*voi/1.0


def compute_variables(voi, states, rates, variables):
    pass
