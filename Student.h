#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;

class Student {
private:
    int studentID;
    int advisorID;
    double GPA;
    string name;
    string level;   //freshman sophomore etc.
    string major;

public:
    Student();  //defaults
    Student(int sID, int aID, double g, string n, string l, string m);  //all inputs
    ~Student();
    int operator==(Student &temp);      //overload ==  to check for key
    int operator<(Student &temp);
    int operator>(Student &temp);
};

#endif