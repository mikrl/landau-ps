#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include<experiment.hxx>

#include <algorithm>

/** SimConfig Test
 * Tests the SimConfig struct
 */
TEST_CASE("Test SimConfig", "[simcfg]" ){
  SimConfig test_simconfig  = {"cylindrical", {0.0}, "standard", 100,  "cli"};
  REQUIRE ( test_simconfig.geometry == "cylindrical");
  REQUIRE ( test_simconfig.extent[0] == 0.0) ;
  REQUIRE ( test_simconfig.discretization == "standard");
  REQUIRE ( test_simconfig.output == "cli");
}

// TEST_CASE("Test FieldConfig", "[simcfg]" ){

//   FieldConfig test_fieldconfig = {} ;
  
//   REQUIRE (1);
// }

TEST_CASE("Initialize and delete a Simulation object", "[initsim]" ){
  // SimConfig test_cfg;
  Simulation* test_simulation = new Simulation  ();
  auto test_cfg = test_simulation->GetConfiguration();
    std::vector<float> test_extent {0.0, 10.0, 0.0, 10.0, 0.0, 10.0};
    
  REQUIRE(test_cfg.geometry == "euclidean");
  REQUIRE(test_cfg.extent == test_extent);
  REQUIRE(test_cfg.discretization == "standard");
  REQUIRE(test_cfg.max_cells == 1000);
  REQUIRE(test_cfg.output == "cli");
  delete test_simulation;
  //REQUIRE ( 1 );
}

// TEST_CASE("Add a field", "[addfield]" ){
//   SimConfig test_cfg;
//   Simulation test_sim (test_cfg);
//   test_sim.AddField()
//   REQUIRE ( 0 );
// }

TEST_CASE("Add and remove particles", "[addparticle]" ){
  SimConfig test_cfg;
  Simulation test_sim (test_cfg);
  auto particle_list = test_sim.GetParticleList();
  REQUIRE ( particle_list.size() == 0 );

  test_sim.AddParticle();
  particle_list = test_sim.GetParticleList();
  REQUIRE ( particle_list.size() == 1 );

  auto particle_ID = particle_list[0];
  test_sim.RemoveParticle(particle_ID);
  particle_list = test_sim.GetParticleList();
  REQUIRE ( particle_list.size() == 0 );  
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
