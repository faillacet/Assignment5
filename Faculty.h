#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>
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
    bool operator < (Faculty &other);
    bool operator > (Faculty &other);
    bool operator == (Faculty &other);
    int getID();
};

#endif