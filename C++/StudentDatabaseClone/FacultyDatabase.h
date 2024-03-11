#include "BST.h"
#include "Faculty.h"
#include "Student.h"

using namespace std;

class FacultyDatabase{
  public:
    FacultyDatabase();
    ~FacultyDatabase();
    void AddStudent(int studentID); 
    void DeleteStudent(int studentID); 
    void StudentPrint(int studentID); 
    void StudentTreePrint(); 
    void FacultyTreePrint(); 
    void FacultyPrint(int facultyID); 
    void AddFaculty(int facultyID); 
    void DeleteFaculty(int facultyID); 
    void ChangeAdvisor(int studentID); 
    void RemoveAdvisee(int facultyID); 
    void RecursiveStudentPrint(TreeNode<Student>* node);
    void RecursiveFacultyPrint(TreeNode<Faculty>* node);
    
  private:
    BST<Faculty> m_faculty_tree; 
    BST<Student> m_student_tree; 
    DoublyList<int> m_student_IDs; 
    DoublyList<int> m_faculty_IDs; 
    void InsertStudent(int studentID);
    void RemoveStudent(int studentID);
    void InsertFaculty(int facultyID);
    void RemoveFaculty(int facultyID);
};