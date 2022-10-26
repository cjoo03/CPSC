#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include "Vector3D.h"

Vector3D::Vector3D(){ //default constructor
  m_vector.at(0) = 0;
  m_vector.at(1) = 0;
  m_vector.at(2) = 0;
}

Vector3D::Vector3D(double dX, double dY, double dZ){
  m_vector.at(0) = dX;
  m_vector.at(1) = dY;
  m_vector.at(2) = dZ;
}

void Vector3D::display(){
  std::cout << m_vector.at(0) << std::endl;
  std::cout << m_vector.at(1) << std::endl;
  std::cout << m_vector.at(2) << std::endl;
}

double Vector3D::dot(Vector3D vec3d){
  double dDotProduct = 0.0;
  for (unsigned int i = 0; i < this->m_vector.size(); i++){
    dDotProduct += this->m_vector.at(i) * vec3d.m_vector.at(i);
  }
  return dDotProduct;
  }
