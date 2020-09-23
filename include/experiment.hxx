#ifndef EXPERIMENT_HXX
#define EXPERIMENT_HXX

#include<vector>

enum BoundaryConditions {periodic, fixed

class FreeSpace
{
private:

public:
  FreeSpace(const CoordinateSystem coord,
	    const std::vector<double> coord_ranges,
	    const Discretization discret_scheme,
	    const unsigned int num_cells);  
};

#endif
