#include "Faculty.h"

Faculty::Faculty() {
    //defaults
    facultyID = 0;
    aCount = 0;
    for (int i = 0; i<10;++i) {
        adviseesID[i] = 0;
    }
    name = "Default";
    level = "Default";
    department = "Default";
}

Faculty::Faculty(int fID, int aC, int arr[10], string n, string l, string d) {
    facultyID = fID;
    aCount = aC;
    for (int i =0; i<= aCount;++i) {
        adviseesID[i] = arr[i];
    }
    name = n;
    level = l;
    department = d;
}

Faculty::~Faculty() {

}

void Faculty::arrSizePlusOne() {

}

void Faculty::printInfo() {
    cout << "FacultyID: " << facultyID <<endl;
    for (int i = 1; i <= aCount; ++i) {
            cout << "Advisee Num " << i << ": " << adviseesID[i-1] << endl;
        }
    cout << "Name: " << name << endl;
    cout << "Level: " << level <<endl;
    cout << "Department: " << department <<endl << endl;
}

void Faculty::pushToFile(ofstream &myFile) {
    if (myFile.is_open()) {
        myFile << facultyID << endl;
        myFile << aCount << endl;
        for (int i = 0; i < aCount; ++i) {
            myFile << adviseesID[i] << endl;
        }
        myFile << name << endl;
        myFile << level << endl;
        myFile << department << endl;
    }
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

bool Faculty::operator != (Faculty &other) {
    return (facultyID != other.facultyID);
}

int Faculty::getID() {
    return facultyID;
}

int Faculty::getStudentID(int index) {
    return adviseesID[index];
}

int Faculty::getCount() {
    return aCount;
}

void Faculty::setID(int x) {
    facultyID = x;
}

void Faculty::setAID(int index, int val) {  //index from 0-9 (1-10)
    adviseesID[index] = val;
}

void Faculty::setCount(int x) {
    aCount = x;
}

void Faculty::setName(string x) {
    name = x;
}

void Faculty::setLevel(string x) {
    level = x;
}  

void Faculty::setDepartment(string x) {
    department = x;
}

bool Faculty::removeAdvisee(int id) {
    int temp;
    for (int i = 0; i < aCount;++i) {
        if (adviseesID[i]==id) {
            for (int j = i; j <= aCount; ++j) {
                temp = adviseesID[j+1];
                adviseesID[i] = temp;
            }
            aCount -= 1;
            return true;
        }
    }
    return false;
}