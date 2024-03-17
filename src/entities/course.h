#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "student.h"
#include "../data_structures/LinkedList.h"

using std::string;

//TODO: add scoreboard.h and add getters/setters

class Course
{
    //course data
    private:
        string course_ID;
        string semester_ID;
        string class_ID;
        LinkedList <string> teacher_name;
        int number_of_credits;
        int capacity;
        string day_of_week;
        string session_time;
        LinkedList <Student> enrolled_students;
        //Scoreboard score_board;
};

#endif //COURSE_H
