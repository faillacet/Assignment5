#ifndef HANDLER_H
#define HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Handler {
private:

public:
    Handler();
    ~Handler();
    void filesExist();    //when program starts search for two stored files (BST) to see if they exist
    bool openFile(ifstream &fileName);      //if the files exist, open them and push info to BST
};

#endif