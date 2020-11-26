#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int advisorID;
    double GPA;
    string name;
    string level;   //freshman sophomore etc.
    string major;

public:
    int studentID;
    Student();  //defaults
    Student(int sID, int aID, double g, string n, string l, string m);  //all inputs
    ~Student();
    void printInfo();
    bool operator < (Student &other);
    bool operator > (Student &other);
    bool operator == (Student &other);
    int getID();
};

#endif