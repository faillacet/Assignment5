#ifndef HANDLER_H
#define HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "Faculty.h"
#include "BST.h"
using namespace std;

class Handler {
private:
    BST<Faculty> facultyTree;
    BST<Student> studentTree;
public:
    Handler();
    ~Handler();
    void filesExist();    //when program starts search for two stored files (BST) to see if they exist
    bool readFileFaculty(ifstream &fileName);      //if the files exist, open them and push info to BST
    bool readFileStudent(ifstream &fileName);       //UPDATE LATER TO ALLOW FOR MULTIPLE ADVISEE IDS
    void insertStudent(Student x);       //push new student to tree
    void insertFaculty(Faculty x);       //push new faculty to tree
    void displayFacultyTree();           //print Faculty tree
    void displayStudentTree();           //print Student Tree
    void displayMenu();                  //menu for user input
    void displayFaculty(int id);
    void displayStudent(int id);
};

#endif