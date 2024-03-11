#include "FacultyDatabase.h"

using namespace std;

class Menu{
  public:
    Menu();
    ~Menu();
    void start();
  private:
    FacultyDatabase m_database;
    string m_choice;
    int m_student_id;
    int m_faculty_id;
    int m_database_choice;
};