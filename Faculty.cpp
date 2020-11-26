#include "Faculty.h"

Faculty::Faculty() {
    //defaults
    facultyID = 0;
    adviseesID = 0;
    name = "Default";
    level = "Default";
    department = "Default";
}

Faculty::Faculty(int fID, int aID, string n, string l, string d) {
    facultyID = fID;
    adviseesID = aID;
    name = n;
    level = l;
    department = d;
}

Faculty::~Faculty() {
    //clean up
}

void Faculty::printInfo() {
    cout << "FacultyID: " << facultyID <<endl;
    cout << "Advisse'sID: " << adviseesID << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level <<endl;
    cout << "Department: " << department <<endl << endl;
}

bool Faculty::operator < (Faculty &other) {
    return (facultyID < other.facultyID);
}

bool Faculty::operator > (Faculty &other) {
    return (facultyID < other.facultyID);
}

bool Faculty::operator == (Faculty &other) {
    return (facultyID < other.facultyID);
}

int Faculty::getID() {
    return facultyID;
}