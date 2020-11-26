#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#ifndef HANDLER_H
#define HANDLER_H

class RunProgram{
public:
  void createTrees();
  void printMenu();
  void menuSelection(int menuSel);
  void printAllStudents();
  void printAllFaculty();
  void printAdvisor();
  void createStudentTableFile();
  void createFacultyTableFile();
  void facultyStudentID();

};
#endif
