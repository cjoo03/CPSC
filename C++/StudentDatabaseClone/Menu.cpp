#include "Menu.h"

using namespace std;

Menu::Menu(){
  m_choice = "Y";
  m_database_choice = 0;
  m_student_id = 0;
  m_faculty_id = 0;
}

Menu::~Menu(){
}

void Menu::start() {
  while (m_choice == "Y"){
    cout << "Here are your choices for action." << endl;
    cout << "1. Print all students and their information, sorted by ascending ID number." << endl;  //
    cout << "2. Print all faculty and their information, sorted by ascending ID number." << endl; //
    cout << "3. Find and display a student's information given the ID number." << endl; //
    cout << "4. Find and display a faculty member's information given the ID number." << endl; //
    cout << "5. Add a new student." << endl;
    cout << "6. Delete a student given the ID number." << endl;
    cout << "7. Add a new faculty member." << endl;
    cout << "8. Delete a faculty member given the ID number." << endl;
    cout << "9. Change a student’s advisor given the student ID number and the new faculty ID number." << endl; //changes student tree
    cout << "10. Remove an advisee from a faculty member given the ID number." << endl; //changes faculty tree AND student tree (must change advisee as well)
    cout << "11. Exit" << endl;
    cout << "Please select a number: ";


     // Get the user's input for the menu option they want to select
    cin >> m_database_choice;

    // Based on the user's selected option, perform the appropriate action
    switch (m_database_choice){
      case 1:
        cout << "\n";
        m_database.StudentTreePrint();
        break;
      case 2:
        cout << "\n";
        m_database.FacultyTreePrint();
        break;
      case 3:
        cout << "\n";
        cout << "Please enter the ID number of the student that you are looking for: ";
        cin >> m_student_id;
        m_database.StudentPrint(m_student_id);
        break;
      case 4:
        cout << "\n";
        cout << "Please enter the ID number of the faculty member that you are looking for: ";
        cin >> m_faculty_id;
        m_database.FacultyPrint(m_faculty_id);
        break;
      case 5:
        cout << "\n";
        cout << "Please enter the ID number of the student that you want to add: ";
        cin >> m_student_id;
        m_database.AddStudent(m_student_id);
        break;
      case 6:
        cout << "\n";
        cout << "Please enter the ID number of the student that you want to delete: ";
        cin >> m_student_id;
        m_database.DeleteStudent(m_student_id);
        break;
      case 7:
        cout << "\n";
        cout << "Please enter the ID number of the faculty member that you want to add: ";
        cin >> m_faculty_id;
        m_database.AddFaculty(m_faculty_id);
        break;
      case 8:
        cout << "\n";
        cout << "Please enter the ID number of the faculty member that you want to delete: ";
        cin >> m_faculty_id;
        m_database.DeleteFaculty(m_faculty_id);
        break;
      case 9:
        cout << "\n";
        cout << "Please enter the ID number of the student whose advisor you want to change: ";
        cin >> m_student_id;
        m_database.ChangeAdvisor(m_student_id);
      case 10:
        cout << "\n";
        cout << "Please enter the ID number of the faculty member that you want to change an advisee for: ";
        cin >> m_faculty_id;
        m_database.RemoveAdvisee(m_faculty_id);
      case 11:
        m_choice = "N";
        cout << "\n";
        cout << "Exiting program.";
    }
  }
}