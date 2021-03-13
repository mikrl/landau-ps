#ifndef LANDAU_CORE_SCALARFIELD_H_
#define LANDAU_CORE_SCALARFIELD_H_

#include <eigen3/Eigen/Core>

#include "field.h"


class ScalarField: public Field{
private:
  Eigen::ArrayXXf field_values;

public:
  ScalarField(FieldConfig config);
  void InitializeFieldValues();
};

#endif
