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
        void setClassID(string newClassID);
        void setName(string name);
        void setListOfStudent(LinkedList<Student> students);
};
#endif