#ifndef FACULTY_H
#define FACULTY_h

#include <iostream>
using namespace std;

class Faculty {
private:
    int facultyID;
    int adviseesID; //implement as list later (linked list?)
    string name;
    string level;
    string department;

    int getID();
    void setID(int id);
    string printInfo();

public:
    Faculty();
    ~Faculty();
};

#endif
