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

int Student::getID(){
  return sID;
}

void Student::setID(int id){
  this->sID = sID;
}

string Student::printInfo(){
  return "| ID: " + to_string(sID) + " | Name: " + n + " | Level: " + l + " | Major: " + m + " | GPA: " + to_string(g) + " | Advisor ID: " + to_string(aID) + " |";
}
