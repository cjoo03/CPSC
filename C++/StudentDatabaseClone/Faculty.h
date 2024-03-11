#include "DoublyList.h"
using namespace std;

#ifndef FACULTY_H
#define FACULTY_H

class Faculty{
    public:
        //Default constructor
        Faculty();
        //Overloaded constructor
        Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment);
        //Copy Constructor
        Faculty(const Faculty &faculty);
        //Destructor
        virtual ~Faculty();

        //Accessors
        int getFacultyID() const;
        string getFacultyName() const;
        string getFacultyLevel() const;
        string getFacultyDepartment() const;
        int getNumFacultyAdvisees() const;
        DoublyListNode<int>* getFacultyAdviseeIDFront() const;

        //Mutators
        void setFacultyID(int facultyID);
        void setFacultyName(string facultyName);
        void setFacultyLevel(string facultyLevel);
        void setFacultyDepartment(string facultyDepartment);

        //Check if a faculty member has a specific student based on the ID
        bool hasStudent(int studentID);

        //Check if a faculty member has any students
        bool facHasStudent();

        //Add a student to the faculty member's Linked-List of advisees
        void addFacultyAdviseeID(int studentID);

        //Remove a student from the faculty member's Linked-List of advisees
        void removeFacultyAdviseeID(int studentID);
        void printFacultyInfo();

        //Equality operators overloading
        bool operator==(const Faculty &faculty) const;
        bool operator!=(const Faculty &faculty) const;
        bool operator>(const Faculty &faculty) const;
        void operator=(const Faculty &faculty);
        bool operator<(const Faculty &faculty) const;

    private:
        string m_fac_department; 
        int m_num_fac_advisee; 
        DoublyList<int> m_fac_advisee_IDs;
        int m_fac_id;
        string m_fac_name; 
        string m_fac_level; 
};

#endif