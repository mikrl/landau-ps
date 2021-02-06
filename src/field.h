#ifndef LANDAU_CORE_FIELD_H_
#define LANDAU_CORE_FIELD_H_

#include <pair>
#include <vector>

typedef struct FieldConfig {
  unsigned short int dimension;
  std::vector<std::pair<float, float>> spatial_extent;
  std::vector<unsigned long int> discretization;
}FieldConfig;

class Field{
private:
  unsigned short int _dimension;
  std::vector<float> _spatial_extent;
  std::vector<unsigned long int> _discretization;
  virtual void CreateField(FieldConfig configuration);

  public:
  Field(FieldConfig config);
};

#endif // LANDAU_CORE_FIELD_H_
