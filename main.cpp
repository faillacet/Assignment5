#include <iostream>
#include "BST.h"
#include "TreeNode.h"
#include "Handler.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

int main(int argc, char* argv[]) {
    Handler h;
    
    Student Trenton(1,2,1,"Trenton","Junior","Computer Science");       //TO keep it simple --- lets use name or ID (ID probably better)
    Student Other(3,3,3,"Other","Sophomore", "English");
    Student Ryan(2,2,2,"Ryan","Freshman", "Science");

    h.insertStudent(Ryan);
    h.insertStudent(Other);
    h.insertStudent(Trenton);
    h.displayStudentTree();

    return 0;
}