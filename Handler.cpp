#include "Handler.h"

Handler::Handler() {
    // Gets info from the files and pushes it to the new BST
    filesExist();
}

Handler::~Handler() {
    //clean up  --- pushes state of all trees to files
    facultyTree.pushTree("facultyTable");
    studentTree.pushTree("studentTable");
}

void Handler::filesExist() {
    // check to see if we can open "facultyTable" and "studentTable"
    // only works if files exist in same directory as program
    ifstream facultyTable("facultyTable");
    ifstream studentTable("studentTable");

    if (facultyTable.is_open() && studentTable.is_open()) {     //case both files exist

        readFileFaculty(facultyTable);
        readFileStudent(studentTable);

        facultyTable.close();
        studentTable.close();
    }
    else if (facultyTable.is_open()) {                          //case only faculty file exits

        readFileFaculty(facultyTable);

        facultyTable.close();
    }
    else if (studentTable.is_open()) {                          //case only student file exists

        readFileStudent(studentTable);
        studentTable.close();
    }
}

bool Handler::readFileFaculty(ifstream &fileName) {
    string x;
    int linecount = 1;
    Faculty temp;
    while (getline(fileName,x)) {
        //Organized ID, adviseeID, Name, Level, Department
        if (linecount%5 == 1) {
            temp.setID(stoi(x));
        }
        else if (linecount%5 == 2) {
            temp.setAID(0,stoi(x));
        }
        else if (linecount%5 == 3) {
            temp.setName(x);
        }
        else if (linecount%5 == 4) {
            temp.setLevel(x);
        }
        else if (linecount%5 == 0) {
            temp.setDepartment(x);
        }
        if (linecount%5 == 0) {
            //push entire object to BST
            facultyTree.insert(temp);
        }
        linecount++;
    }
    return true;
}

bool Handler::readFileStudent(ifstream &fileName) {
    string x;
    int linecount = 1;
    Student temp;
    while (getline(fileName,x)) {
        //Organized ID, adviserID, GPA, Name, Level, Major
        if (linecount%6 == 1) {
            temp.setID(stoi(x));
        }
        else if (linecount%6 == 2) {
            temp.setAID(stoi(x));
        }
        else if (linecount%6 == 3) {
            temp.setGPA(stoi(x));
        }
        else if (linecount%6 == 4) {
            temp.setName(x);
        }
        else if (linecount%6 == 5) {
            temp.setLevel(x);
        }
        else if (linecount%6 == 0) {
            temp.setMajor(x);
        }
        if (linecount%6 == 0) {
            //push entire object to BST
            studentTree.insert(temp);
        }
        linecount++;
    }
    return true;
}

void Handler::createNewFaculty() {
    Faculty temp;

}

void Handler::createNewStudent() {
    Student temp;
    int x;
    double y;
    string z;
    cout << "Enter New Student ID: " << endl;
    cin >> x;
    temp.setID(x);
    cout << "Enter New Student's Advisor ID: " << endl;
    cin >> x;
    temp.setAID(x);
    cout << "Enter New Student GPA: " << endl;
    cin >> y;
    temp.setGPA(y);
    cout << "Enter New Student Name: " << endl;
    cin >> z;
    temp.setName(z);
    cout << "Enter New Student Grade Level: " << endl;
    cin >> z;
    temp.setLevel(z);
    cout << "Enter New Student Major: " << endl;
    cin >> z;
    temp.setMajor(z);

    insertStudent(temp);
}

void Handler::insertFaculty(Faculty x) {
    facultyTree.insert(x);
}

void Handler::insertStudent(Student x) {
    studentTree.insert(x);
}

void Handler::displayFacultyTree() {
    facultyTree.printTree();
}

void Handler::displayStudentTree() {
    studentTree.printTree();
}

void Handler::displayMenu(){
  cout << "~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~" << endl;
  cout << " 1) Print all students and their information (sorted by ascending id #)" << endl;
  cout << " 2) Print all faculty and their information (sorted by ascending id #)" << endl;
  cout << " 3) Find and display student information given the students id" << endl;
  cout << " 4) Find and display faculty information given the faculty id" << endl;
  cout << " 5) Given a student’s id, print the name and info of their faculty advisor" << endl;
  cout << " 6) Given a faculty id, print ALL the names and info of his/her advisees" << endl;
  cout << " 7) Add a new student" << endl;
  cout << " 8) Delete a student given the id" << endl;
  cout << " 9) Add a new faculty member" << endl;
  cout << " 10) Delete a faculty member given the id" << endl;
  cout << " 11) Change a student’s advisor given the student id and the new faculty id" << endl;
  cout << " 12) Remove an advisee from a faculty member given the ids" << endl;
  cout << " 13) Rollback" << endl;
  cout << " 14) Exit" << endl;
}

void Handler::displayFaculty(int id) {
    Faculty temp;
    temp.setID(id);
    facultyTree.contains(temp);
}

void Handler::displayStudent(int id) {
    Student temp;
    temp.setID(id);
    studentTree.contains(temp);
}

void Handler::deleteFaculty(int id) {
    bool result;
    Faculty temp;
    temp.setID(id);

    //rollback
    if (facultyTree.preSearch(temp)) {
        TreeNode<Faculty> *tempPTR;
        tempPTR = facultyTree.search(temp);
        BothObjects rollback(tempPTR->data, 0);
        stack.push(rollback);
    }
    //end rollback

    result =facultyTree.deleteNode(temp);
    if (result) {
        cout << "Faculty with ID " << id << " sucessfully deleted." <<endl;
    }
    else {
        cout << "Could not delete Faculty!" <<endl;
    }
}

