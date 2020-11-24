#include <iostream>
#include "BST.h"
#include "TreeNode.h"
#include "Handler.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

int main(int argc, char* argv[]) {
    BST<Student> test;
    if (test.isEmpty()) {
        cout << "yes" << endl;
    }

    Student Trenton(1,1,1,"Trenton","Junior","Computer Science");       //TO keep it simple --- lets use name or ID (ID probably better)
    test.insert(Trenton);


    return 0;
}