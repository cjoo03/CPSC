#include "Student.h"
#include <iomanip>

using namespace std;

//Default Constructor
Student::Student(){
  m_student_ID = 0;
  m_student_name = "";
  m_student_level = "";
  m_student_major = "";
  m_student_GPA = 0.00;
  m_student_advisor_ID = 0;
}

//Overloaded Constructor
Student::Student(int studentID, string studentName, string studentLevel, string studentMajor, double studentGPA, int studentAdvisorID){
  m_student_ID = studentID;
  m_student_name = studentName;
  m_student_level = studentLevel;
  m_student_major = studentMajor;
  m_student_GPA = studentGPA;
  m_student_advisor_ID = studentAdvisorID;
}

//Copy Constructor
Student::Student(Student& other){
  m_student_ID = other.getStudentID();
  m_student_name = other.getStudentName();
  m_student_level = other.getStudentLevel();
  m_student_major = other.getStudentMajor();
  m_student_GPA = other.getStudentGPA();
  m_student_advisor_ID = other.getStudentAdvisorID();
}

//Destructor
Student::~Student(){
}

//Mutators
void Student::setStudentName(string studentName){
  m_student_name = studentName;
}

void Student::setStudentID(int studentID){
  m_student_ID = studentID;
}

void Student::setStudentAdvisorID(int studentAdvisorID){
  m_student_advisor_ID = studentAdvisorID;
}

void Student::setStudentLevel(string studentLevel){
  m_student_level = studentLevel;
}

void Student::setStudentMajor(string studentMajor){
  m_student_major = studentMajor;
}

void Student::setStudentGPA(double studentGPA){
  m_student_GPA = studentGPA;
}

//Accessors
string Student::getStudentName(){
  return m_student_name;
}

string Student::getStudentLevel(){
  return m_student_level;
}

string Student::getStudentMajor(){
  return m_student_major;
}

int Student::getStudentID(){
  return m_student_ID;
}
int Student::getStudentAdvisorID(){
  return m_student_advisor_ID;
}

double Student::getStudentGPA(){
  return m_student_GPA;
}

//Overloaded operators
void Student::operator=(Student &other){
  m_student_ID = other.getStudentID();
  m_student_name = other.getStudentName();
  m_student_level = other.getStudentLevel();
  m_student_major = other.getStudentMajor();
  m_student_GPA = other.getStudentGPA();
  m_student_advisor_ID = other.getStudentAdvisorID();
}
bool Student::operator!=(Student &other){
  return (m_student_ID != other.getStudentID());
}

bool Student::operator==(Student &other){
  return (m_student_ID == other.getStudentID());
}

bool Student::operator<(Student &other){
  return (m_student_ID < other.getStudentID());
}

bool Student::operator>(Student &other){
  return (m_student_ID > other.getStudentID());
}


//Function that prints out all student info
void Student::printStudentInfo(){
  cout << "Student ID: " << m_student_ID << endl;
  cout << "Name: " << m_student_name << endl;
  cout << "Academic Level: " << m_student_level << endl;
  cout << "Major: " << m_student_major << endl;
  cout << fixed;
  cout << setprecision(2);
  cout << "GPA: " << m_student_GPA << endl;
  cout << "Advisor ID: " << m_student_advisor_ID << endl;
}
