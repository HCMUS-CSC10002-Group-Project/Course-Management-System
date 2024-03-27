#include <gtest/gtest.h>
#include "course.h"

TEST(Course, Constructor)
{
    Course course("OOP", "S01", "C01", 3, 50, "Monday", "7:30-9:30");
    EXPECT_EQ(course.getCourseName(), "OOP");
    EXPECT_EQ(course.getSemesterID(), "S01");
    EXPECT_EQ(course.getClassID(), "C01");
    EXPECT_EQ(course.getNumberOfCredits(), 3);
    EXPECT_EQ(course.getCapacity(), 50);
    EXPECT_EQ(course.getDayOfWeek(), "Monday");
    EXPECT_EQ(course.getSessionTime(), "7:30-9:30");
}

TEST(Course, Serialize)
{
    LinkedList<string> teacherNames;
    teacherNames.AddToEnd("Teacher 1");
    teacherNames.AddToEnd("Teacher 2");
    LinkedList<string> enrolledStudents;
    enrolledStudents.AddToEnd("Student 1");
    enrolledStudents.AddToEnd("Student 2");
    Course course("CSC101", "OOP", "S01", "C01", teacherNames, 3, 50, "Monday", "7:30-9:30", enrolledStudents);
    string serialized = course.serialize();
    EXPECT_EQ(serialized, "CSC101,OOP,S01,C01,Teacher 1;Teacher 2,3,50,Monday,7:30-9:30,Student 1;Student 2");
}

TEST(Course, Deserialize)
{
    Course course = Course::deserialize("CSC101,OOP,S01,C01,Teacher 1;Teacher 2,3,50,Monday,7:30-9:30,Student 1;Student 2");
    EXPECT_EQ(course.getCourseID(), "CSC101");
    EXPECT_EQ(course.getCourseName(), "OOP");
    EXPECT_EQ(course.getSemesterID(), "S01");
    EXPECT_EQ(course.getClassID(), "C01");
    EXPECT_EQ(course.getNumberOfCredits(), 3);
    EXPECT_EQ(course.getCapacity(), 50);
    EXPECT_EQ(course.getDayOfWeek(), "Monday");
    EXPECT_EQ(course.getSessionTime(), "7:30-9:30");
    LinkedList<string> teacherNames = course.getTeacherNames();
    EXPECT_EQ(teacherNames.Size(), 2);
    EXPECT_EQ(teacherNames.Get(0), "Teacher 1");
    EXPECT_EQ(teacherNames.Get(1), "Teacher 2");
    LinkedList<string> enrolledStudents = course.getEnrolledStudentsList();
    EXPECT_EQ(enrolledStudents.Size(), 2);
    EXPECT_EQ(enrolledStudents.Get(0), "Student 1");
    EXPECT_EQ(enrolledStudents.Get(1), "Student 2");
}