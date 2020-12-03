#include <iostream>
#include "BST.h"
#include "TreeNode.h"
#include "Handler.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

int main(int argc, char* argv[]) {
    Handler h;
    h.displayStudentTree();
    h.displayStudent(1);    // searching for one tht doesnt exist = segmentation fault

    return 0;
}