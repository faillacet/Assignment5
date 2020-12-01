#include "Student.h"
#include "Handler.h"
#include "Faculty.h"
#include <iostream>
#include <fstream>

ofstream file_;
int studID = 2;
int facID = 1;
int searchID;
BST<Student> masterStudent;
BST<Faculty> masterFaculty;
Faculty f1();



void RunProgram::createTrees(){
  //test
  Student s1();
  Student s2();
  masterStudent.insert(s1);
  masterStudent.insert(s2);
  masterFaculty.insert(f1);
}

void RunProgram::printMenu(){
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

void RunProgram::menuSelection(int menuSel){
  Student newStudent;
  Faculty newFac;
  switch(menuSel){
    case 1: //print all students
      printAllStudents();
      break;
    case 2: //print all faculty
      printAllFaculty();
      break;
    case 3: //print a student's info
      cout << "Enter the Student ID: " << endl;
      cin >> searchID;
      masterStudent.contains(searchID);
      break;
    case 4: //print a faculty's info
      cout << "Enter the Faculty ID: " << endl;
      cin >> searchID;
      masterFaculty.contains(searchID);
      break;
    case 5: //print a faculty's info from student id
      cout << "Enter the Student ID: " << endl;
      break;
    case 6: //print all advisee's info for a faculty
      cout << "Enter the Faculty ID: " << endl;
      break;
    case 7: //add student
      studID++;
      newStudent.setID(studentID);
      cout << "Enter Student Name: " << endl;
      cin.ignore(); //https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus
      getline(cin,newStudent.name);
      cout << "Enter Student Level: " << endl;
      cin >> newStudent.level;
      cout << "Enter Student Major: " << endl;
      cin.ignore();
      getline(cin,newStudent.major);
      cout << "Enter Student GPA: " << endl;
      cin >> newStudent.gpa;
      masterStudent.insert(newStudent);
      break;
    case 8: //delete student
      cout << "Enter the Student ID: " << endl;

      break;
    case 9: //add faculty
      facID++;
      newFac.setID(facultyID);
      cout << "Enter Faculty Name: " << endl;
      cin.ignore();
      getline(cin,newFac.name);
      cout << "Enter Faculty Level: " << endl;
      cin.ignore();
      getline(cin,newFac.level);
      cout << "Enter Faculty Department: " << endl;
      cin.ignore();
      getline(cin,newFac.department);
      masterFaculty.insert(newFac);
      break;
    case 10: //delete faculty
      cout << "Enter the Faculty ID: " << endl;
      break;
    case 11: //change student's advisor
      cout << "Enter the Student ID: " << endl;
      cout << "Enter the new Faculty ID: " << endl;
      break;
    case 12: //remove student from faculty's advisee  list
      cout << "Enter the Student ID: " << endl;
      cout << "Enter the new Faculty ID: " << endl;
      break;
    case 13: //Rollback
      break;
    case 14:
      createStudentTableFile();
      createFacultyTableFile();
      break;
  }
}

void RunProgram::printAllStudents(){
  if(masterStudent.isEmpty())
    cout << "No Students exist at this time." << endl;
  else{
    //write function to print out entire tree
  }
}

void RunProgram::printAllFaculty(){
  if(masterFaculty.isEmpty())
    cout << "No Faculty exist at this time." << endl;
  else{
    //write function to print out entire tree
  }
}

void RunProgram::createStudentTableFile(){
  if(masterStudent.isEmpty())
    cout << "No Students exist at this time." << endl;
  else{
    //file open
  }
}

void RunProgram::createFacultyTableFile(){
  if(masterFaculty.isEmpty())
    cout << "No Students exist at this time." << endl;
  else{
    //file open
  }
}
