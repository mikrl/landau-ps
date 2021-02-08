// Copyright 2021 Michael Lynch. All rights reserved.
// Use of this source code is governed by an MIT-style license that can be
// found in the LICENSE file under the project root.

#include <boost/log/trivial.hpp>

#include "configurations.h"
#include "field.h"

bool ConfigurationValid(FieldConfig config){
  auto field_dimension = config.dimension;
  auto field_extent = config.spatial_extent;
  auto field_discretization = config.discretization;

  // Assume valid until otherwise.
  bool config_valid = true;
  
  // Verify that the field extent is the right size.
  if (field_extent.size() != field_dimension){
    BOOST_LOG_TRIVIAL(error) << "Wrong shape for field extent. "
			    << "Is " << field_extent.size()
			    << ", should be " << field_dimension;
    config_valid = false;
  }
  
  // Verify that the discretization is the right size.
  if (field_discretization.size() != field_dimension){
    BOOST_LOG_TRIVIAL(error) << "Wrong shape for field discretization. "
			    << "Is " << field_discretization.size()
			    << ", should be " << field_dimension;
    config_valid = false;
  } else {
    for (int idx = 0; idx < field_discretization.size(); idx++){
      if (not (field_discretization[idx] > 0)){
	BOOST_LOG_TRIVIAL(error) << "Discretization on dimension " << idx+1
				 << " must be greater than 0 cells.";
	config_valid = false;
      }
    }

  }

  
  return config_valid;
}
