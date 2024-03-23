#ifndef CLASS_MANAGEMENT_SERVICE_H
#define CLASS_MANAGEMENT_SERVICE_H

#include "../entities/class.h"
#include "../data_structures/LinkedList.h"

class ClassManagementService
{
    public:
    bool createClass(string className);
    bool addStudentToClass(string classID, string studentID);
    bool removeStudentFromClass(string classID, string studentID);
    LinkedList<Class> viewClasses();
    LinkedList<Student> viewStudentsInClass(string classID);
};

#endif //CLASS_MANAGEMENT_SERVICE_H
