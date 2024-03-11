#include "Faculty.h"

using namespace std;

//Default constructor
Faculty::Faculty(){
  m_fac_id = 0;
  m_fac_name = "";
  m_fac_level = "";
  m_fac_department = "";
  m_num_fac_advisee = 0;
}

//Destructor
Faculty::~Faculty(){
}

//Overloaded constructor 
Faculty::Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment){
  m_fac_id = facultyID;
  m_fac_name = facultyName;
  m_fac_level = facultyLevel;
  m_fac_department = facultyDepartment;
  m_num_fac_advisee = 0;
}

// Copy Constructor
Faculty::Faculty(const Faculty &faculty) {
    // Copy all of the member variables from faculty
    m_fac_id = faculty.getFacultyID();
    m_fac_name = faculty.getFacultyName();
    m_fac_level = faculty.getFacultyLevel();
    m_fac_department = faculty.getFacultyDepartment();

    // Create a pointer to the front of fac's advisee list
    DoublyListNode<int> *curr = faculty.getFacultyAdviseeIDFront();

    // Traverse fac's advisee list and add each advisee to this faculty's advisee list
    while (curr != NULL){
        addFacultyAdviseeID(curr->m_data);
        curr = curr->next;
    }
}

//Mutators
void Faculty::setFacultyID(int facultyID){
  m_fac_id = facultyID;
}

void Faculty::setFacultyName(string facultyName){
  m_fac_name = facultyName;
}

void Faculty::setFacultyLevel(string facultyLevel){
  m_fac_level = facultyLevel;
}

void Faculty::setFacultyDepartment(string facultyDepartment){
  m_fac_department = facultyDepartment;
}

//Accessors
int Faculty::getFacultyID() const{
  return m_fac_id;
}

string Faculty::getFacultyName() const{
  return m_fac_name;
}
int Faculty::getNumFacultyAdvisees() const{
  return m_num_fac_advisee;
}

DoublyListNode<int>* Faculty::getFacultyAdviseeIDFront() const{
  return m_fac_advisee_IDs.getFront();
}

string Faculty::getFacultyLevel() const{
  return m_fac_level;
}

string Faculty::getFacultyDepartment() const{
  return m_fac_department;
}

//Add a student ID to the faculty member's list of advisees
void Faculty::addFacultyAdviseeID(int studentID){
  //Insert the new student ID at the back of the doubly linked list
  m_fac_advisee_IDs.insertBack(studentID);
  //Increment the count of advisees
  m_num_fac_advisee++;
}

//Remove a student ID from the faculty member's list of advisees
void Faculty::removeFacultyAdviseeID(int studentID)
{
  //Remove the specified student ID from the doubly linked list
  m_fac_advisee_IDs.remove(studentID);
  //Decrement the count of advisees
  m_num_fac_advisee--;
}

// Check if a faculty member has a specific student based on their ID
bool Faculty::hasStudent(int studentID){
    return m_fac_advisee_IDs.contains(studentID);
}

//Used to tell whether a faculty member has any students
bool Faculty::facHasStudent(){
  return (!m_fac_advisee_IDs.isEmpty());
}

//Overloaded operators based on ID
bool Faculty::operator<(const Faculty &fac) const {
    return (m_fac_id < fac.m_fac_id);
}

bool Faculty::operator==(const Faculty &fac) const {
    return (m_fac_id == fac.m_fac_id);
}

bool Faculty::operator>(const Faculty &fac) const {
    return (m_fac_id > fac.m_fac_id);
}

bool Faculty::operator!=(const Faculty &fac) const {
    return (m_fac_id != fac.m_fac_id);
}

//Assignment operator overload
void Faculty::operator=(const Faculty &faculty){
  //Copy values of the fields from faculty pointer to the current object
  m_fac_id = faculty.getFacultyID();
  m_fac_name = faculty.getFacultyName();
  m_fac_level = faculty.getFacultyLevel();
  m_fac_department = faculty.getFacultyDepartment();
  
  //Copy the list of advisee IDs from fac to the current object
  DoublyListNode<int> *curr = faculty.getFacultyAdviseeIDFront(); //get the front of the list from fac
  while (curr!= NULL)
  {
    addFacultyAdviseeID(curr->m_data); //add each advisee ID to the current object's list
    curr = curr->next;
  }
}

void Faculty::printFacultyInfo(){
    cout << "Faculty ID: " << m_fac_id << endl;
    cout << "Name: " << m_fac_name << endl;
    cout << "Academic Level: " << m_fac_level << endl;
    cout << "Department: " << m_fac_department << endl;
    if (!m_fac_advisee_IDs.isEmpty()){
        cout << "Student Advisee IDs: ";
        m_fac_advisee_IDs.printList();
    } else {
        cout << "This faculty member has no student advisees." << endl;
    }
}



