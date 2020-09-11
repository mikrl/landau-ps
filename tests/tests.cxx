#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <cmake_test.hxx>

TEST_CASE(" Test vec2str ", "[main]" ){
  std::vector<char> testcase {'t','e','s','t'};
  auto ret_str = vec2str(testcase);

  REQUIRE (ret_str == "test");
}
