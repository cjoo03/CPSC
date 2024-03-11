#include "FacultyDatabase.h"

using namespace std;

FacultyDatabase::FacultyDatabase(){
}

FacultyDatabase::~FacultyDatabase(){
}

void FacultyDatabase::AddStudent(int studentID){
  cin.ignore();
  string studentName;
  string academicLevel; 
  string studentMajor;
  double studentGPA;
  int facultyID;
  
  //Get student info
  cout << "Enter the name of the student that you want to add: ";
  getline(cin, studentName);
  
  cout << "Enter the academic level of the student that you want to add: ";
  getline(cin, academicLevel);
  
  cout << "Enter the major of the student that you want to add: ";
  getline(cin, studentMajor);
  
  cout << "Enter the GPA of the student that you want to add: ";
  cin >> studentGPA;
  
  cout << "Enter the ID of the faculty advisor of the student that you want to add: ";
  cin >> facultyID;

  //Check if student already exists
  Student student(studentID, studentName, academicLevel, studentMajor, studentGPA, facultyID);
  if (m_student_tree.contains(student)) {
    cout << "\n";
    cout << "There is already a student in our database with that ID." << endl;
    cout << "\n";
    return;
  }

  //Check if advisor exists
  Faculty fac(facultyID, "", "", "");
  if (!m_faculty_tree.contains(fac)) {
    cout << "\n";
    cout << "This faculty member is not in the database." << endl;
    cout << "\n";
    return;
  }
  
  // Add student and update advisor's advisee list
  m_faculty_tree.getNode(fac)->key.addFacultyAdviseeID(studentID);
  m_student_tree.insert(student);
  InsertStudent(studentID);
  
  cout << "\n";
  cout << "Your student has been added to our database." << endl;
  cout << "\n";
}

void FacultyDatabase::RemoveStudent(int studentID){
  m_student_IDs.remove(studentID);
}

void FacultyDatabase::DeleteStudent(int studentID) {
  // Check if there are any students in the tree
  if (m_student_tree.isEmpty()) {
    cout << "\nThere are no students in our database.\n\n";
    return;
  }

  // Try to find the student in the tree
  Student s(studentID, "", "", "", 1.00, 0);
  TreeNode<Student>* studentNode = m_student_tree.getNode(s);

  if (!studentNode) {
    cout << "\nThis student is not in our database.\n\n";
    return;
  }

  // Get the faculty advisor of the student
  int facultyID = studentNode->key.getStudentAdvisorID();
  Faculty f(facultyID, "", "", "");

  // Check if the faculty advisor is in the tree
  if (m_faculty_tree.isEmpty()) {
    cout << "\nThere are no faculty members in our database.\n\n";
    return;
  }

  TreeNode<Faculty>* facultyNode = m_faculty_tree.getNode(f);
  if (!facultyNode) {
    cout << "\nThis faculty member is not in our database.\n\n";
    return;
  }

  // Remove the student from the faculty's advisee list
  facultyNode->key.removeFacultyAdviseeID(studentID);

  // Remove the student from the student tree and the list
  m_student_tree.deleteNode(s);
  RemoveStudent(studentID);

  cout << "\nThe student has been deleted from our database.\n\n";
}


void FacultyDatabase::InsertFaculty(int facultyID){
  m_faculty_IDs.insertBack(facultyID);
}

void FacultyDatabase::InsertStudent(int studentID){
  m_student_IDs.insertBack(studentID);
}

