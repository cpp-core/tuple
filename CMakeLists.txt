cmake_minimum_required (VERSION 3.24 FATAL_ERROR)
project (tuple VERSION 0.1 LANGUAGES C CXX)

# Make including this file idempotent
#
if(TARGET tuple::tuple)
  return()
endif()

# If this is the current project.
#
if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
  # Laod the cmake recipes and utilities.
  #
  include(${CMAKE_CURRENT_LIST_DIR}/cmake/load_cmake_helpers.cmake)
  
  # Options for generating tests and documentation.
  #
  option(TUPLE_TEST "Generate the tests." ON)
  option(TUPLE_DOCS "Generate the docs." OFF)

  # compile_commands.json
  #
  symlink_compile_commands()

  # Convenience targets for git operations
  #
  make_submodule_pull_target()

else()
  option(TUPLE_TEST "Generate the tests." OFF)
  option(TUPLE_DOCS "Generate the docs." OFF)
endif()

# Put executables in the top-level binary directory
#
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Output configuration
#
message("-- tuple: Configuration: ${CMAKE_CURRENT_SOURCE_DIR}")
message("-- tuple: Included from: ${CMAKE_SOURCE_DIR}")
message("-- tuple: Install prefix: ${CMAKE_INSTALL_PREFIX}")
message("-- tuple: Binary dir: ${CMAKE_BINARY_DIR}")
message("-- tuple: core dir: ${CPP_CORE_DIR}")
message("-- tuple: test ${TUPLE_TEST}")
message("-- tuple: docs ${TUPLE_DOCS}")

# Setup compilation before adding dependencies
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
add_compile_options(-stdlib=libc++)
add_compile_options(-O)
add_link_options(-stdlib=libc++)

# Add our dependencies
#
add_mp()

# Build the library
#
add_library(tuple INTERFACE)
add_library(tuple::tuple ALIAS tuple) # Allow interop between FetchContent and FindPackage.

# Define the header files for this library.
#
file(GLOB_RECURSE PUBLIC_INCLUDE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} include/*.h)
target_sources(tuple INTERFACE FILE_SET HEADERS BASE_DIRS include FILES ${PUBLIC_INCLUDE_FILES})

target_link_libraries(tuple INTERFACE mp::mp)

add_executable(tuple0 src/tools/tuple0.cpp)
target_link_libraries(tuple0 tuple mp::mp)

# Optionally configure the tests
#
if(TUPLE_TEST)
  add_gtest()
  add_subdirectory(test)
endif()

# Optionally configure the documentation
#
if(TUPLE_DOCS)
  add_subdirectory(docs)
endif()

# Install config
#
install_config(tuple)
