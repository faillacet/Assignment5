#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Faculty {
private:
    int facultyID;
    int adviseesID; //implement as list later (linked list?)
    string name;
    string level;
    string department;

public:
    Faculty();
    Faculty(int fID, int aID, string n, string l, string d);  //all inputs
    ~Faculty();
    void printInfo();
    void pushToFile(ofstream &myFile);
    bool operator < (Faculty &other);
    bool operator > (Faculty &other);
    bool operator == (Faculty &other);
    int getID();
    void setID(int x);
    void setAID(int x);
    void setName(string x);
    void setLevel(string x);
    void setDepartment(string x);
};

#endif