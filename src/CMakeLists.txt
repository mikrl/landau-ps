cmake_minimum_required(VERSION 3.10)

# For IDEs
set(HEADER_LIST "${Landau_SOURCE_DIR}/include/cmake_test.hxx")

# include_directories(cmake_test "../include")

add_library(cmake_test cmake_test.cxx ${HEADER_LIST})

target_include_directories(cmake_test PUBLIC ../include/)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

