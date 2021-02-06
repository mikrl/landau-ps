#ifndef LANDAU_UTILS_CONFIGURATIONS_H_
#define LANDAU_UTILS_CONFIGURATIONS_H_

#include "core/field.h"

typedef struct FieldConfig {
  unsigned short int dimension;
  std::vector<float> spatial_extent;
  std::vector<unsigned long int> discretization;
}FieldConfig;

bool ConfigurationValid(FieldConfig config);


#endif // LANDAU_UTILS_CONFIGURATIONS_H_
