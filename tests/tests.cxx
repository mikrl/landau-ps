#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include<experiment.hxx>

/** SimConfig Test
 * Tests the SimConfig struct
 */
TEST_CASE("Test SimConfig", "[simcfg]" ){
  SimConfig test_simconfig  = {"cylindrical", {0.0}, "standard", "cli"};
  REQUIRE ( test_simconfig.geometry == "cylindrical");
  REQUIRE ( test_simconfig.extent[0] == 0.0) ;
  REQUIRE ( test_simconfig.discretization == "standard");
  REQUIRE ( test_simconfig.output == "cli");
}

TEST_CASE("Test FieldConfig", "[simcfg]" ){

  FieldConfig test_fieldconfig = {} ;

  REQUIRE ( test_simconfig.geometry == "cylindrical");
  REQUIRE ( test_simconfig.extent[0] == 0.0) ;
  REQUIRE ( test_simconfig.discretization == "standard");
  REQUIRE ( test_simconfig.output == "cli");
}

TEST_CASE("Initialize and delete a Simulation object", "[initsim]" ){
  SimConfig test_cfg;
  Simulation testsim (test_cfg);
  delete testsim;
  REQUIRE ( 0 );
}

TEST_CASE("Add a field", "[addfield]" ){
  SimConfig test_cfg;
  Simulation test_sim (test_cfg);
  test_sim.AddField()
  REQUIRE ( 0 );
}

TEST_CASE("Add a particle", "[addparticle]" ){
  SimConfig test_cfg;
  Simulation test_sim (test_cfg);
  REQUIRE ( 0 );
}

TEST_CASE("Test", "[main]" ){

  REQUIRE ( 0 );
}

TEST_CASE("Test", "[main]" ){

  REQUIRE ( 0 );
}

TEST_CASE("Test", "[main]" ){

  REQUIRE ( 0 );
}

TEST_CASE("Test", "[main]" ){

  REQUIRE ( 0 );
}

TEST_CASE("Test", "[main]" ){

  REQUIRE ( 0 );
}

// TEST_CASE("Test", "[main]" ){

//   REQUIRE ( 0 );
// }
