#ifndef COURSESERVICE_H
#define COURSESERVE_H
#include "../entities/course.h"
#include "../entities/student.h"
#include "../data_structures/LinkedList.h"
class CourseService
{
    public: 
    bool addCourse(Course course);
    bool updateCourse(string courseID, Course newCourse);
    bool enrollStudentInCourse(string studentID, string courseID);
    bool unenrollStudentFromCourse(string studentId, string courseID);
    bool deleteCourse(Course course);
    LinkedList<Course> viewCourses();
    LinkedList<Student> viewStudentsInCourse(string courseID);
};
#endif