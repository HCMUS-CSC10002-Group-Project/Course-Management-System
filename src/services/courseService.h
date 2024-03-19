#ifndef COURSESERVICE_H
#define COURSESERVE_H
#include "../entities/course.h"
#include "../entities/student.h"
#include "../data_structures/LinkedList.h"
class CourseService
{
    public: 
    bool addCourse(Course course);
    bool updateCourse(Course course);
    bool enrollStudentInCourse(Student student);
    bool unenrollStudentFromCourse(Student student);
    bool deleteCourse(Course course);
    LinkedList<Course> viewCourse(LinkedList<Course> course);
    LinkedList<Student> viewStudentInCourse(LinkedList<Student> student);
};
#endif