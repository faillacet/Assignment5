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
