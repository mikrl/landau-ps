#ifndef LANDAU_CORE_FIELD_H_
#define LANDAU_CORE_FIELD_H_

#include <vector>
#include <utility>


typedef struct FieldConfig {
  unsigned short int dimension;
  std::vector<std::pair<float, float>> spatial_extent;
  std::vector<unsigned long int> discretization;
}FieldConfig;

class Field{
private:
  unsigned short int dimension_;
  std::vector<float> spatial_extent_;
  std::vector<unsigned long int> _discretization_;
  virtual void InitializeField(FieldConfig configuration) = 0;

  public:
  virtual ~Field();
  Field(FieldConfig config);

  // // Field additive inverse
  // Field operator-() const;
  
  // // Field addition
  // Field operator+(const Field& addend_field);

  // // Field subtraction
  // Field operator-(const Field& subtrahend_field);
  
  // // Scalar multiplication
  // Field operator*(double scalar);
};

#endif // LANDAU_CORE_FIELD_H_
