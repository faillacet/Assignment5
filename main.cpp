#include <iostream>
#include "BST.h"
#include "TreeNode.h"
#include "Handler.h"
#include "Student.h"
#include "Faculty.h"
using namespace std;

int main(int argc, char* argv[]) {
    Handler h;
    
    Student temp(5, 5,3.0,"Dope","Freshman", "Art");
    //h.insertStudent(temp);
    h.deleteStudent(5);
    h.displayStudent(5);


    h.displayStudentTree();
    return 0;
}