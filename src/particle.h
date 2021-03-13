#ifndef LANDAU_CORE_PARTICLE_H_
#define LANDAU_CORE_PARTICLE_H_

#include <map>
#include <string>
#include <vector>


enum CoordinateSystem { euclidean, polar, cylindrical, spherical };

typedef struct ParticleConfig{
  std::vector<float> init_position;
  std::vector<float> init_velocity;
  CoordinateSystem coordinate_system;
} ParticleConfig;

/*! A class specifying a particle or material point */

class Particle{
private:
  unsigned int dimensions_ = 3;
  std::vector<float> position_;
  std::vector<float> velocity_;
  // CoordinateSystem coordinate_system_;
  std::map<std::string, bool> properties_;


  
public:
  Particle();
  Particle(ParticleConfig config);
	   
  // Setters for position and velocity
  void set_position(std::vector<float> new_pos);
  void set_velocity(std::vector<float> new_pos);
  // Updates position and velocity over a time step
  void advance_position(float delta_t);
  void advance_velocity(float delta_t);
  // Gets physical properties of particle
  bool is_massive();
  bool is_charged();
};

#endif // LANDAU_CORE_PARTICLE_H_
