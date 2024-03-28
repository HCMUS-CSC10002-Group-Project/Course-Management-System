#include "course.h"
#include "../utils/StringUtils.h"
#include "../utils/UUID.h"

Course::Course(string course_name, string semesterID, string classID, int numberOfCredits, int capacity, string dayOfWeek, string sessionTime)
{
    course_ID = UUIDGenerator::generate();
    this->course_name = course_name;
    this->semester_ID = semesterID;
    this->class_ID = classID;
    this->number_of_credits = numberOfCredits;
    this->capacity = capacity;
    this->day_of_week = dayOfWeek;
    this->session_time = sessionTime;
}

Course::Course(string courseID, string course_name, string semesterID, string classID, LinkedList<string> teacherNames, int numberOfCredits, int capacity, string dayOfWeek, string sessionTime, LinkedList<string> enrolledStudents)
{
    this->course_ID = courseID;
    this->course_name = course_name;
    this->semester_ID = semesterID;
    this->class_ID = classID;
    this->teacher_names = teacherNames;
    this->number_of_credits = numberOfCredits;
    this->capacity = capacity;
    this->day_of_week = dayOfWeek;
    this->session_time = sessionTime;
    this->enrolled_students = enrolledStudents;
}

string Course::getCourseID()
{
    return course_ID;
}

string Course::getCourseName()
{
    return course_name;
}

string Course::getSemesterID()
{
    return semester_ID;
}

bool Course::setCourseName(string newCourseName)
{
    course_name = newCourseName;
    return true;
}

bool Course::setSemesterID(string newSemesterID)
{
    semester_ID = newSemesterID;
    return true;
}

string Course::getClassID()
{
    return class_ID;
}

LinkedList<string> Course::getTeacherNames()
{
    return teacher_names;
}

int Course::getNumberOfCredits()
{
    return number_of_credits;
}

int Course::getCapacity()
{
    return capacity;
}

bool Course::setNumberOfCredits(int newNumberOfCredits)
{
    if (newNumberOfCredits < 0)
    {
        return false;
    }
    number_of_credits = newNumberOfCredits;
    return true;
}

bool Course::setCapacity(int newCapacity)
{
    if (newCapacity < 0)
    {
        return false;
    }
    capacity = newCapacity;
    return true;
}

string Course::getDayOfWeek()
{
    return day_of_week;
}

bool Course::setDayOfWeek(string newDayOfWeek)
{
    day_of_week = newDayOfWeek;
    return true;
}

string Course::getSessionTime()
{
    return session_time;
}

bool Course::setSessionTime(string newSessionTime)
{
    session_time = newSessionTime;
    return true;
}

LinkedList<string> Course::getEnrolledStudentsList()
{
    return enrolled_students;
}

string Course::serialize()
{
    string serialized = course_ID + "," + course_name + "," + semester_ID + "," + class_ID + ",";
    for (int i = 0; i < teacher_names.Size(); i++)
    {
        serialized += teacher_names.Get(i);
        if (i < teacher_names.Size() - 1)
        {
            serialized += ';';
        }
    }
    serialized += "," + std::to_string(number_of_credits) + "," + std::to_string(capacity) + "," + day_of_week + "," + session_time + ",";
    for (int i = 0; i < enrolled_students.Size(); i++)
    {
        serialized += enrolled_students.Get(i);
        if (i < enrolled_students.Size() - 1)
        {
            serialized += ';';
        }
    }
    return serialized;
}

Course Course::deserialize(const string &serialized)
{
    DynamicArray<string> data = split(serialized, ',');
    string courseID = data.Get(0);
    string courseName = data.Get(1);
    string semesterID = data.Get(2);
    string classID = data.Get(3);
    LinkedList<string> teacherNames;
    DynamicArray<string> teacherNamesData = split(data.Get(4), ';');
    for (int i = 0; i < teacherNamesData.Size(); i++)
    {
        teacherNames.AddToEnd(teacherNamesData.Get(i));
    }
    int numberOfCredits = std::stoi(data.Get(5));
    int capacity = std::stoi(data.Get(6));
    string dayOfWeek = data.Get(7);
    string sessionTime = data.Get(8);
    LinkedList<string> enrolledStudents;
    DynamicArray<string> enrolledStudentsData = split(data.Get(9), ';');
    for (int i = 0; i < enrolledStudentsData.Size(); i++)
    {
        enrolledStudents.AddToEnd(enrolledStudentsData.Get(i));
    }
    return Course(courseID, courseName, semesterID, classID, teacherNames, numberOfCredits, capacity, dayOfWeek, sessionTime, enrolledStudents);
}

string Course::getHeader()
{
    return "Course ID,Course Name,Semester ID,Class ID,Teacher Names,Number of Credits,Capacity,Day of Week,Session Time,Enrolled Student IDs";
}
