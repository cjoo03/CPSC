// @file MusicalNotesFreq
// @brief Calculates the frequency of musical notes
// @author Chris Joo

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
  double refFreq = 16.35;
  double dTwelfthRootofTwo = 1.059463094359;
  int soundSpeed = 345;
  double cSharp0;
  double d0;
  double c4;
  double dSharp7;
  double c8;

  cSharp0 = refFreq * pow(2,0) * pow(dTwelfthRootofTwo, 1);
  d0 = refFreq * pow(2,0) * pow(dTwelfthRootofTwo, 2);
  c4 = refFreq * pow(2,4) * pow(dTwelfthRootofTwo, 0);
  dSharp7 = refFreq * pow(2,7) * pow(dTwelfthRootofTwo, 3);
  c8 = refFreq * pow(2,8) * pow(dTwelfthRootofTwo, 0);


  cout << "Reference Frequency: " << refFreq << " Hz" << endl;
  cout << "Speed of Sound: " << soundSpeed << " m/s" << endl;
  cout << "Note: C0   nu: 0  k: 0  frequency: " << refFreq << " Hz    wavelength: " << (soundSpeed / refFreq) * 100 << " cm " << endl;
  cout << "Note: C#0  nu: 0  k: 1  frequency: " << cSharp0 << " Hz  wavelength: " << (soundSpeed / cSharp0) * 100 << " cm " << endl;
  cout << "Note: D0   nu: 0  k: 2  frequency: " << d0 << " Hz  wavelength: " << (soundSpeed / d0) * 100 << " cm " << endl;
  cout << "Note: C4   nu: 4  k: 0  frequency: " << c4 << " Hz    wavelength: " << (soundSpeed / c4) * 100 << " cm " << endl;
  cout << "Note: D#7  nu: 7  k: 3  frequency: " << dSharp7 << " Hz  wavelength: " << (soundSpeed / dSharp7) * 100 << " cm " << endl;
  cout << "Note: C8   nu: 8  k: 0  frequency: " << c8 << " Hz   wavelength: " << (soundSpeed / c8) * 100 << " cm " << endl;
}
