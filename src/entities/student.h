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
        int social_ID;
    
    public:
        //constructor
        Student(string classID, string gender, Date dateOfBirth, string major, int cohort, int socialID);

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
        int getSocialID();
        bool setSocialID(int newSocialID);
};

#endif //STUDENT_H
