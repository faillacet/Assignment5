#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Faculty {
private:
    int facultyID;
    int adviseesID[10]; //only up to 10 for these purposed, could expand
    int arrSize;
    string name;
    string level;
    string department;

public:
    Faculty();
    Faculty(int fID, int aID, string n, string l, string d);  //all inputs
    ~Faculty();
    void arrSizePlusOne();
    void printInfo();
    void pushToFile(ofstream &myFile);
    bool operator < (Faculty &other);
    bool operator > (Faculty &other);
    bool operator == (Faculty &other);
    bool operator != (Faculty &other);
    int getID();
    int getStudentID(int index);
    int getSize();
    void setID(int x);
    void setAID(int index, int val);
    void setName(string x);
    void setLevel(string x);
    void setDepartment(string x);
};

#endif