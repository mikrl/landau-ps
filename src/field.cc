// Copyright 2021 Michael Lynch. All rights reserved.
// Use of this source code is governed by an MIT-style license that can be
// found in the LICENSE file under the project root.

#include <iostream>
#include <vector>
#include <utility>

#include <boost/log/trivial.hpp>

#include "field.h"

Field::Field(FieldConfig config){
  dimension_ = config.dimension;
  spatial_extent_ = config.spatial_extent;
  discretization_ = config.discretization;
}

std::vector<float> Field::get_coordinate_at_cell(std::vector<unsigned long int> cell_indices){
  if (cell_indices.size() != this->discretization_.size()){
    BOOST_LOG_TRIVIAL(error) << "Wrong number of cell indices."
			     << "Is " << cell_indices.size()
			     << ", should be " << this->discretization_.size();
    return std::vector<float> {};
  } else {
    for (int idx = 0; idx < this->discretization_.size(); idx++){
      if (cell_indices[idx] >= this->discretization_[idx]){
	BOOST_LOG_TRIVIAL(error) << "Attempting to access out of bounds cell on axis " << idx
				 << ". Cell index is " << cell_indices[idx]
				 << ", should be at most " << this->discretization_[idx]-1;
	return std::vector<float> {};
      }
    }
  }

  // Got here means no errors.
  std::vector<float> spatial_coordinate(this->dimension_);

  for (int idx = 0; idx < spatial_coordinate.size(); idx++){
    std::pair<float, float> bounds = this->spatial_extent_[idx];
    float dim_min = bounds.first;
    float dim_max = bounds.second;

    unsigned long int cell_idx = cell_indices[idx];
    unsigned long int cell_max_idx = this->discretization_[idx];
    
    float delta_dim = (dim_max-dim_min)/cell_max_idx;
    

    spatial_coordinate[idx] = dim_min + cell_idx*delta_dim;
  }
    
  return spatial_coordinate;
}
