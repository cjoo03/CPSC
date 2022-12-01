#include <iostream>
#include <string>
using namespace std;

class ElectronicControlUnit
{
public:
  ElectronicControlUnit(){
    bool m_ActivatedHydraulicJacks = false; //Button A
    bool m_ActivatedBeltTires = false; //Button B
    bool m_ActivatedIRIllumination = false; //Button E
    bool Hstatus = false;
    bool Tstatus = false;
    bool Istatus = false;
  }
  void handleCommand(char cCommand){
    switch (cCommand) {
      case 'A':
      case 'a':
        actuateHydraulicJacks();
        break;
      case 'B':
      case 'b':
        actuateBeltTires();
        break;
      case 'E':
      case 'e':
        actuateIRIllumination();
        break;
      }
    }

void actuateHydraulicJacks(){
    m_ActivatedHydraulicJacks = true;
    if (m_ActivatedHydraulicJacks == true && Hstatus == false){
      cout << "Hydraulic Jacks Activated" << endl;
      Hstatus = true;
    }
    else if ((m_ActivatedHydraulicJacks == true) && (Hstatus == true)){
        cout << "Hydraulic Jacks deactivated" << endl;
        Hstatus = false;
    }
    if (m_ActivatedBeltTires == true){
      m_ActivatedBeltTires = false;
      cout << "Belt Tires deactivated due to Auto-Jack" << endl;;
    }
    }

  void actuateBeltTires(){
    m_ActivatedBeltTires = true;
    if (m_ActivatedBeltTires == true && Tstatus == false){
      cout << "Belt Tires Activated" << endl;
      Tstatus = true;
    }
    else if ((m_ActivatedBeltTires == true) && (Tstatus == true)){
      cout << "Belt Tires deactivated" << endl;
      Tstatus = false;
    }

  }

  void actuateIRIllumination(){
    m_ActivatedIRIllumination = true;
    if (m_ActivatedIRIllumination == true && Istatus == false){
      cout << "Infrared Illumination activated" << endl;
      Istatus = true;
    }
    else if (m_ActivatedIRIllumination == true && Istatus == true){
      cout << "Infrared Illumination deactivated" << endl;
      Istatus = false;
    }
  }

private:
  bool m_ActivatedHydraulicJacks; //Button A
  bool m_ActivatedBeltTires; //Button B
  bool m_ActivatedIRIllumination; //Button E
  bool Hstatus;
  bool Tstatus;
  bool Istatus;
};

int main()
{
  ElectronicControlUnit ecu;
  char userInput;
  while (userInput != 'X'){
    cout << "Press X to turn off ignition or enter a steering wheel button (A, B or E)" << endl;
    cout << "     (A)     " << endl;
    cout << "(F)  (G)  (B)" << endl;
    cout << "(E)       (C)" << endl;
    cout << "     (D)     " << endl;
    cin >> userInput;
    ecu.handleCommand(userInput);
    }
  }
