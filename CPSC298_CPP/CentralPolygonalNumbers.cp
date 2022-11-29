#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class CentralPolygonalNumbers
{
public:
  CentralPolygonalNumbers(){
    m_nMax = 0;
  }
  CentralPolygonalNumbers(int nMax){
    mp_iNumbers = new int[nMax + 1];
    for (int n = 0; n <= nMax; n++){
      int p = (((n * n) + n + 2) / 2);
      mp_iNumbers[n] = p;
      cout << "n: " << n << "  maximum number of pieces: " << mp_iNumbers[n] << endl;
    }
  }
  ~CentralPolygonalNumbers(){
    delete [] mp_iNumbers;
    std::cout << "~CentralPolygonalNumbers called " << std::endl;
  }

  void save(string strFilename, int max){
    ofstream ofsNumbers;
    ofsNumbers.open(strFilename);
    for (int i = 0; i < max + 1; i++){
      ofsNumbers << mp_iNumbers[i] << endl;
    }
    ofsNumbers.close();
  }

private:
  int m_nMax;
  int* mp_iNumbers;
};

int main()
{
  CentralPolygonalNumbers cpn(10);
  cpn.save("CPN", 10);
}
