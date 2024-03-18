#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include "date.h"
#include "../data_structures/LinkedList.h"

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
        bool setClassID(string newClassID);
        bool addCourse(string newCourseID);
        bool removeCourse(string courseID);
        LinkedList <string> getCourseIDs();
        string getGender();
        bool setGender(string newGender);
        Date getDateOfBirth();
        bool setDateOfBirth(Date newDateOfBirth);
        string getMajor();
        bool setMajor(string newMajor);
        int getCohort();
        bool setCohort(int newCohort);
};

#endif STUDENT_H
