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

int Student::operator==(Student &temp) {
    return temp.studentID;
}

int Student::operator<(Student &temp) {
    return temp.studentID;
}

int Student::operator>(Student &temp) {
    return temp.studentID;
}