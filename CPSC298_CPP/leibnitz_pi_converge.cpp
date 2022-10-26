// @file Leibnitz_Pi_Converge
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
  double pi = 0.0;

  for (int n = 2; n <= 1048576; n){
    for (int k = 0; k <= n; k++){
      pi += (pow(-1.0,k)) / ((2.0 * k) + 1.0);
      }
    pi *= 4;
    cout << "PI: " << setprecision(15) << pi << "   n:  " << n << endl;
    n = n * 2;
    pi = 0;
  }

  return 0;

}
