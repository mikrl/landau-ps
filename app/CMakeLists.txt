include_directories("../include")
add_executable(landau main.cxx)

target_link_libraries(landau PRIVATE cmake_test)