void Handler::deleteStudent(int id) {
    bool result;
    Student temp;
    temp.setID(id);

    //rollback
    if (studentTree.preSearch(temp)) {
        TreeNode<Student> *tempPTR;
        tempPTR = studentTree.search(temp);
        BothObjects rollback(tempPTR->data, 0);
        stack.push(rollback);
    }
    //end rollback

    result = studentTree.deleteNode(temp);
    if (result) {
        cout << "Student with ID " << id << " sucessfully delted."  <<endl;
    }
    else {
        cout << "Could not delete Student!" << endl;
    }
}

void Handler::undoLastCommand() {
    if (stack.isEmpty()) {
        cout << "No commands have been issued in this instance" << endl;
        return;
    }
    BothObjects temp = stack.pop();
    if (temp.member == 0) {         //faculty
        if (temp.command == 0) {    //was deleted, now insert
            facultyTree.insert(temp.facultyMember);
        }
        else {                      //was inserted, now delete
            facultyTree.deleteNode(temp.facultyMember);
        }
    }
    else {                          //student
        if (temp.command == 0) {    //was deleted, now insert
            studentTree.insert(temp.studentMember);
        }
        else {                      //was inserted, now delete
            studentTree.deleteNode(temp.studentMember);
        }
    }
    cout << "Last Command Sucessfully Undone" << endl;
}

//void Handler::facultyStudentID(int id) {
//    Student temp;
//    if(studentTree.contains(id)) {
//        temp = studentTree.contains(id);

//        facultyTree.contains(temp->getAdvisor())->displayFaculty();
//        break;
//      }
//      else {
//          cout << "The student ID entered was not found. Please enter a valid ID." << endl;
//      }
//    }

//  }
//}


void Handler::runProgram() {
    bool runProgram = true;
    displayMenu();
    while (runProgram) {
        int x = 0;
        cout << "Enter Input 1-14: ";
        cin >> x;

        if (x == 1) {
            displayStudentTree();
        }
        else if (x == 2) {
            displayFacultyTree();
        }
        else if (x == 3) {
            int input;
            cout << "Please Enter Student ID to find: ";
            cin >> input;
            displayStudent(input);
        }
        else if (x == 4) {
            int input;
            cout << "Please Enter Faculty ID to find: ";
            cin >> input;
            displayFaculty(input);
        }
        else if (x == 5) {
          //  cout << "Please Enter Student ID: ";
          //  cin >> input;
          //  facultyStudentID();
        }
        else if (x == 6) {

        }
        else if (x == 7) {
            createNewStudent();
        }
        else if (x == 8) {
            int input;
            cout << "Please enter ID of student you want to delete: ";
            cin >> input;
            deleteStudent(input);
        }
        else if (x == 9) {
            createNewFaculty();
        }
        else if (x == 10) {
            int input;
            cout << "Please enter ID of faculty you want to delete: ";
            cin >> input;
            deleteFaculty(input);
        }
        else if (x == 11) {

        }
        else if (x == 12) {

        }
        else if (x == 13) {
            undoLastCommand();
        }
        else {
            runProgram = false;
        }
    }
}

//Case 6
cout << "Please enter Faculty ID: " << flush;
cin >> id;

if (facultyTree.cntains(id))
{
  for (int tempID : facultyTree.contains()->data.displayStudent())
  {
    if (studentTree.contains(tempID))
    {
      studentTree.contains()->displayFaculty();
    }
  }
}

//case 11
validInput = false;
while (!validInput) {
  cout << "Enter the id of the student you wish to reassign:" << endl;
  cin >> id;
  if (!studentTree.callContains(id)) {
    cout << "The student ID you entered was not found." << endl;
  }
  else {
    validInput = true;
  }
}

validInput = false;
while (!validInput) {
  cout << "Which faculty ID would you like to reassign this student too?" << endl;
  cin >> advisorID;
  if (!facultyTree.contains(advisorId)) {
    cout << "Invalid input: Faculty member not found" << endl;
  }
  else {
    validInput = true;
  }
}

if(studentTree.contains()->data.getAdvisorID()! = advisorID) {
  facultyTree.contains()->data.insertStudent(id);
  if (facultyTreeT.contains(studentTree.contains()->data.getAdvisorID()))
  {
    facultyTree.contains()->data.removeStudent(id);
  }
  studentTree.contains()->data.insertAdvisor(advisorID);
}
break;


//case 12
validInput = false;

while (!validInput) {
  cout << "Enter ID of faculty member you would like to change:" << endl;
  cin >> advisorID;
  if (!facultyTree.contains(advisorID))
  {
    cout << "Invalid input: Faculty member not found" << endl;
  }
  else
  {
    validInput = true;
  }
}
validInput = false;

while (!validInput) {
  cout << "Enter ID of the student you wish to remove:" << endl;
  cin >> id;
  if (!studentTree.contains(id)) {
    cout << "Invalid input: Student not found" << endl;
  }
  else {
    validInput = true;
  }
}
facultyTree.contains()->data.deleteStudent(id);
studentTree.contains()->data.deleteAdvisor();
break;
