#include "Handler.h"

Handler::Handler() {
    // 

}

Handler::~Handler() {
    //clean up 
}

void Handler::filesExist() {
    // check to see if we can open "facultyTable" and "studentTable"
    // only works if files exist in same directory as program
    ifstream facultyTable("facultyTable");
    ifstream studentTable("studentTable");
	
    if (facultyTable.is_open() && studentTable.is_open()) {     //case both files exist

        openFile(facultyTable);
        openFile(studentTable);

        facultyTable.close();
        studentTable.close();
    }
    else if (facultyTable.is_open()) {                          //case only faculty file exits

        openFile(facultyTable);

        facultyTable.close();
    }
    else if (studentTable.is_open()) {                          //case only student file exists

        openFile(studentTable);
        studentTable.close();
    }
}

bool Handler::openFile(ifstream &fileName) {
    if (fileName.is_open()) {
        //code to push all the info to a BST


        return true;
    }
    else {
        return false;
    }
}