#ifndef FREESPACE_HXX
#define FREESPACE_HXX

#include<vector>

class SpatialVolume
{
private:

public:
  FreeSpace(const CoordinateSystem coord,
	    const std::vector<double> coord_ranges,
	    const Discretization discret_scheme,
	    const unsigned int num_cells);  
};

#endif
