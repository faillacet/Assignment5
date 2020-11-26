#include "Student.h"

Student::Student() {

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

bool Student::operator < (Student &other) {
    return (studentID < other.studentID);
}

bool Student::operator > (Student &other) {
    return (studentID > other.studentID);
}

bool Student::operator == (Student &other) {
    return (studentID == other.studentID);
}

int Student::getID(){
  return studentID;
}
