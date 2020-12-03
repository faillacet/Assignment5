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

}

void Handler::displayStudent(int id) {
    Student temp;
    temp.setID(id);
    studentTree.contains(temp);
}
