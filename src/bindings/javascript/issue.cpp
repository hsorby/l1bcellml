/*
Copyright libCellML Contributors

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <emscripten/bind.h>
#include <emscripten/emscripten.h>

#include "libcellml/issue.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(libcellml_issue) {

    enum_<libcellml::Issue::Level>("Issue.Level")
        .value("ERROR", libcellml::Issue::Level::ERROR)
        .value("WARNING", libcellml::Issue::Level::WARNING)
        .value("MESSAGE", libcellml::Issue::Level::MESSAGE)
    ;

    enum_<libcellml::Issue::ReferenceRule>("Issue.ReferenceRule")
        .value("UNDEFINED", libcellml::Issue::ReferenceRule::UNDEFINED)
        .value("XML", libcellml::Issue::ReferenceRule::XML)
        .value("DATA_REPR_IDENTIFIER_UNICODE", libcellml::Issue::ReferenceRule::DATA_REPR_IDENTIFIER_UNICODE)
        .value("DATA_REPR_IDENTIFIER_LATIN_ALPHANUM", libcellml::Issue::ReferenceRule::DATA_REPR_IDENTIFIER_LATIN_ALPHANUM)
        .value("DATA_REPR_IDENTIFIER_AT_LEAST_ONE_ALPHANUM", libcellml::Issue::ReferenceRule::DATA_REPR_IDENTIFIER_AT_LEAST_ONE_ALPHANUM)
        .value("DATA_REPR_IDENTIFIER_BEGIN_EURO_NUM", libcellml::Issue::ReferenceRule::DATA_REPR_IDENTIFIER_BEGIN_EURO_NUM)
        .value("DATA_REPR_IDENTIFIER_IDENTICAL", libcellml::Issue::ReferenceRule::DATA_REPR_IDENTIFIER_IDENTICAL)
        .value("DATA_REPR_INT_BASE10", libcellml::Issue::ReferenceRule::DATA_REPR_INT_BASE10)
        .value("DATA_REPR_INT_SIGN", libcellml::Issue::ReferenceRule::DATA_REPR_INT_SIGN)
        .value("DATA_REPR_INT_DIGIT", libcellml::Issue::ReferenceRule::DATA_REPR_INT_DIGIT)
        .value("DATA_REPR_BASIC_REAL_BASE10", libcellml::Issue::ReferenceRule::DATA_REPR_BASIC_REAL_BASE10)
        .value("DATA_REPR_BASIC_REAL_SIGN", libcellml::Issue::ReferenceRule::DATA_REPR_BASIC_REAL_SIGN)
        .value("DATA_REPR_BASIC_REAL_DECIMAL", libcellml::Issue::ReferenceRule::DATA_REPR_BASIC_REAL_DECIMAL)
        .value("DATA_REPR_BASIC_REAL_DIGIT", libcellml::Issue::ReferenceRule::DATA_REPR_BASIC_REAL_DIGIT)
        .value("DATA_REPR_REAL_BASE10", libcellml::Issue::ReferenceRule::DATA_REPR_REAL_BASE10)
        .value("DATA_REPR_REAL_SIGNIFICAND", libcellml::Issue::ReferenceRule::DATA_REPR_REAL_SIGNIFICAND)
        .value("DATA_REPR_REAL_EXPONENT", libcellml::Issue::ReferenceRule::DATA_REPR_REAL_EXPONENT)
        .value("MODEL_ELEMENT", libcellml::Issue::ReferenceRule::MODEL_ELEMENT)
        .value("MODEL_NAME", libcellml::Issue::ReferenceRule::MODEL_NAME)
        .value("MODEL_CHILD", libcellml::Issue::ReferenceRule::MODEL_CHILD)
        .value("MODEL_MORE_THAN_ONE_ENCAPSULATION", libcellml::Issue::ReferenceRule::MODEL_MORE_THAN_ONE_ENCAPSULATION)
        .value("IMPORT_ATTRIBUTE", libcellml::Issue::ReferenceRule::IMPORT_ATTRIBUTE)
        .value("IMPORT_HREF", libcellml::Issue::ReferenceRule::IMPORT_HREF)
        .value("IMPORT_CHILD", libcellml::Issue::ReferenceRule::IMPORT_CHILD)
        .value("IMPORT_EQUIVALENT", libcellml::Issue::ReferenceRule::IMPORT_EQUIVALENT)
        .value("IMPORT_UNITS_NAME", libcellml::Issue::ReferenceRule::IMPORT_UNITS_NAME)
        .value("IMPORT_UNITS_NAME_UNIQUE", libcellml::Issue::ReferenceRule::IMPORT_UNITS_NAME_UNIQUE)
        .value("IMPORT_UNITS_REF", libcellml::Issue::ReferenceRule::IMPORT_UNITS_REF)
        .value("IMPORT_COMPONENT_NAME", libcellml::Issue::ReferenceRule::IMPORT_COMPONENT_NAME)
        .value("IMPORT_COMPONENT_NAME_UNIQUE", libcellml::Issue::ReferenceRule::IMPORT_COMPONENT_NAME_UNIQUE)
        .value("IMPORT_COMPONENT_COMPONENT_REF", libcellml::Issue::ReferenceRule::IMPORT_COMPONENT_COMPONENT_REF)
        .value("UNITS_ATTRIBUTE", libcellml::Issue::ReferenceRule::UNITS_ATTRIBUTE)
        .value("UNITS_NAME", libcellml::Issue::ReferenceRule::UNITS_NAME)
        .value("UNITS_NAME_UNIQUE", libcellml::Issue::ReferenceRule::UNITS_NAME_UNIQUE)
        .value("UNITS_STANDARD", libcellml::Issue::ReferenceRule::UNITS_STANDARD)
        .value("UNITS_CHILD", libcellml::Issue::ReferenceRule::UNITS_CHILD)
        .value("UNIT_ATTRIBUTE", libcellml::Issue::ReferenceRule::UNIT_ATTRIBUTE)
        .value("UNIT_UNITS_REF", libcellml::Issue::ReferenceRule::UNIT_UNITS_REF)
        .value("UNIT_CIRCULAR_REF", libcellml::Issue::ReferenceRule::UNIT_CIRCULAR_REF)
        .value("UNIT_OPTIONAL_ATTRIBUTE", libcellml::Issue::ReferenceRule::UNIT_OPTIONAL_ATTRIBUTE)
        .value("UNIT_PREFIX", libcellml::Issue::ReferenceRule::UNIT_PREFIX)
        .value("UNIT_MULTIPLIER", libcellml::Issue::ReferenceRule::UNIT_MULTIPLIER)
        .value("UNIT_EXPONENT", libcellml::Issue::ReferenceRule::UNIT_EXPONENT)
        .value("COMPONENT_ATTRIBUTE", libcellml::Issue::ReferenceRule::COMPONENT_ATTRIBUTE)
        .value("COMPONENT_NAME", libcellml::Issue::ReferenceRule::COMPONENT_NAME)
        .value("COMPONENT_NAME_UNIQUE", libcellml::Issue::ReferenceRule::COMPONENT_NAME_UNIQUE)
        .value("COMPONENT_CHILD", libcellml::Issue::ReferenceRule::COMPONENT_CHILD)
        .value("VARIABLE_NAME", libcellml::Issue::ReferenceRule::VARIABLE_NAME)
        .value("VARIABLE_NAME_UNIQUE", libcellml::Issue::ReferenceRule::VARIABLE_NAME_UNIQUE)
        .value("VARIABLE_UNITS", libcellml::Issue::ReferenceRule::VARIABLE_UNITS)
        .value("VARIABLE_INTERFACE", libcellml::Issue::ReferenceRule::VARIABLE_INTERFACE)
        .value("VARIABLE_INITIAL_VALUE", libcellml::Issue::ReferenceRule::VARIABLE_INITIAL_VALUE)
        .value("RESET_ATTRIBUTE", libcellml::Issue::ReferenceRule::RESET_ATTRIBUTE)
        .value("RESET_VARIABLE_REF", libcellml::Issue::ReferenceRule::RESET_VARIABLE_REF)
        .value("RESET_TEST_VARIABLE_REF", libcellml::Issue::ReferenceRule::RESET_TEST_VARIABLE_REF)
        .value("RESET_ORDER", libcellml::Issue::ReferenceRule::RESET_ORDER)
        .value("RESET_CHILD", libcellml::Issue::ReferenceRule::RESET_CHILD)
        .value("RESET_TEST_VALUE", libcellml::Issue::ReferenceRule::RESET_TEST_VALUE)
        .value("RESET_RESET_VALUE", libcellml::Issue::ReferenceRule::RESET_RESET_VALUE)
        .value("MATH_MATHML", libcellml::Issue::ReferenceRule::MATH_MATHML)
        .value("MATH_CHILD", libcellml::Issue::ReferenceRule::MATH_CHILD)
        .value("MATH_CI_VARIABLE_REF", libcellml::Issue::ReferenceRule::MATH_CI_VARIABLE_REF)
        .value("MATH_CN_UNITS", libcellml::Issue::ReferenceRule::MATH_CN_UNITS)
        .value("MATH_CN_BASE10", libcellml::Issue::ReferenceRule::MATH_CN_BASE10)
        .value("MATH_CN_FORMAT", libcellml::Issue::ReferenceRule::MATH_CN_FORMAT)
        .value("ENCAPSULATION_ATTRIBUTE", libcellml::Issue::ReferenceRule::ENCAPSULATION_ATTRIBUTE)
        .value("ENCAPSULATION_CHILD", libcellml::Issue::ReferenceRule::ENCAPSULATION_CHILD)
        .value("COMPONENT_REF_COMPONENT", libcellml::Issue::ReferenceRule::COMPONENT_REF_COMPONENT)
        .value("COMPONENT_REF_CHILD", libcellml::Issue::ReferenceRule::COMPONENT_REF_CHILD)
        .value("CONNECTION_ATTRIBUTE", libcellml::Issue::ReferenceRule::CONNECTION_ATTRIBUTE)
        .value("CONNECTION_COMPONENT1", libcellml::Issue::ReferenceRule::CONNECTION_COMPONENT1)
        .value("CONNECTION_COMPONENT2", libcellml::Issue::ReferenceRule::CONNECTION_COMPONENT2)
        .value("CONNECTION_EXCLUDE_SELF", libcellml::Issue::ReferenceRule::CONNECTION_EXCLUDE_SELF)
        .value("CONNECTION_UNIQUE", libcellml::Issue::ReferenceRule::CONNECTION_UNIQUE)
        .value("CONNECTION_CHILD", libcellml::Issue::ReferenceRule::CONNECTION_CHILD)
        .value("MAP_VARIABLES_ATTRIBUTE", libcellml::Issue::ReferenceRule::MAP_VARIABLES_ATTRIBUTE)
        .value("MAP_VARIABLES_VARIABLE1", libcellml::Issue::ReferenceRule::MAP_VARIABLES_VARIABLE1)
        .value("MAP_VARIABLES_VARIABLE2", libcellml::Issue::ReferenceRule::MAP_VARIABLES_VARIABLE2)
        .value("MAP_VARIABLES_UNIQUE", libcellml::Issue::ReferenceRule::MAP_VARIABLES_UNIQUE)
        .value("MAP_VARIABLES_AVAILABLE_INTERFACE", libcellml::Issue::ReferenceRule::MAP_VARIABLES_AVAILABLE_INTERFACE)
        .value("MAP_VARIABLES_IDENTICAL_UNIT_REDUCTION", libcellml::Issue::ReferenceRule::MAP_VARIABLES_IDENTICAL_UNIT_REDUCTION)
        .value("INVALID_ARGUMENT", libcellml::Issue::ReferenceRule::INVALID_ARGUMENT)
        .value("IMPORTER_NULL_MODEL", libcellml::Issue::ReferenceRule::IMPORTER_NULL_MODEL)
        .value("IMPORTER_MISSING_COMPONENT", libcellml::Issue::ReferenceRule::IMPORTER_MISSING_COMPONENT)
        .value("IMPORTER_MISSING_UNITS", libcellml::Issue::ReferenceRule::IMPORTER_MISSING_UNITS)
        .value("ANALYSER_VARIABLE_INITIALISED_MORE_THAN_ONCE", libcellml::Issue::ReferenceRule::ANALYSER_VARIABLE_INITIALISED_MORE_THAN_ONCE)
        .value("ANALYSER_VARIABLE_NON_CONSTANT_INITIALISATION", libcellml::Issue::ReferenceRule::ANALYSER_VARIABLE_NON_CONSTANT_INITIALISATION)
        .value("ANALYSER_VOI_INITIALISED", libcellml::Issue::ReferenceRule::ANALYSER_VOI_INITIALISED)
        .value("ANALYSER_VOI_SEVERAL", libcellml::Issue::ReferenceRule::ANALYSER_VOI_SEVERAL)
        .value("ANALYSER_ODE_NOT_FIRST_ORDER", libcellml::Issue::ReferenceRule::ANALYSER_ODE_NOT_FIRST_ORDER)
        .value("ANALYSER_VARIABLE_UNUSED", libcellml::Issue::ReferenceRule::ANALYSER_VARIABLE_UNUSED)
        .value("ANALYSER_STATE_NOT_INITIALISED", libcellml::Issue::ReferenceRule::ANALYSER_STATE_NOT_INITIALISED)
        .value("ANALYSER_VARIABLE_COMPUTED_MORE_THAN_ONCE", libcellml::Issue::ReferenceRule::ANALYSER_VARIABLE_COMPUTED_MORE_THAN_ONCE)
        .value("ANALYSER_EXTERNAL_VARIABLE_DIFFERENT_MODEL", libcellml::Issue::ReferenceRule::ANALYSER_EXTERNAL_VARIABLE_DIFFERENT_MODEL)
        .value("ANALYSER_EXTERNAL_VARIABLE_VOI", libcellml::Issue::ReferenceRule::ANALYSER_EXTERNAL_VARIABLE_VOI)
        .value("ANALYSER_EXTERNAL_VARIABLE_USE_PRIMARY_VARIABLE", libcellml::Issue::ReferenceRule::ANALYSER_EXTERNAL_VARIABLE_USE_PRIMARY_VARIABLE)
        .value("UNSPECIFIED", libcellml::Issue::ReferenceRule::UNSPECIFIED)
    ;

    class_<libcellml::Issue>("Issue")
        .smart_ptr<std::shared_ptr<libcellml::Issue>>("Issue")
        .function("description", &libcellml::Issue::description)
        .function("level", &libcellml::Issue::level)
        .function("referenceRule", &libcellml::Issue::referenceRule)
        .function("item", &libcellml::Issue::item)
        .function("url", &libcellml::Issue::url)
        .function("referenceHeading", &libcellml::Issue::referenceHeading)
    ;

    EM_ASM(
        Module['Issue']['ReferenceRule'] = Module['Issue.ReferenceRule'];
        delete Module['Issue.ReferenceRule'];
        Module['Issue']['Level'] = Module['Issue.Level'];
        delete Module['Issue.Level'];
    );
}
