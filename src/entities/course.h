#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "student.h"
#include "scoreboard.h"
#include "../data_structures/LinkedList.h"

using std::string;

// TODO: add getters/setters

class Course
{
    // course data
private:
    string course_ID;
    string course_name;
    string semester_ID;
    string class_ID;
    LinkedList<string> teacher_names;
    int number_of_credits;
    int capacity;
    string day_of_week;
    string session_time;
    LinkedList<string> enrolled_students;
    // Scoreboard score_board;

public:
    // constructor
    Course(string course_name, string semesterID, string classID, int numberOfCredits, int capacity, string dayOfWeek, string sessionTime);
    Course(string courseID, string course_name, string semesterID, string classID, LinkedList<string> teacherNames, int numberOfCredits, int capacity, string dayOfWeek, string sessionTime, LinkedList<string> enrolledStudents);
    // getters and setters
    string getCourseID();
    string getSemesterID();
    string getCourseName();
    bool setCourseName(string newCourseName);
    bool setSemesterID(string newSemesterID);
    string getClassID();
    LinkedList<string> getTeacherNames();
    int getNumberOfCredits();
    int getCapacity();
    bool setNumberOfCredits(int newNumberOfCredits);
    bool setCapacity(int newCapacity);
    string getDayOfWeek();
    bool setDayOfWeek(string newDayOfWeek);
    string getSessionTime();
    bool setSessionTime(string newSessionTime);
    LinkedList<string> getEnrolledStudentsList();
    bool addStudent(string newStudentID);
    bool removeStudent(string studentID);

    // serialization
    string serialize();
    static Course deserialize(const string &serialized);
    static string getHeader();
};

#endif // COURSE_H
