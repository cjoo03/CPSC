#include <string>
#include <iostream>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student{
  public:
      Student();
      ~Student();
    //Overloaded Constructor
      Student(int studentID, string studentName, string studentLevel, string studentMajor, double studentGPA, int studentAdvisorID);
    //Copy Constructor
      Student(Student& other);
    //Accessors
      int getStudentID();
      string getStudentName() ;
      string getStudentLevel() ;
      string getStudentMajor() ;
      double getStudentGPA() ;
      int getStudentAdvisorID() ;
    //Mutators
      void setStudentID(int studentID);
      void setStudentName(string studentName);
      void setStudentLevel(string studentLevel);
      void setStudentMajor(string studentMajor);
      void setStudentGPA(double studentGPA);
      void setStudentAdvisorID(int studentAdvisorID);
    //Overloaded operators
      bool operator==(Student &other) ;
      bool operator!=(Student &other) ;
      bool operator<(Student &other) ;
      bool operator> (Student &other) ;
      void operator= (Student &other);
      void printStudentInfo();
  private:
      int m_student_ID; 
      string m_student_name; 
      string m_student_level; 
      string m_student_major; 
      double m_student_GPA; 
      int m_student_advisor_ID;
};

#endif