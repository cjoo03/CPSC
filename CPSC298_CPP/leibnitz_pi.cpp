// @file Leibnitz_Pi
// @brief
// @author Chris Joo

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cfloat>
using namespace std;

int main()
{
  const int n = 1048576; // 2^20
  double pi = 0.0;

  for (int k = 0; k <= n; k++){
    pi += (pow(-1.0,k)) / ((2.0 * k) + 1.0);
  }
  pi *= 4;

  cout << "Please enter a non-negative integer upper limit of summation for the Leibnitz formula for computing pi:" << endl;
  cout << n << endl;

  std::cout << "PI (approx): " << setprecision(16) << pi << "; n: " << std::setw(7) << n << std::endl;
  std::cout << "PI (actual): " << "3.141592653589793" << std::endl;
  std::cout << "Decimal digits of precision: " << DBL_DIG << std::endl;
  std::cout << "Number of base 2 mantissa digits of double precision floating point value: " <<  DBL_MANT_DIG << std::endl;
  std::cout << "Next representable number from 3.141592653589793: " << std::nextafter(3.141592653589793, 3.14) << std::endl;

  return 0;

}
