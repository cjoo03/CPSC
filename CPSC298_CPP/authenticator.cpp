// @file authenticator
// @brief
// @author Chris Joo

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
  const char authenticatorCode1 = 'E';
  const char authenticatorCode2 = 'C';
  const char authenticatorCode3 = 'A';
  char userCode1;
  char userCode2;
  char userCode3;
  string authenticatorCode;
  string messageCode;
  const int validCodeCheck = 5;
  int checkSum;

  authenticatorCode.push_back(authenticatorCode1);
  authenticatorCode.push_back(authenticatorCode2);
  authenticatorCode.push_back(authenticatorCode3);

  cout << "Enter the first character of the message code: " << endl;
  cin >> userCode1;
  cout << "Enter the second character of the message code: " << endl;
  cin >> userCode2;
  cout << "Enter the third character of the message code: " << endl;
  cin >> userCode3;

  messageCode.push_back(userCode1);
  messageCode.push_back(userCode2);
  messageCode.push_back(userCode3);

  cout << endl;

  cout << "Authenticator Code: " << authenticatorCode << endl;
  cout << "Message Code: " << messageCode << endl << endl;

  if (userCode1 == authenticatorCode1 && userCode2 == authenticatorCode2 && userCode3 == authenticatorCode3){
    cout << "Message is authentic." << endl;
  }
  else {
    cout << "Message is invalid." << endl;
  }

  if (messageCode == authenticatorCode){
    cout << "Concurrence: Message is authentic" << endl;
  }
  else {
    cout << "Concurrence: Message is invalid" << endl;
  }

  cout << endl;

  checkSum = (int(userCode1) + int(userCode2) + int(userCode3)) % 7;

  if (checkSum == validCodeCheck){
    cout << "Message Code Checksum is Valid: " << checkSum << endl;
  }
  else {
    cout << "Message Code Checksum is invalid: " << checkSum << "; expected: " << validCodeCheck << endl;
  }

  cout << "ASCII values of Message Code Characters : " << int(userCode1) << ", " << int(userCode2) << ", " << int(userCode3) << endl;
  cout << "Sum of ASCII values for Message Code Characters: " << int(userCode1) + int(userCode2) + int(userCode3) << endl;

  if (userCode1 != authenticatorCode1){
    cout << "First Characters do not match: Message: " << userCode1 << "; Authenticator: " << authenticatorCode1 << endl;
   }
  if (userCode2 != authenticatorCode2){
     cout << "Second Characters do not match: Message: " << userCode2 << "; Authenticator: " << authenticatorCode2 << endl;
   }
  if (userCode3 != authenticatorCode3){
     cout << "Third Characters do not match: Message: " << userCode3 << "; Authenticator: " << authenticatorCode3  << endl;
   }

   if (messageCode < authenticatorCode){
     cout << "Message code (" << messageCode << ") is lexicographically less than Authenticator Code (" << authenticatorCode << ")" << endl;
   }
   else if (messageCode > authenticatorCode){
     cout << "Message code (" << messageCode << ") is lexicographically greater than Authenticator Code (" << authenticatorCode << ")" << endl;
   }

}
