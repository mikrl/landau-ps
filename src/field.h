#ifndef LANDAU_CORE_FIELD_H_
#define LANDAU_CORE_FIELD_H_

#include <vector>
#include <utility>

/*! A struct holding the necessary information to configure a Field.*/
typedef struct FieldConfig {
  unsigned short int dimension; /*< Number of spatial dimensions.**/
  std::vector<std::pair<float, float>> spatial_extent; /*< The x_min and x_max for each dimension.**/
  std::vector<unsigned long int> discretization; /*< The number of cells per dimension.**/
}FieldConfig;

/*! An abstract class specifying a general field object */

class Field{
private:
  unsigned short int dimension_;
  std::vector<std::pair<float,float>> spatial_extent_;
  std::vector<unsigned long int> discretization_;
  void ConfigureField(FieldConfig configuration);

  public:
  virtual ~Field();
  //virtual void InitializeFieldValues() = 0;
  Field(FieldConfig config);

  std::vector<float> get_coordinate_at_cell(std::vector<unsigned long int> cell_index);

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
