#ifndef LANDAU_CORE_SIMULATION_H_
#define LANDAU_CORE_SIMULATION_H_

#include <string>
#include <vector>

#include "field.h"
#include "particle.h"

/*! A class to hold a RESTful simulation API */

class Simulation{
 private:
  float time_;
  float delta_t_;

  std::vector<Particle> point_particles_;
  std::vector<Field> fields_;
  
 public:
  Simulation();

  void add_field();
  void add_particle();

  void step(); // advance by the time step

  std::string get_state(); // returns the simulation state in RESTful format
};
  

#endif // LANDAU_CORE_SIMULATION_H_
