#ifndef CLASS_H
#define CLASS_H
#include "student.h"
#include "../data_structures/LinkedList.h"
class Class
{
    private: 
        string class_ID;
        string name;
        LinkedList<Student> students;
    public: 
        //getters
        string getClassID();
        string getName();
        LinkedList<Student> getListOfStudents();
        //setters
        void setName(string name);
        bool addStudent(Student student);
        bool removeStudent(Student student);
};
#endif