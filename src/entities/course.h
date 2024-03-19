#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "student.h"
#include "scoreboard.h"
#include "../data_structures/LinkedList.h"

using std::string;

//TODO: add getters/setters

class Course
{
    //course data
    private:
        string course_ID;
        string semester_ID;
        string class_ID;
        LinkedList <string> teacher_names;
        int number_of_credits;
        int capacity;
        string day_of_week;
        string session_time;
        LinkedList <Student> enrolled_students;
        //Scoreboard score_board;

    public:
        //constructor
        Course(string semesterID, string classID, int numberOfCredits, int capacity, string dayOfWeek, string sessionTime);

        //getters and setters
        string getCourseID();
        string getSemesterID();
        bool setSemesterID(string newSemesterID);
        string getClassID();
        LinkedList <string> getTeacherNames();
        int getNUmberOfCredits();
        int getCapacity();
        bool setCapacity(int newCapacity);
        string getDayOfWeek();
        bool setDayOfWeek(string newDayOfWeek);
        string getSessionTime();
        bool setSessionTime(string newSessionTime);
        LinkedList <Student> getEnrolledStudentsList();
        bool addStudent(string newStudentID);
        bool removeStudent(string studentID);
};

#endif //COURSE_H
