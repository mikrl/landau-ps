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
  unsigned long max_cells;
  std::string output;
} ;

//!  The Simulation class
/*!
  Initializes the simulation object ready to add particles, fields, etc
*/
class Simulation
{
private:
  long t_step_; 
  SpatialVolume free_space_;  
  std::vector<Field> fields_;
  std::vector<Particle*> particles_;
  std::vector<Material> materials_;
  std::vector<Force> forces_;
  
public:
  /** Constructor.
   * Returns a simulation object with default configuration (euclidean, 10m x 10m x 10m, 1000 cells)
   * Or takes a configuration as input and returns a pointer.
   */ 
  Simulation(); // default
  Simulation(const SimConfig configuration);
  /** Destructor.
   * Cleans up the Simulation object.
   */
  virtual ~Simulation();
  /** AddParticle.
   * Adds a new particle to the system with r=v=a=0 (all vector quants) and no interactions
   * Also can take a ParticleConfig as input to modify default values
   */
  void AddParticle();
  void AddParticle(ParticleConfig new_particle_cfg);
  /** RemoveParticle.
   * Takes a particle ID as input and removes the particle from the system.
   */
  void RemoveParticle(std::string particle_ID);
  /** AddField.
   * Takes a FieldConfig as input and adds a new force field to the system.
   */
  /** GetParticles.
   * Returns a vector containing the names of all the particles
   */
  std::vector<std::string> GetParticleList();
  /** GetConfiguration
   * Reads the Simulation configuration and returns the struct
   */
  SimConfig GetConfiguration();
  void AddField(FieldConfig new_field_cfg);
  /** RemoveField.
   * Takes a field ID as input and removes the field from the system.
   */
  void RemoveField(std::string field_ID);

  /** Solve.
   * Runs the solver and evolves the system according to active fields and forces
   */
  void Solve();
};


#endif
