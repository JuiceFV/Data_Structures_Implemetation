## Add unit test with mocking support
#  \param name unit test name (excluding extension and 'test_' prefix)
#  \param SOURCES optional list of source files to include in test executable
#  (beside test_${name}.c)
#  \param MOCKS optional list of functions to be mocked in executable
#  \param COMPILE_OPTIONS optional list of options for the compiler
#  \param LINK_LIBRARIES optional list of libraries to link (used as
#  -l${LINK_LIBRARIES})
#  \param LINK_OPTIONS optional list of options to be passed to linker
function(add_mocked_test name)
  # parse arguments passed to the function
  set(options )
  set(oneValueArgs )
  set(multiValueArgs SOURCES MOCKS COMPILE_OPTIONS LINK_LIBRARIES LINK_OPTIONS)
  cmake_parse_arguments(ADD_MOCKED_TEST "${options}" "${oneValueArgs}"
    "${multiValueArgs}" ${ARGN} )

  # create link flags for mocks
  set(link_flags "")
  foreach (mock ${ADD_MOCKED_TEST_MOCKS})
    set(link_flags "${link_flags} -Wl,--wrap=${mock}")
  endforeach(mock)

  # define test
  add_cmocka_test(test_${name}
                  SOURCES test_${name}.c ${ADD_MOCKED_TEST_SOURCES}
                  COMPILE_OPTIONS ${DEFAULT_C_COMPILE_FLAGS}
                                  ${ADD_MOCKED_TEST_COMPILE_OPTIONS}
                  LINK_LIBRARIES ${CMOCKA_SHARED_LIBRARY}
                                 ${ADD_MOCKED_TEST_LINK_LIBRARIES}
                  LINK_OPTIONS ${link_flags} ${ADD_MOCKED_TEST_LINK_OPTIONS})

  # allow using includes from src/ directory
  target_include_directories(test_${name} PRIVATE ${CMAKE_SOURCE_DIR}/src)
endfunction(add_mocked_test)