void FacultyDatabase::AddFaculty(int facultyID) {
  cin.ignore();

  // Get faculty information
  cout << "Enter the name of the faculty member that you want to add: ";
  string facultyName;
  getline(cin, facultyName);

  cout << "Enter the academic level of the faculty member that you want to add: ";
  string facultyLevel;
  getline(cin, facultyLevel);

  cout << "Enter the name of the department of the faculty member that you want to add: ";
  string facultyDepartment;
  getline(cin, facultyDepartment);

  // Check if facultyID is already in the tree
  if (m_faculty_tree.contains(Faculty(facultyID, "", "", ""))) {
    // Already in tree - don't add
    cout << "\n";
    cout << "There is already a faculty member in our database with that ID." << endl;
    cout << "\n";
    return;
  }

  // Add the new faculty member to the tree
  m_faculty_tree.insert(Faculty(facultyID, facultyName, facultyLevel, facultyDepartment));
  InsertFaculty(facultyID);

  cout << "\n";
  cout << "The faculty member has been added to our database." << endl;
  cout << "\n";
}


void FacultyDatabase::RemoveFaculty(int facultyID){
  m_faculty_IDs.remove(facultyID);
}

void FacultyDatabase::DeleteFaculty(int facultyID){
  Faculty f(facultyID, "", "", "");
    // Check if faculty exists
    if (m_faculty_tree.isEmpty()) {
        cout << "\nThere are no faculty in our database.\n\n";
        return;
    }

    if (!m_faculty_tree.contains(f)) {
        cout << "\nThis faculty member is not in our database.\n\n";
        return;
    }

    // Find a temp faculty member to reassign students to
    DoublyListNode<int>* tempID = m_faculty_IDs.getFront();
    while (tempID->m_data == facultyID) {
        tempID = tempID->next;
    }

    Faculty temp(tempID->m_data, "", "", "");

    // Reassign students to a substitute faculty member
    DoublyListNode<int>* curr = m_faculty_tree.getNode(f)->key.getFacultyAdviseeIDFront();
    while (curr != nullptr) {
        Student s(curr->m_data, "", "", "", 1.00, 0);

        if (!m_student_tree.contains(s)) {
            std::cout << "The advisee of the faculty advisor is not in our database.n";
        } else {
            m_student_tree.getNode(s)->key.setStudentAdvisorID(tempID->m_data);
            m_faculty_tree.getNode(temp)->key.addFacultyAdviseeID(curr->m_data);
        }

        curr = curr->next;
    }
    // Remove faculty from the faculty 
    RemoveFaculty(facultyID);

    // Print a message indicating that the faculty member has been deleted and all students have been reassigned
    cout << m_faculty_tree.getNode(f)->key.getFacultyLevel() << " " << m_faculty_tree.getNode(f)->key.getFacultyName() << " with ID " << m_faculty_tree.getNode(f)->key.getFacultyID() << " has been removed!\n";

    if (m_faculty_tree.getSize() == 1 && m_faculty_tree.getRoot()->key == f) {
        // If the deleted faculty member was the only one in the tree, replace them with a substitute
        cout << "It looks like the faculty member that you want to remove is the last faculty member in our database.\n";
        }
    }

void FacultyDatabase::RemoveAdvisee(int facultyID){
  // Create a Faculty object with the given ID
  Faculty faculty(facultyID, "", "", "");

  // Check if the faculty member exists in the faculty tree
  if (!m_faculty_tree.contains(faculty)){
    // Faculty member does not exist, so inform the user and return
    cout << "Faculty member not found in database. Unable to remove advisee." << endl;
    return;
  }

  // Prompt the user for the ID of the student to be removed
  int studentID;
  cout << "Please provide the ID of the student to remove from this faculty member: ";
  cin >> studentID;

  // Check if the faculty member has any advisees
  if (!m_faculty_tree.getNode(faculty)->key.facHasStudent()){
    // Faculty member has no advisees, so inform the user and return
    cout << "Faculty member has no advisees. Unable to remove student." << endl;
    return;
  }

  // Check if the faculty member advises the given student
  if (!m_faculty_tree.getNode(faculty)->key.hasStudent(studentID)){
    // Faculty member does not advise the student, so inform the user and return
    cout << "Faculty member does not advise the student. Unable to remove student." << endl;
    return;
  }

  // Create a Student object with the given ID
  Student student(studentID, "", "", "", 1.00, 0);

  // Check if the student exists in the student tree
  if (!m_student_tree.contains(student)){
    // Student not found, so inform the user and return
    cout << "Student not found in database. Unable to remove student." << endl;
    return;
  }

  // Change the advisor for the given student to NULL
  ChangeAdvisor(studentID);
}


