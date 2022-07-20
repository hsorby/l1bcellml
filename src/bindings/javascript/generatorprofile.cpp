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

#include "libcellml/generatorprofile.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(libcellml_generatorprofile)
{
    enum_<libcellml::GeneratorProfile::Profile>("GeneratorProfile.Profile")
        .value("C", libcellml::GeneratorProfile::Profile::C)
        .value("PYTHON", libcellml::GeneratorProfile::Profile::PYTHON)
    ;

    class_<libcellml::GeneratorProfile>("GeneratorProfile")
        .smart_ptr_constructor("GeneratorProfile", &libcellml::GeneratorProfile::create)
        .function("profile", &libcellml::GeneratorProfile::profile)
        .function("setProfile", &libcellml::GeneratorProfile::setProfile)
        .function("hasInterface", &libcellml::GeneratorProfile::hasInterface)
        .function("setHasInterface", &libcellml::GeneratorProfile::setHasInterface)
        .function("assignmentString", &libcellml::GeneratorProfile::assignmentString)
        .function("setAssignmentString", &libcellml::GeneratorProfile::setAssignmentString)
        .function("eqString", &libcellml::GeneratorProfile::eqString)
        .function("setEqString", &libcellml::GeneratorProfile::setEqString)
        .function("neqString", &libcellml::GeneratorProfile::neqString)
        .function("setNeqString", &libcellml::GeneratorProfile::setNeqString)
        .function("ltString", &libcellml::GeneratorProfile::ltString)
        .function("setLtString", &libcellml::GeneratorProfile::setLtString)
        .function("leqString", &libcellml::GeneratorProfile::leqString)
        .function("setLeqString", &libcellml::GeneratorProfile::setLeqString)
        .function("gtString", &libcellml::GeneratorProfile::gtString)
        .function("setGtString", &libcellml::GeneratorProfile::setGtString)
        .function("geqString", &libcellml::GeneratorProfile::geqString)
        .function("setGeqString", &libcellml::GeneratorProfile::setGeqString)
        .function("andString", &libcellml::GeneratorProfile::andString)
        .function("setAndString", &libcellml::GeneratorProfile::setAndString)
        .function("orString", &libcellml::GeneratorProfile::orString)
        .function("setOrString", &libcellml::GeneratorProfile::setOrString)
        .function("xorString", &libcellml::GeneratorProfile::xorString)
        .function("setXorString", &libcellml::GeneratorProfile::setXorString)
        .function("notString", &libcellml::GeneratorProfile::notString)
        .function("setNotString", &libcellml::GeneratorProfile::setNotString)
        .function("hasEqOperator", &libcellml::GeneratorProfile::hasEqOperator)
        .function("setHasEqOperator", &libcellml::GeneratorProfile::setHasEqOperator)
        .function("hasNeqOperator", &libcellml::GeneratorProfile::hasNeqOperator)
        .function("setHasNeqOperator", &libcellml::GeneratorProfile::setHasNeqOperator)
        .function("hasLtOperator", &libcellml::GeneratorProfile::hasLtOperator)
        .function("setHasLtOperator", &libcellml::GeneratorProfile::setHasLtOperator)
        .function("hasLeqOperator", &libcellml::GeneratorProfile::hasLeqOperator)
        .function("setHasLeqOperator", &libcellml::GeneratorProfile::setHasLeqOperator)
        .function("hasGtOperator", &libcellml::GeneratorProfile::hasGtOperator)
        .function("setHasGtOperator", &libcellml::GeneratorProfile::setHasGtOperator)
        .function("hasGeqOperator", &libcellml::GeneratorProfile::hasGeqOperator)
        .function("setHasGeqOperator", &libcellml::GeneratorProfile::setHasGeqOperator)
        .function("hasAndOperator", &libcellml::GeneratorProfile::hasAndOperator)
        .function("setHasAndOperator", &libcellml::GeneratorProfile::setHasAndOperator)
        .function("hasOrOperator", &libcellml::GeneratorProfile::hasOrOperator)
        .function("setHasOrOperator", &libcellml::GeneratorProfile::setHasOrOperator)
        .function("hasXorOperator", &libcellml::GeneratorProfile::hasXorOperator)
        .function("setHasXorOperator", &libcellml::GeneratorProfile::setHasXorOperator)
        .function("hasNotOperator", &libcellml::GeneratorProfile::hasNotOperator)
        .function("setHasNotOperator", &libcellml::GeneratorProfile::setHasNotOperator)
        .function("plusString", &libcellml::GeneratorProfile::plusString)
        .function("setPlusString", &libcellml::GeneratorProfile::setPlusString)
        .function("minusString", &libcellml::GeneratorProfile::minusString)
        .function("setMinusString", &libcellml::GeneratorProfile::setMinusString)
        .function("timesString", &libcellml::GeneratorProfile::timesString)
        .function("setTimesString", &libcellml::GeneratorProfile::setTimesString)
        .function("divideString", &libcellml::GeneratorProfile::divideString)
        .function("setDivideString", &libcellml::GeneratorProfile::setDivideString)
        .function("powerString", &libcellml::GeneratorProfile::powerString)
        .function("setPowerString", &libcellml::GeneratorProfile::setPowerString)
        .function("squareRootString", &libcellml::GeneratorProfile::squareRootString)
        .function("setSquareRootString", &libcellml::GeneratorProfile::setSquareRootString)
        .function("squareString", &libcellml::GeneratorProfile::squareString)
        .function("setSquareString", &libcellml::GeneratorProfile::setSquareString)
        .function("absoluteValueString", &libcellml::GeneratorProfile::absoluteValueString)
        .function("setAbsoluteValueString", &libcellml::GeneratorProfile::setAbsoluteValueString)
        .function("exponentialString", &libcellml::GeneratorProfile::exponentialString)
        .function("setExponentialString", &libcellml::GeneratorProfile::setExponentialString)
        .function("naturalLogarithmString", &libcellml::GeneratorProfile::naturalLogarithmString)
        .function("setNaturalLogarithmString", &libcellml::GeneratorProfile::setNaturalLogarithmString)
        .function("commonLogarithmString", &libcellml::GeneratorProfile::commonLogarithmString)
        .function("setCommonLogarithmString", &libcellml::GeneratorProfile::setCommonLogarithmString)
        .function("ceilingString", &libcellml::GeneratorProfile::ceilingString)
        .function("setCeilingString", &libcellml::GeneratorProfile::setCeilingString)
        .function("floorString", &libcellml::GeneratorProfile::floorString)
        .function("setFloorString", &libcellml::GeneratorProfile::setFloorString)
        .function("minString", &libcellml::GeneratorProfile::minString)
        .function("setMinString", &libcellml::GeneratorProfile::setMinString)
        .function("maxString", &libcellml::GeneratorProfile::maxString)
        .function("setMaxString", &libcellml::GeneratorProfile::setMaxString)
        .function("remString", &libcellml::GeneratorProfile::remString)
        .function("setRemString", &libcellml::GeneratorProfile::setRemString)
        .function("hasPowerOperator", &libcellml::GeneratorProfile::hasPowerOperator)
        .function("setHasPowerOperator", &libcellml::GeneratorProfile::setHasPowerOperator)
        .function("sinString", &libcellml::GeneratorProfile::sinString)
        .function("setSinString", &libcellml::GeneratorProfile::setSinString)
        .function("cosString", &libcellml::GeneratorProfile::cosString)
        .function("setCosString", &libcellml::GeneratorProfile::setCosString)
        .function("tanString", &libcellml::GeneratorProfile::tanString)
        .function("setTanString", &libcellml::GeneratorProfile::setTanString)
        .function("secString", &libcellml::GeneratorProfile::secString)
        .function("setSecString", &libcellml::GeneratorProfile::setSecString)
        .function("cscString", &libcellml::GeneratorProfile::cscString)
        .function("setCscString", &libcellml::GeneratorProfile::setCscString)
        .function("cotString", &libcellml::GeneratorProfile::cotString)
        .function("setCotString", &libcellml::GeneratorProfile::setCotString)
        .function("sinhString", &libcellml::GeneratorProfile::sinhString)
        .function("setSinhString", &libcellml::GeneratorProfile::setSinhString)
        .function("coshString", &libcellml::GeneratorProfile::coshString)
        .function("setCoshString", &libcellml::GeneratorProfile::setCoshString)
        .function("tanhString", &libcellml::GeneratorProfile::tanhString)
        .function("setTanhString", &libcellml::GeneratorProfile::setTanhString)
        .function("sechString", &libcellml::GeneratorProfile::sechString)
        .function("setSechString", &libcellml::GeneratorProfile::setSechString)
        .function("cschString", &libcellml::GeneratorProfile::cschString)
        .function("setCschString", &libcellml::GeneratorProfile::setCschString)
        .function("cothString", &libcellml::GeneratorProfile::cothString)
        .function("setCothString", &libcellml::GeneratorProfile::setCothString)
        .function("asinString", &libcellml::GeneratorProfile::asinString)
        .function("setAsinString", &libcellml::GeneratorProfile::setAsinString)
        .function("acosString", &libcellml::GeneratorProfile::acosString)
        .function("setAcosString", &libcellml::GeneratorProfile::setAcosString)
        .function("atanString", &libcellml::GeneratorProfile::atanString)
        .function("setAtanString", &libcellml::GeneratorProfile::setAtanString)
        .function("asecString", &libcellml::GeneratorProfile::asecString)
        .function("setAsecString", &libcellml::GeneratorProfile::setAsecString)
        .function("acscString", &libcellml::GeneratorProfile::acscString)
        .function("setAcscString", &libcellml::GeneratorProfile::setAcscString)
        .function("acotString", &libcellml::GeneratorProfile::acotString)
        .function("setAcotString", &libcellml::GeneratorProfile::setAcotString)
        .function("asinhString", &libcellml::GeneratorProfile::asinhString)
        .function("setAsinhString", &libcellml::GeneratorProfile::setAsinhString)
        .function("acoshString", &libcellml::GeneratorProfile::acoshString)
        .function("setAcoshString", &libcellml::GeneratorProfile::setAcoshString)
        .function("atanhString", &libcellml::GeneratorProfile::atanhString)
        .function("setAtanhString", &libcellml::GeneratorProfile::setAtanhString)
        .function("asechString", &libcellml::GeneratorProfile::asechString)
        .function("setAsechString", &libcellml::GeneratorProfile::setAsechString)
        .function("acschString", &libcellml::GeneratorProfile::acschString)
        .function("setAcschString", &libcellml::GeneratorProfile::setAcschString)
        .function("acothString", &libcellml::GeneratorProfile::acothString)
        .function("setAcothString", &libcellml::GeneratorProfile::setAcothString)
        .function("conditionalOperatorIfString", &libcellml::GeneratorProfile::conditionalOperatorIfString)
        .function("setConditionalOperatorIfString", &libcellml::GeneratorProfile::setConditionalOperatorIfString)
        .function("conditionalOperatorElseString", &libcellml::GeneratorProfile::conditionalOperatorElseString)
        .function("setConditionalOperatorElseString", &libcellml::GeneratorProfile::setConditionalOperatorElseString)
        .function("piecewiseIfString", &libcellml::GeneratorProfile::piecewiseIfString)
        .function("setPiecewiseIfString", &libcellml::GeneratorProfile::setPiecewiseIfString)
        .function("piecewiseElseString", &libcellml::GeneratorProfile::piecewiseElseString)
        .function("setPiecewiseElseString", &libcellml::GeneratorProfile::setPiecewiseElseString)
        .function("hasConditionalOperator", &libcellml::GeneratorProfile::hasConditionalOperator)
        .function("setHasConditionalOperator", &libcellml::GeneratorProfile::setHasConditionalOperator)
        .function("trueString", &libcellml::GeneratorProfile::trueString)
        .function("setTrueString", &libcellml::GeneratorProfile::setTrueString)
        .function("falseString", &libcellml::GeneratorProfile::falseString)
        .function("setFalseString", &libcellml::GeneratorProfile::setFalseString)
        .function("eString", &libcellml::GeneratorProfile::eString)
        .function("setEString", &libcellml::GeneratorProfile::setEString)
        .function("piString", &libcellml::GeneratorProfile::piString)
        .function("setPiString", &libcellml::GeneratorProfile::setPiString)
        .function("infString", &libcellml::GeneratorProfile::infString)
        .function("setInfString", &libcellml::GeneratorProfile::setInfString)
        .function("nanString", &libcellml::GeneratorProfile::nanString)
        .function("setNanString", &libcellml::GeneratorProfile::setNanString)
        .function("eqFunctionString", &libcellml::GeneratorProfile::eqFunctionString)
        .function("setEqFunctionString", &libcellml::GeneratorProfile::setEqFunctionString)
        .function("neqFunctionString", &libcellml::GeneratorProfile::neqFunctionString)
        .function("setNeqFunctionString", &libcellml::GeneratorProfile::setNeqFunctionString)
        .function("ltFunctionString", &libcellml::GeneratorProfile::ltFunctionString)
        .function("setLtFunctionString", &libcellml::GeneratorProfile::setLtFunctionString)
        .function("leqFunctionString", &libcellml::GeneratorProfile::leqFunctionString)
        .function("setLeqFunctionString", &libcellml::GeneratorProfile::setLeqFunctionString)
        .function("gtFunctionString", &libcellml::GeneratorProfile::gtFunctionString)
        .function("setGtFunctionString", &libcellml::GeneratorProfile::setGtFunctionString)
        .function("geqFunctionString", &libcellml::GeneratorProfile::geqFunctionString)
        .function("setGeqFunctionString", &libcellml::GeneratorProfile::setGeqFunctionString)
        .function("andFunctionString", &libcellml::GeneratorProfile::andFunctionString)
        .function("setAndFunctionString", &libcellml::GeneratorProfile::setAndFunctionString)
        .function("orFunctionString", &libcellml::GeneratorProfile::orFunctionString)
        .function("setOrFunctionString", &libcellml::GeneratorProfile::setOrFunctionString)
        .function("xorFunctionString", &libcellml::GeneratorProfile::xorFunctionString)
        .function("setXorFunctionString", &libcellml::GeneratorProfile::setXorFunctionString)
        .function("notFunctionString", &libcellml::GeneratorProfile::notFunctionString)
        .function("setNotFunctionString", &libcellml::GeneratorProfile::setNotFunctionString)
        .function("minFunctionString", &libcellml::GeneratorProfile::minFunctionString)
        .function("setMinFunctionString", &libcellml::GeneratorProfile::setMinFunctionString)
        .function("maxFunctionString", &libcellml::GeneratorProfile::maxFunctionString)
        .function("setMaxFunctionString", &libcellml::GeneratorProfile::setMaxFunctionString)
        .function("secFunctionString", &libcellml::GeneratorProfile::secFunctionString)
        .function("setSecFunctionString", &libcellml::GeneratorProfile::setSecFunctionString)
        .function("cscFunctionString", &libcellml::GeneratorProfile::cscFunctionString)
        .function("setCscFunctionString", &libcellml::GeneratorProfile::setCscFunctionString)
        .function("cotFunctionString", &libcellml::GeneratorProfile::cotFunctionString)
        .function("setCotFunctionString", &libcellml::GeneratorProfile::setCotFunctionString)
        .function("sechFunctionString", &libcellml::GeneratorProfile::sechFunctionString)
        .function("setSechFunctionString", &libcellml::GeneratorProfile::setSechFunctionString)
        .function("cschFunctionString", &libcellml::GeneratorProfile::cschFunctionString)
        .function("setCschFunctionString", &libcellml::GeneratorProfile::setCschFunctionString)
        .function("cothFunctionString", &libcellml::GeneratorProfile::cothFunctionString)
        .function("setCothFunctionString", &libcellml::GeneratorProfile::setCothFunctionString)
        .function("asecFunctionString", &libcellml::GeneratorProfile::asecFunctionString)
        .function("setAsecFunctionString", &libcellml::GeneratorProfile::setAsecFunctionString)
        .function("acscFunctionString", &libcellml::GeneratorProfile::acscFunctionString)
        .function("setAcscFunctionString", &libcellml::GeneratorProfile::setAcscFunctionString)
        .function("acotFunctionString", &libcellml::GeneratorProfile::acotFunctionString)
        .function("setAcotFunctionString", &libcellml::GeneratorProfile::setAcotFunctionString)
        .function("asechFunctionString", &libcellml::GeneratorProfile::asechFunctionString)
        .function("setAsechFunctionString", &libcellml::GeneratorProfile::setAsechFunctionString)
        .function("acschFunctionString", &libcellml::GeneratorProfile::acschFunctionString)
        .function("setAcschFunctionString", &libcellml::GeneratorProfile::setAcschFunctionString)
        .function("acothFunctionString", &libcellml::GeneratorProfile::acothFunctionString)
        .function("setAcothFunctionString", &libcellml::GeneratorProfile::setAcothFunctionString)
        .function("commentString", &libcellml::GeneratorProfile::commentString)
        .function("setCommentString", &libcellml::GeneratorProfile::setCommentString)
        .function("originCommentString", &libcellml::GeneratorProfile::originCommentString)
        .function("setOriginCommentString", &libcellml::GeneratorProfile::setOriginCommentString)
        .function("interfaceFileNameString", &libcellml::GeneratorProfile::interfaceFileNameString)
        .function("setInterfaceFileNameString", &libcellml::GeneratorProfile::setInterfaceFileNameString)
        .function("interfaceHeaderString", &libcellml::GeneratorProfile::interfaceHeaderString)
        .function("setInterfaceHeaderString", &libcellml::GeneratorProfile::setInterfaceHeaderString)
        .function("implementationHeaderString", &libcellml::GeneratorProfile::implementationHeaderString)
        .function("setImplementationHeaderString", &libcellml::GeneratorProfile::setImplementationHeaderString)
        .function("interfaceVersionString", &libcellml::GeneratorProfile::interfaceVersionString)
        .function("setInterfaceVersionString", &libcellml::GeneratorProfile::setInterfaceVersionString)
        .function("implementationVersionString", &libcellml::GeneratorProfile::implementationVersionString)
        .function("setImplementationVersionString", &libcellml::GeneratorProfile::setImplementationVersionString)
        .function("interfaceLibcellmlVersionString", &libcellml::GeneratorProfile::interfaceLibcellmlVersionString)
        .function("setInterfaceLibcellmlVersionString", &libcellml::GeneratorProfile::setInterfaceLibcellmlVersionString)
        .function("implementationLibcellmlVersionString", &libcellml::GeneratorProfile::implementationLibcellmlVersionString)
        .function("setImplementationLibcellmlVersionString", &libcellml::GeneratorProfile::setImplementationLibcellmlVersionString)
        .function("interfaceStateCountString", &libcellml::GeneratorProfile::interfaceStateCountString)
        .function("setInterfaceStateCountString", &libcellml::GeneratorProfile::setInterfaceStateCountString)
        .function("implementationStateCountString", &libcellml::GeneratorProfile::implementationStateCountString)
        .function("setImplementationStateCountString", &libcellml::GeneratorProfile::setImplementationStateCountString)
        .function("interfaceVariableCountString", &libcellml::GeneratorProfile::interfaceVariableCountString)
        .function("setInterfaceVariableCountString", &libcellml::GeneratorProfile::setInterfaceVariableCountString)
        .function("implementationVariableCountString", &libcellml::GeneratorProfile::implementationVariableCountString)
        .function("setImplementationVariableCountString", &libcellml::GeneratorProfile::setImplementationVariableCountString)
        .function("variableTypeObjectString", &libcellml::GeneratorProfile::variableTypeObjectString)
        .function("setVariableTypeObjectString", &libcellml::GeneratorProfile::setVariableTypeObjectString)
        .function("variableOfIntegrationVariableTypeString", &libcellml::GeneratorProfile::variableOfIntegrationVariableTypeString)
        .function("setVariableOfIntegrationVariableTypeString", &libcellml::GeneratorProfile::setVariableOfIntegrationVariableTypeString)
        .function("stateVariableTypeString", &libcellml::GeneratorProfile::stateVariableTypeString)
        .function("setStateVariableTypeString", &libcellml::GeneratorProfile::setStateVariableTypeString)
        .function("constantVariableTypeString", &libcellml::GeneratorProfile::constantVariableTypeString)
        .function("setConstantVariableTypeString", &libcellml::GeneratorProfile::setConstantVariableTypeString)
        .function("computedConstantVariableTypeString", &libcellml::GeneratorProfile::computedConstantVariableTypeString)
        .function("setComputedConstantVariableTypeString", &libcellml::GeneratorProfile::setComputedConstantVariableTypeString)
        .function("algebraicVariableTypeString", &libcellml::GeneratorProfile::algebraicVariableTypeString)
        .function("setAlgebraicVariableTypeString", &libcellml::GeneratorProfile::setAlgebraicVariableTypeString)
        .function("externalVariableTypeString", &libcellml::GeneratorProfile::externalVariableTypeString)
        .function("setExternalVariableTypeString", &libcellml::GeneratorProfile::setExternalVariableTypeString)
        .function("variableInfoObjectString", &libcellml::GeneratorProfile::variableInfoObjectString)
        .function("setVariableInfoObjectString", &libcellml::GeneratorProfile::setVariableInfoObjectString)
        .function("interfaceVoiInfoString", &libcellml::GeneratorProfile::interfaceVoiInfoString)
        .function("setInterfaceVoiInfoString", &libcellml::GeneratorProfile::setInterfaceVoiInfoString)
        .function("implementationVoiInfoString", &libcellml::GeneratorProfile::implementationVoiInfoString)
        .function("setImplementationVoiInfoString", &libcellml::GeneratorProfile::setImplementationVoiInfoString)
        .function("interfaceStateInfoString", &libcellml::GeneratorProfile::interfaceStateInfoString)
        .function("setInterfaceStateInfoString", &libcellml::GeneratorProfile::setInterfaceStateInfoString)
        .function("implementationStateInfoString", &libcellml::GeneratorProfile::implementationStateInfoString)
        .function("setImplementationStateInfoString", &libcellml::GeneratorProfile::setImplementationStateInfoString)
        .function("interfaceVariableInfoString", &libcellml::GeneratorProfile::interfaceVariableInfoString)
        .function("setInterfaceVariableInfoString", &libcellml::GeneratorProfile::setInterfaceVariableInfoString)
        .function("implementationVariableInfoString", &libcellml::GeneratorProfile::implementationVariableInfoString)
        .function("setImplementationVariableInfoString", &libcellml::GeneratorProfile::setImplementationVariableInfoString)
        .function("variableInfoEntryString", &libcellml::GeneratorProfile::variableInfoEntryString)
        .function("setVariableInfoEntryString", &libcellml::GeneratorProfile::setVariableInfoEntryString)
        .function("voiString", &libcellml::GeneratorProfile::voiString)
        .function("setVoiString", &libcellml::GeneratorProfile::setVoiString)
        .function("statesArrayString", &libcellml::GeneratorProfile::statesArrayString)
        .function("setStatesArrayString", &libcellml::GeneratorProfile::setStatesArrayString)
        .function("ratesArrayString", &libcellml::GeneratorProfile::ratesArrayString)
        .function("setRatesArrayString", &libcellml::GeneratorProfile::setRatesArrayString)
        .function("variablesArrayString", &libcellml::GeneratorProfile::variablesArrayString)
        .function("setVariablesArrayString", &libcellml::GeneratorProfile::setVariablesArrayString)
        .function("externalVariableMethodTypeDefinitionString", &libcellml::GeneratorProfile::externalVariableMethodTypeDefinitionString)
        .function("setExternalVariableMethodTypeDefinitionString", &libcellml::GeneratorProfile::setExternalVariableMethodTypeDefinitionString)
        .function("externalVariableMethodCallString", &libcellml::GeneratorProfile::externalVariableMethodCallString)
        .function("setExternalVariableMethodCallString", &libcellml::GeneratorProfile::setExternalVariableMethodCallString)
        .function("interfaceCreateStatesArrayMethodString", &libcellml::GeneratorProfile::interfaceCreateStatesArrayMethodString)
        .function("setInterfaceCreateStatesArrayMethodString", &libcellml::GeneratorProfile::setInterfaceCreateStatesArrayMethodString)
        .function("implementationCreateStatesArrayMethodString", &libcellml::GeneratorProfile::implementationCreateStatesArrayMethodString)
        .function("setImplementationCreateStatesArrayMethodString", &libcellml::GeneratorProfile::setImplementationCreateStatesArrayMethodString)
        .function("interfaceCreateVariablesArrayMethodString", &libcellml::GeneratorProfile::interfaceCreateVariablesArrayMethodString)
        .function("setInterfaceCreateVariablesArrayMethodString", &libcellml::GeneratorProfile::setInterfaceCreateVariablesArrayMethodString)
        .function("implementationCreateVariablesArrayMethodString", &libcellml::GeneratorProfile::implementationCreateVariablesArrayMethodString)
        .function("setImplementationCreateVariablesArrayMethodString", &libcellml::GeneratorProfile::setImplementationCreateVariablesArrayMethodString)
        .function("interfaceDeleteArrayMethodString", &libcellml::GeneratorProfile::interfaceDeleteArrayMethodString)
        .function("setInterfaceDeleteArrayMethodString", &libcellml::GeneratorProfile::setInterfaceDeleteArrayMethodString)
        .function("implementationDeleteArrayMethodString", &libcellml::GeneratorProfile::implementationDeleteArrayMethodString)
        .function("setImplementationDeleteArrayMethodString", &libcellml::GeneratorProfile::setImplementationDeleteArrayMethodString)
        .function("interfaceInitialiseVariablesMethodString", &libcellml::GeneratorProfile::interfaceInitialiseVariablesMethodString)
        .function("setInterfaceInitialiseVariablesMethodString", &libcellml::GeneratorProfile::setInterfaceInitialiseVariablesMethodString)
        .function("implementationInitialiseVariablesMethodString", &libcellml::GeneratorProfile::implementationInitialiseVariablesMethodString)
        .function("setImplementationInitialiseVariablesMethodString", &libcellml::GeneratorProfile::setImplementationInitialiseVariablesMethodString)
        .function("interfaceComputeComputedConstantsMethodString", &libcellml::GeneratorProfile::interfaceComputeComputedConstantsMethodString)
        .function("setInterfaceComputeComputedConstantsMethodString", &libcellml::GeneratorProfile::setInterfaceComputeComputedConstantsMethodString)
        .function("implementationComputeComputedConstantsMethodString", &libcellml::GeneratorProfile::implementationComputeComputedConstantsMethodString)
        .function("setImplementationComputeComputedConstantsMethodString", &libcellml::GeneratorProfile::setImplementationComputeComputedConstantsMethodString)
        .function("interfaceComputeRatesMethodString", &libcellml::GeneratorProfile::interfaceComputeRatesMethodString)
        .function("setInterfaceComputeRatesMethodString", &libcellml::GeneratorProfile::setInterfaceComputeRatesMethodString)
        .function("implementationComputeRatesMethodString", &libcellml::GeneratorProfile::implementationComputeRatesMethodString)
        .function("setImplementationComputeRatesMethodString", &libcellml::GeneratorProfile::setImplementationComputeRatesMethodString)
        .function("interfaceComputeVariablesMethodString", &libcellml::GeneratorProfile::interfaceComputeVariablesMethodString)
        .function("setInterfaceComputeVariablesMethodString", &libcellml::GeneratorProfile::setInterfaceComputeVariablesMethodString)
        .function("implementationComputeVariablesMethodString", &libcellml::GeneratorProfile::implementationComputeVariablesMethodString)
        .function("setImplementationComputeVariablesMethodString", &libcellml::GeneratorProfile::setImplementationComputeVariablesMethodString)
        .function("emptyMethodString", &libcellml::GeneratorProfile::emptyMethodString)
        .function("setEmptyMethodString", &libcellml::GeneratorProfile::setEmptyMethodString)
        .function("indentString", &libcellml::GeneratorProfile::indentString)
        .function("setIndentString", &libcellml::GeneratorProfile::setIndentString)
        .function("openArrayInitialiserString", &libcellml::GeneratorProfile::openArrayInitialiserString)
        .function("setOpenArrayInitialiserString", &libcellml::GeneratorProfile::setOpenArrayInitialiserString)
        .function("closeArrayInitialiserString", &libcellml::GeneratorProfile::closeArrayInitialiserString)
        .function("setCloseArrayInitialiserString", &libcellml::GeneratorProfile::setCloseArrayInitialiserString)
        .function("openArrayString", &libcellml::GeneratorProfile::openArrayString)
        .function("setOpenArrayString", &libcellml::GeneratorProfile::setOpenArrayString)
        .function("closeArrayString", &libcellml::GeneratorProfile::closeArrayString)
        .function("setCloseArrayString", &libcellml::GeneratorProfile::setCloseArrayString)
        .function("arrayElementSeparatorString", &libcellml::GeneratorProfile::arrayElementSeparatorString)
        .function("setArrayElementSeparatorString", &libcellml::GeneratorProfile::setArrayElementSeparatorString)
        .function("stringDelimiterString", &libcellml::GeneratorProfile::stringDelimiterString)
        .function("setStringDelimiterString", &libcellml::GeneratorProfile::setStringDelimiterString)
        .function("commandSeparatorString", &libcellml::GeneratorProfile::commandSeparatorString)
        .function("setCommandSeparatorString", &libcellml::GeneratorProfile::setCommandSeparatorString)
    ;

    EM_ASM(
        Module['GeneratorProfile']['Profile'] = Module['GeneratorProfile.Profile'];
        delete Module['GeneratorProfile.Profile'];
    );
}
