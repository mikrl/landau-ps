#include <simulation.hxx>


Simulation::Simulation()
{
  SimConfig default_configuration;
  default_configuration.geometry = "euclidean";
  default_configuration.extent = {0.0, 10.0, 0.0, 10.0, 0.0, 10.0};
  default_configuration.max_cells = 1000;
  default_configuration.discretization = "standard";
  default_configuration.output = "cli";
  
  Simulation(SimConfig default_configuration);
}

Simulation::Simulation(SimConfig configuration)
{
    
}

Simulation::~Simulation()
{

}
