#ifndef EXPERIMENT_HXX
#define EXPERIMENT_HXX

#include<freespace.hxx>
#include<field.hxx>
#include<particle.hxx>
#include<material.hxx>
#include<force.hxx>

#include <vector>
#include <memory>
#include <string>


//enum BoundaryConditions {periodic, fixed, free}

struct SimConfig{
  std::string geometry;
  std::vector<float> extent;
  std::string discretization;
  std::string output;
} ;

//!  A test class. 
/*!
  A more elaborate class description.
*/
class Simulation
{
private:
  long t_step; 
  SpatialVolume _free_space;  
  std::vector<Field> _fields;
  std::vector<Particle> _particles;
  std::vector<Material> _materials;
  std::vector<Force> _forces;
  
public:
  /** Constructor.
   * Takes a configuration as input and returns a pointer.
   */
  Simulation(const SimConfig configuration);
  /** Destructor.
   * Cleans up the Simulation object.
   */
  virtual ~Simulation();
  /** AddParticle.
   * Takes a ParticleConfig as input and adds a new particle to the system.
   */
  void AddParticle(ParticleConfig new_particle_cfg);
  /** RemoveParticle.
   * Takes a particle ID as input and removes the particle from the system.
   * Or takes the particle name as a string and does the same.
   */
  void RemoveParticle(unsigned int particle_ID);
  void RemoveParticle(std::string particle_name);
  /** AddField.
   * Takes a FieldConfig as input and adds a new force field to the system.
   */
  void AddField(FieldConfig new_field_cfg);
  /** RemoveField.
   * Takes a field ID as input and removes the field from the system.
   * Or takes the field name as a string and does the same.
   */
  void RemoveField(unsigned int field_ID);
  void RemoveField(std::string field_name);

  /** Solve.
   * Runs the solver and evolves the system according to active fields and forces
   */
  void Solve();
};


#endif
