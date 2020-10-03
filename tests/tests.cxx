#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include<experiment.hxx>

/** SimConfig Test
 * Tests the SimConfig struct
 */
TEST_CASE("Test SimConfig", "[main]" ){
  SimConfig test_simconfig  = {"cylindrical", {0.0}, "standard", "cli"};
  REQUIRE ( test_simconfig.geometry == "cylindrical");
  REQUIRE ( test_simconfig.extent[0] == 0.0) ;
  REQUIRE ( test_simconfig.discretization == "standard");
  REQUIRE ( test_simconfig.output == "cli");
}
