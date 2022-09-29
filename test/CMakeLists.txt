cmake_minimum_required (VERSION 3.22 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

cpp_core_find_package(GTest
  URL https://github.com/cpp-core/googletest
  VERSION v1.12.0
  EXCLUDE_FROM_ALL)
find_package(Threads REQUIRED)

set(TESTS
  tuple/find
  tuple/fold
  tuple/from_array
  tuple/from_container
  tuple/from_vector
  tuple/list
  tuple/map
  tuple/parse
  tuple/permute
  tuple/permute_array
  tuple/print
  tuple/remove
  tuple/to_array
  tuple/to_container
  tuple/to_vector
  )

set(LIBRARIES
  tuple
  GTest::gtest
  Threads::Threads
  )

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/configure_tests.cmake)
configure_tests("core" "${LIBRARIES}" ${TESTS})
