// CPSC 298-6 "Programming in C++"
// jbonang@champman.edu
// Final Examination Programming Project: Exceptions
// File: exceptions.cpp

#include <iostream>
#include <stdexcept>
#include <string>

unsigned long sigma (unsigned long n){
  unsigned long sum = 0;

  try
  {
    if (n < 1){
      throw std::runtime_error("Precondition n>=1 violated: invalid value for argument n: ");
    }
    for (int i = 1; i <= n; i++){
        sum += i;
      }
    if (sum != (n * (n + 1) / 2)){
      throw std::runtime_error("Postcondition not met: sum must equal n(n+1)/2");
    }
  }

  catch (std::runtime_error & ex){
    std::cout << "Exception: " << ex.what() << std::endl;
    std::cout << "Cannot compute sum; returning 0" << std::endl;
    //sum = 0;
  }

  return sum;
}

int main() {
  int sum = sigma(5);
  std::cout << "sigma(5) = " << sum << std::endl;
  sum = sigma(0);
  std::cout << "sigma(0) = " << sum << std::endl;

  return 0;
}