void FacultyDatabase::ChangeAdvisor(int studentID){
    Student student(studentID, "", "", "", 1.00, 0);  
    if (m_student_tree.isEmpty()){
        std::cout << "\nThere are no students in our database.\n\n";
        return;
    }

    if (!m_student_tree.contains(student)){
        std::cout << "\nThis student is not in our database.\n\n";
        return;
    }
    
    Faculty oldAdvisor(m_student_tree.getNode(student)->key.getStudentAdvisorID(), "", "", "");
    
    if (!m_faculty_tree.contains(oldAdvisor)){
        std::cout << "The previous advisor is not in our database.\n";
        return;
    }

    std::cout << "Please provide the ID of the new advisor for the student: ";
    
    int facultyID;
    std::cin >> facultyID;

    Faculty newAdvisor(facultyID, "", "", "");

    if (!m_faculty_tree.contains(newAdvisor)){
        std::cout << "\nIt looks like you want to give a student an advisor that is not in our database." << std::endl;
        std::cout << "Please add this faculty member to the database before giving this faculty member an advisee.\n\n";
        return;
    }
    
    // Update the student's advisor.
    m_student_tree.getNode(student)->key.setStudentAdvisorID(facultyID);
    
    // Remove the student from the old faculty member's advisee list.
    m_faculty_tree.getNode(oldAdvisor)->key.removeFacultyAdviseeID(studentID);
    
    // Insert the student into the new faculty member's advisee list.
    m_faculty_tree.getNode(newAdvisor)->key.addFacultyAdviseeID(studentID);
}

void FacultyDatabase::RecursiveStudentPrint(TreeNode<Student>* node) {
  if (node != nullptr) {
    RecursiveStudentPrint(node->left);
    node->key.printStudentInfo();
    cout << "\n";
    RecursiveStudentPrint(node->right);
  }
}

void FacultyDatabase::RecursiveFacultyPrint(TreeNode<Faculty>* node) {
  if (node != nullptr) {
    RecursiveFacultyPrint(node->left);
    node->key.printFacultyInfo();
    cout << "\n";
    RecursiveFacultyPrint(node->right);
  }
}

void FacultyDatabase::StudentTreePrint() {
  TreeNode<Student>* root = m_student_tree.getRoot();
  if(!root) {
    cout << "\nThere are no students in our database.\n";
    return;
  }
  cout << "\n";
  RecursiveStudentPrint(root);
}


void FacultyDatabase::FacultyTreePrint() {
  if (m_faculty_tree.isEmpty()) {
    cout << "\n";
    cout << "There are no faculty in our database." << endl;
  } else {
    cout << "\n";
    RecursiveFacultyPrint(m_faculty_tree.getRoot());
  }
  cout << "\n";
}


void FacultyDatabase::StudentPrint(int studentID) {
  Student s(studentID, "", "", "", 1.00, 0);
  TreeNode<Student>* node = m_student_tree.getNode(s);
  if (node == NULL) {
    cout << "\n";
    cout << "This student is not in our database." << endl;
    cout << "\n";
  } else {
    cout << "\n";
    node->key.printStudentInfo();
    cout << "\n";
  }
}

void FacultyDatabase::FacultyPrint(int facultyID){
  Faculty f(facultyID, "", "", "");
  TreeNode<Faculty>* facultyNode = m_faculty_tree.getNode(f);
  if (facultyNode == nullptr){
    cout << "\n";
    cout << "Faculty member with ID: " << facultyID << " is not in our database." << endl;
    cout << "\n";
  } else {
    cout << "\n";
    facultyNode->key.printFacultyInfo();
    cout << "\n";
  }
}
