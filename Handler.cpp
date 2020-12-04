#include "Handler.h"

Handler::Handler() {
    // Gets info from the files and pushes it to the new BST
    filesExist();
}

Handler::~Handler() {
    //clean up  --- pushes state of all trees to files
    facultyTree.pushTree("facultyTable");
    studentTree.pushTree("studentTable");
    cout << "Faculty and Student Trees Saved, See You Next Time!" << endl;
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
    bool reset = false;
    int linecount = 1;
    int mod = 5;
    int numA = 0;
    int counter = 1;
    Faculty temp;
    while (getline(fileName,x)) {
        //Organized ID, adviseeID, Name, Level, Department
        if (reset) {
            linecount = 1;  
            numA = 0;
            mod = 5;
            counter = 1;
            reset = false;
        }
        if (linecount%mod == 1) {
            temp.setID(stoi(x));
        }
        else if (linecount%mod == 2) {
            numA = stoi(x);
            mod += numA;
            temp.setCount(numA);
        }
        else if (linecount%mod == (2+counter)  && numA != 0) {
            temp.setAID(counter-1,stoi(x));
            if (counter < numA)
                counter++;
        }
        else if (linecount%mod == (3+counter)) {
            temp.setName(x);
        }
        else if (linecount%mod == (4+counter)) {
            temp.setLevel(x);
        }
        else if (linecount%mod == 0) {
            temp.setDepartment(x);
        }
        if (linecount%mod == 0) {
            //push entire object to BST
            facultyTree.insert(temp);
            reset = true;
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
    string y;
    int x;
    int iterator;
    cout << "Enter New Faculty ID: " << endl;
    cin >> x;
    temp.setID(x);
    cout << "Enter Number Of Advisees (can be changed later): "  <<endl;
    cin >> x;
    temp.setCount(x);
    iterator = x;
    for (int i = 0; i < iterator; ++i) {
        cout << "Enter Student ID: " << endl;
        cin >> x;
        temp.setAID(i,x);
    }
    cout << "Enter New Faculty Name (Enter as one word): " <<endl;
    cin >> y;
    temp.setName(y);
    cout << "Enter New Faculty Level (Enter as one word): " <<endl;
    cin >> y;
    temp.setLevel(y);
    cout << "Enter New Faculty Department (Enter as one word): " <<endl;
    cin >>y;
    temp.setDepartment(y);

    insertFaculty(temp);
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
    cout << "Enter New Student First Name: " << endl;
    cin >> z;
    temp.setName(z);
    cout << "Enter New Student Grade Level: " << endl;
    cin >> z;
    temp.setLevel(z);
    cout << "Enter New Student Major (Enter as one word): " << endl;
    cin >> z;
    temp.setMajor(z);

    insertStudent(temp);
}

void Handler::insertFaculty(Faculty x) {
    //rollback
    BothObjects temp(x, 1);
    stack.push(temp);
    //end rollback

    facultyTree.insert(x);
}

void Handler::insertStudent(Student x) {
    //rollback
    BothObjects temp(x, 1);
    stack.push(temp);
    //end rollback

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
        Student student = tempPTR->data;
        BothObjects rollback(student, 0);
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

void Handler::givenSIDPrintAdvisor() {
    int x;
    cout << "Please enter Student ID: " << endl;
    cin >> x;
    Student temp;
    TreeNode<Student> *student;
    Faculty faculty;
    temp.setID(x);
    if (studentTree.preSearch(temp)) {
        student = studentTree.search(temp);
        x = student->data.getAID();
        faculty.setID(x);
        if (facultyTree.preSearch(faculty)) 
            facultyTree.contains(faculty);
        else
            cout << "Advisor could not be found."  << endl;
    }
    else {
        cout << "Student could not be found." << endl;
    }
}

void Handler::givenAIDPrintStudents() {
    int x;
    cout << "Please enter Advisor ID: ";
    cin >> x;
    Faculty temp;
    TreeNode<Faculty> *faculty;
    temp.setID(x);
    if (facultyTree.preSearch(temp)) {
        faculty = facultyTree.search(temp);
        int counter = 0;
        while (faculty->data.getStudentID(counter) != 0 && counter < 10) {
            Student student;
            student.setID(faculty->data.getStudentID(counter));
            if (studentTree.preSearch(student)) {
                studentTree.contains(student);
            }
            else {
                cout << "Student with ID: " << student.getID() << " could not be found." << endl;
            }
            counter++;
        }
    }
    else {
        cout << "Faculty could not be found."  << endl;
    }
}

void Handler::changeAdvisorViaStudent() {
    int x;
    int y;
    cout << "Enter Student ID: " << endl;
    cin >> x;
    cout << "Enter New Advisor ID: " << endl;
    cin >> y;
    Student temp;
    TreeNode<Student> *ptr;
    temp.setID(x);
    if (studentTree.preSearch(temp)) {
        ptr = studentTree.search(temp);
        ptr->data.setAID(y);
    }
    else {
        cout << "Student Not Found." <<endl;
    }
}

void Handler::removeAdviseeFromFaculty() {
    int x;
    int y;
    cout << "Enter Faculty ID: " << endl;
    cin >> x;
    cout << "Enter Advisee ID to remove: " <<endl;
    cin >> y;
    Faculty temp;
    TreeNode<Faculty> *ptr;
    temp.setID(x);
    if (facultyTree.preSearch(temp)) {
        ptr = facultyTree.search(temp);
        if (ptr->data.removeAdvisee(y)) {
            cout << "Advisee With ID " << y << " Removed." << endl;
        }
        else {
            cout << "Advisee could not be removed." << endl;
        }
    }
    else {
        cout << "Faculty member does not exist." <<endl;
    }
}

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
            givenSIDPrintAdvisor();
        }
        else if (x == 6) {
            givenAIDPrintStudents();
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
            changeAdvisorViaStudent();

        }
        else if (x == 12) {
            removeAdviseeFromFaculty();
        }
        else if (x == 13) {
            undoLastCommand();
        }
        else {
            runProgram = false;
        }
    }
}