#include "Student.h"

Student::Student() {
    //defaults
    studentID = 0;
    advisorID = 0;
    GPA = 0;
    name = "Default";
    level = "Default";
    major = "Default";
}

Student::Student(int sID, int aID, double g, string n, string l, string m) {
    studentID = sID;
    advisorID = aID;
    GPA = g;
    name = n;
    level = l;
    major = m;
}

Student::~Student() {

}

void Student::printInfo() {
    cout << "Student ID: " << studentID << endl;
    cout << "Advisor ID: " << advisorID << endl;
    cout << "Name: " << name << endl;
    cout << "GPA: " << GPA << endl;
    cout << "Grade Level: " << level <<endl;
    cout << "Major: " << major << endl << endl;
}

void Student::pushToFile(ofstream &myFile) {
    if (myFile.is_open()) {
        myFile << studentID << endl;
        myFile << advisorID << endl;
        myFile << GPA << endl;
        myFile << name << endl;
        myFile << level << endl;
        myFile << major << endl;
    }
}

bool Student::operator < (Student &other) {
    return (studentID < other.studentID);
}

bool Student::operator > (Student &other) {
    return (studentID > other.studentID);
}

bool Student::operator == (Student &other) {
    return (studentID == other.studentID);
}

bool Student::operator != (Student &other) {
    return (studentID != other.studentID);
}

int Student::getID(){
  return studentID;
}

int Student::getAID() {
    return advisorID;
}

void Student::setID(int x) {
    studentID = x;
}

void Student::setAID(int x) {
    advisorID = x;
}

void Student::setGPA(double x) {
    GPA = x;
}

void Student::setName(string x) {
    name = x;
}

void Student::setLevel(string x) {
    level = x;
}

void Student::setMajor(string x) {
    major = x;
}
