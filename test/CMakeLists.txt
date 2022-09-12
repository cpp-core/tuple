cmake_minimum_required (VERSION 3.22 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

find_package(googletest REQUIRED)
find_package(Threads REQUIRED)

set(TESTS
  tuple/apply
  tuple/find
  tuple/from_array
  tuple/from_container
  tuple/from_vector
  tuple/list
  tuple/map
#  tuple/parse
  tuple/permute
  tuple/permute_array
  tuple/print
  tuple/remove
  tuple/to_array
  tuple/to_container
  tuple/to_vector
  )

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/configure_tests.cmake)
set(LIBS "cxx_core_mp::cxx_core_mp;googletest::cxx-googletest;Threads::Threads")
configure_tests("core" "${LIBS}" ${TESTS})
