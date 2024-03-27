#ifndef CLASS_H
#define CLASS_H
#include "student.h"
#include "../data_structures/LinkedList.h"
class Class
{
private:
    string class_ID;
    string name;
    LinkedList<string> student_IDs;

public:
    // constructor
    Class(string name, LinkedList<string> student_IDs);
    Class(string class_ID, string name, LinkedList<string> student_IDs);
    // getters
    string getClassID();
    string getName();
    LinkedList<string> getListOfStudentIDs();
    // setters
    bool setName(string name);
    bool addStudent(string student_ID);
    bool removeStudent(string student_ID);
    // serialization
    string serialize();
    static Class deserialize(const string &serialized);
    static string getHeader();
};
#endif