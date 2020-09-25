#ifndef FREESPACE_HXX
#define FREESPACE_HXX

#include<vector>

struct CoordinateSystem{};
struct Discretization{};

class SpatialVolume
{
private:

public:
  SpatialVolume(const CoordinateSystem coord,
	    const std::vector<double> coord_ranges,
	    const Discretization discret_scheme,
	    const unsigned int num_cells);  
};

#endif
