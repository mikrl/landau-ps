// Copyright 2021 Michael Lynch. All rights reserved.
// Use of this source code is governed by an MIT-style license that can be
// found in the LICENSE file under the project root.

#include <iostream>

#include "field.h"

Field::Field(FieldConfig config){
  auto dimension = config.dimension;
  auto extent = config.spatial_extent;
  auto discretization = config.discretization;
  
  _dimension = config.dimension;
  

  
  std::cout << "Generic field constructor." << endl;
}
