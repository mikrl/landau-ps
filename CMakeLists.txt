cmake_minimum_required(VERSION 3.10)

# Project name and settings
project(
  Landau
  VERSION 0.1
  DESCRIPTION "The Landau Physics Simulator"
  LANGUAGES CXX)

add_subdirectory(app)
add_subdirectory(src)

# C++ standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add main executable
add_executable()
