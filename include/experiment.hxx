#ifndef EXPERIMENT_HXX
#define EXPERIMENT_HXX

#include<vector>
#include<memory>

//enum BoundaryConditions {periodic, fixed

struct SimConfig{
  string geometry;
  vector<float> extent;
  string discretization;
  string output;
} ;

class Simulation
{
private:
  long t_step;
  SpatialVolume _free_space;
  std::vector<*Field> _fields;
  std::vector<*Particle> _particles;
  std::vector<Material> _materials;
  
public:
  Simulation(const SimConfig configuration);
  AddParticle(ParticleConfig new_particle_cfg);
  RemoveParticle(unsigned int particle_ID);
  RemoveParticle(std::string particle_name);
  AddField(FieldConfig new_field_cfg);
  RemoveField(unsigned int field_ID);
  virtual ~Simulation();
};


#endif
