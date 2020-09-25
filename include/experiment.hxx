#ifndef EXPERIMENT_HXX
#define EXPERIMENT_HXX

#include<freespace.hxx>
#include<field.hxx>
#include<particle.hxx>
#include<material.hxx>

#include <vector>
#include <memory>
#include <string>


//enum BoundaryConditions {periodic, fixed

struct SimConfig{
  std:: string geometry;
  std::vector<float> extent;
  std::string discretization;
  std::string output;
} ;

class Simulation
{
private:
  long t_step;
  SpatialVolume _free_space;
  std::vector<Field> _fields;
  std::vector<Particle> _particles;
  std::vector<Material> _materials;
  
public:
  Simulation(const SimConfig configuration);
  void AddParticle(ParticleConfig new_particle_cfg);
  void RemoveParticle(unsigned int particle_ID);
  void RemoveParticle(std::string particle_name);
  void AddField(FieldConfig new_field_cfg);
  void RemoveField(unsigned int field_ID);
  virtual ~Simulation();
};


#endif
