cmake_minimum_required (VERSION 3.24 FATAL_ERROR)

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

configure_tests("core" "${LIBRARIES}" ${TESTS})
