#include <iostream>
#include "BST.h"
#include "TreeNode.h"
#include "Handler.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

int main(int argc, char* argv[]) {
    BST<Student> test;

    Student Trenton(1,1,1,"Trenton","Junior","Computer Science");       //TO keep it simple --- lets use name or ID (ID probably better)
    Student Other(3,3,3,"Other","Sophomore", "English");
    Student Ryan(2,2,2,"Ryan","Freshman", "Science");
    test.insert(Trenton);
    test.insert(Other);
    test.insert(Ryan);

    test.printTree();



    return 0;
}