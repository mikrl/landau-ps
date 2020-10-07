cmake_minimum_required(VERSION 3.10)

# Project name and settings
project(
  Landau
  VERSION 0.1
  DESCRIPTION "The Landau Physics Simulator"
  LANGUAGES CXX)

option(USE_CLANG "build application with clang" ON) # OFF is the default

if(USE_CLANG)
  set(CMAKE_C_COMPILER clang)
  set(CMAKE_CPP_COMPILER clang++)
endif(USE_CLANG)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  # Testing only available if this is the main app
  include(CTest)

endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)
# FetchContent_MakeAvailable was not added until CMake 3.14; use our shim
if(${CMAKE_VERSION} VERSION_LESS 3.14)
  include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()


# Add supporting source files
add_subdirectory(src)

# Add main executable
add_subdirectory(app)

# C++ standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Testing only available if this is the main app
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
   AND BUILD_TESTING)
  add_subdirectory(tests)
endif()
