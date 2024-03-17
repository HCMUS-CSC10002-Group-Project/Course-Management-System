#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include "Date.h"
#include "../data_structures/LinkedList.h"

//TODO: uncomment date_of_birth and its getter/setter after Date is implemented

class Student : public User
{
    private:
        //student data
        string student_ID;
        string class_ID;
        LinkedList <string> course_IDs;
        string gender;
        Date date_of_birth;
        string major;
        int cohort;
    
    public:
        //view courses and scoreboard
        void viewMyCourses();
        void viewMyScoreboard();

        //setters and getters
        string getStudentID();
        string getClassID();
        void setClassID(string newClassID);
        void addCourse(string newCourseID);
        void removeCourse(string courseID);
        LinkedList <string> getCourseIDs();
        string getGender();
        void setGender(string newGender);
        Date getDateOfBirth();
        void setDateOfBirth(Date newDateOfBirth);
        string getMajor();
        void setMajor(string newMajor);
        int getCohort();
        void setCohort(int newCohort);
};

#endif STUDENT_H
