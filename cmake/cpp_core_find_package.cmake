cmake_minimum_required (VERSION 3.24 FATAL_ERROR)

function(cpp_core_find_package NAME)
  cmake_parse_arguments(CCFP
    "" # options
    "VERSION" # single-value arguments
    "" # multi-value arguments
    ${ARGN}
    )
  message("-- cpp_core_find_package NAME: ${NAME}")
  message("-- cpp_core_find_package VERSION: ${CCFP_VERSION}")
  
  include(FetchContent)

  if (DEFINED CCFP_VERSION)
    FetchContent_Declare(
      ${NAME}
      GIT_REPOSITORY https://github.com/cpp-core/${NAME}
      GIT_TAG ${CCFP_VERSION}
      GIT_SHALLOW TRUE
      FIND_PACKAGE_ARGS
      )
  else()
    FetchContent_Declare(
      ${NAME}
      GIT_REPOSITORY https://github.com/cpp-core/${NAME}
      GIT_TAG main
      GIT_SHALLOW TRUE
      FIND_PACKAGE_ARGS
      )
  endif()
  
  FetchContent_MakeAvailable(${NAME})
  
endfunction()

function(cpp_core_find_package_local NAME URL)
  message("-- cpp_core_find_package_local NAME: ${NAME}")
  message("-- cpp_core_find_package_local URL: ${URL}")
  
  include(FetchContent)

  FetchContent_Declare(
    ${NAME}
    GIT_REPOSITORY ${URL}
    GIT_TAG main
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS
    )
  FetchContent_MakeAvailable(${NAME})
  
endfunction()
