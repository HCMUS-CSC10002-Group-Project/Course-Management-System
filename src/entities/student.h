#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include "date.h"
#include "../data_structures/LinkedList.h"

class Student : public User
{
private:
    // student data
    string student_ID;
    string class_ID;
    LinkedList<string> course_IDs;
    string gender;
    Date date_of_birth;
    string major;
    string cohort;
    string social_ID;

public:
    // constructor
    Student(string fullName, string department, string email, string username, string password, string classID, string gender, Date dateOfBirth, string major, string cohort, string socialID);
    Student(string ID, string fullName, string department, string email, string username, string password, string studentID, string classID, LinkedList<string> courseIDs, string gender, Date dateOfBirth, string major, string cohort, string socialID);
    // view courses and scoreboard
    void viewMyCourses();
    void viewMyScoreboard();

    // setters and getters
    string getStudentID();
    string getClassID();
    bool setClassID(string newClassID);
    bool addCourse(string newCourseID);
    bool removeCourse(string courseID);
    LinkedList<string> getCourseIDs();
    string getGender();
    bool setGender(string newGender);
    Date getDateOfBirth();
    bool setDateOfBirth(Date newDateOfBirth);
    string getMajor();
    bool setMajor(string newMajor);
    string getCohort();
    bool setCohort(string newCohort);
    string getSocialID();
    bool setSocialID(string newSocialID);

    // serialization
    string serialize();
    static Student deserialize(const string &serialized);
    string getHeader();
};

#endif // STUDENT_H
