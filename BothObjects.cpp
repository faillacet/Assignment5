#include "BothObjects.h"

BothObjects::BothObjects() {

}

BothObjects::BothObjects(Faculty faculty, bool cmnd) {
    //student is ignored
    facultyMember = faculty;
    member = 0;    
    command = cmnd;
}

BothObjects::BothObjects(Student student, bool cmnd) {
    //faculty is ignored
    studentMember = student;
    member = 1;
    command = cmnd;
}