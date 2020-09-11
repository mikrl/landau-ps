# Get the testing library Catch2
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.9.1)

# Make Catch2 available
FetchContent_MakeAvailable(catch)


# Create the test executable
add_executable(testsuite tests.cxx)

# Want to use C++20 
target_compile_features(testsuite PRIVATE cxx_std_20)

# Libraries to be linked
target_link_libraries(testsuite PRIVATE cmake_test Catch2::Catch2)

add_test(NAME run_testsuite COMMAND testsuite)
