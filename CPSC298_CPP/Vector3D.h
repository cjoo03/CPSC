/// @brief Vector 3D Application Header File
/// CPSC-298-06 Programming in C++ Project Vector 3D
/// @author Chris Joo
#if !defined(VECTOR_3D_H)
#define VECTOR_3D_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Vector3D{
public:
  Vector3D();
  Vector3D(double dX, double dY, double dZ);
  ~Vector3D(){}
  double dot(Vector3D vec3d);
  void display();

private:
  std::vector<double> m_vector = {0, 0, 0};
};

#endif
