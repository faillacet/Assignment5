#ifndef HANDLER_H
#define HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "GenStack.h"
#include "BothObjects.h"
using namespace std;

class Handler {
private:
    BST<Faculty> facultyTree;
    BST<Student> studentTree;
    GenStack<BothObjects> stack;
public:
    Handler();
    ~Handler();
    void filesExist();    //when program starts search for two stored files (BST) to see if they exist
    bool readFileFaculty(ifstream &fileName);      //if the files exist, open them and push info to BST
    bool readFileStudent(ifstream &fileName);       //UPDATE LATER TO ALLOW FOR MULTIPLE ADVISEE IDS
    void createNewStudent();                //menu fucntion to add a new student
    void createNewFaculty();                //menu fucntion to add a new faculty
    void insertStudent(Student x);       //push new student to tree
    void insertFaculty(Faculty x);       //push new faculty to tree
    void displayFacultyTree();           //print Faculty tree
    void displayStudentTree();           //print Student Tree
    void displayMenu();                  //menu for user input
    void displayFaculty(int id);         //display faculty info given id
    void displayStudent(int id);         //display studnt info given id
    void deleteFaculty(int id);          //delete faculty given id
    void deleteStudent(int id);          //detlete student given id
    void undoLastCommand();              //implementation of rollback
    void givenSIDPrintAdvisor();         //given student ID print the advisor
    void givenAIDPrintStudents();        //given advisor ID print the students
    void changeAdvisorViaStudent();      //given student ID change the advisor
    void removeAdviseeFromFaculty();     //given advisor ID and adviseee ID remove advisee

    // menu oriented functions
    void runProgram();
};

#endif