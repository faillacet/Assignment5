#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <fstream>
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
    void printInfo();
    void pushToFile(ofstream &myFile);
    bool operator < (Student &other);
    bool operator > (Student &other);
    bool operator == (Student &other);
    bool operator != (Student &other);
    int getID();
    int getAID();
    void setID(int x);
    void setAID(int x);
    void setGPA(double x);
    void setName(string x);
    void setLevel(string x);
    void setMajor(string x);
};

#endif