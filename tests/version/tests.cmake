
set(CURRENT_TEST version)
set(${CURRENT_TEST}_CATEGORY api)
list(APPEND LIBCELLML_TESTS ${CURRENT_TEST})
set(${CURRENT_TEST}_SRCS
  ${CMAKE_CURRENT_LIST_DIR}/version.cpp
)

