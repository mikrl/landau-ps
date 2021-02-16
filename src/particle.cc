#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <boost/log/trivial.hpp>

#include "particle.h"



Particle::Particle(std::vector<float> init_position,
		   std::vector<float> init_velocity){  

  position_ = init_position;
  velocity_ = init_velocity;
  
}
