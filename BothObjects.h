#ifndef BOTHOBJECTS_H
#define BOTHOBJECTS_H

#include "Student.h"
#include "Faculty.h"

class BothObjects {
public:
    Faculty facultyMember;
    Student studentMember;
    bool member; // 0 is faculty, 1 is student
    bool command; // 0 is delete, 1 is insert

    BothObjects();
    BothObjects(Faculty faculty, bool cmnd);
    BothObjects(Student student, bool cmnd);
};

#endif