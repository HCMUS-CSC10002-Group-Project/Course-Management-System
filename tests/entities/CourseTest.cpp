#include <gtest/gtest.h>
#include "course.h"

TEST(CourseTest, CourseConstructor)
{
    Course course("S1", "C1", 3, 30, "Monday", "8:00-9:30");
    ASSERT_NE("", course.getCourseID());
    ASSERT_EQ("S1", course.getSemesterID());
    ASSERT_EQ("C1", course.getClassID());
    ASSERT_EQ(3, course.getNUmberOfCredits());
    ASSERT_EQ(30, course.getCapacity());
    ASSERT_EQ("Monday", course.getDayOfWeek());
    ASSERT_EQ("8:00-9:30", course.getSessionTime());
}

TEST(CourseTest, CourseSetters)
{
    Course course("S1", "C1", 3, 30, "Monday", "8:00-9:30");
    ASSERT_TRUE(course.setSemesterID("S2"));
    ASSERT_EQ("S2", course.getSemesterID());
    ASSERT_FALSE(course.setSemesterID(""));
    ASSERT_EQ("S2", course.getSemesterID());
    ASSERT_TRUE(course.setCapacity(40));
    ASSERT_EQ(40, course.getCapacity());
    ASSERT_FALSE(course.setCapacity(-1));
    ASSERT_EQ(40, course.getCapacity());
    ASSERT_TRUE(course.setDayOfWeek("Tuesday"));
    ASSERT_EQ("Tuesday", course.getDayOfWeek());
    ASSERT_FALSE(course.setDayOfWeek(""));
    ASSERT_EQ("Tuesday", course.getDayOfWeek());
    ASSERT_TRUE(course.setSessionTime("9:00-10:30"));
    ASSERT_EQ("9:00-10:30", course.getSessionTime());
    ASSERT_FALSE(course.setSessionTime(""));
    ASSERT_EQ("9:00-10:30", course.getSessionTime());
}

TEST(CourseTest, CourseAddRemoveStudent)
{
    Course course("S1", "C1", 3, 10, "Monday", "8:00-9:30");
    ASSERT_TRUE(course.addStudent("S1"));
    ASSERT_TRUE(course.addStudent("S2"));
    ASSERT_TRUE(course.addStudent("S3"));
    ASSERT_TRUE(course.addStudent("S4"));
    ASSERT_TRUE(course.addStudent("S5"));
    ASSERT_TRUE(course.addStudent("S6"));
    ASSERT_TRUE(course.addStudent("S7"));
    ASSERT_TRUE(course.addStudent("S8"));
    ASSERT_TRUE(course.addStudent("S9"));
    ASSERT_TRUE(course.addStudent("S10"));
    ASSERT_FALSE(course.addStudent("S11"));
    ASSERT_EQ(10, course.getEnrolledStudentsList().Size());
    ASSERT_TRUE(course.removeStudent("S1"));
    ASSERT_TRUE(course.removeStudent("S2"));
    ASSERT_TRUE(course.removeStudent("S3"));
    ASSERT_TRUE(course.removeStudent("S4"));
    ASSERT_TRUE(course.removeStudent("S5"));
    ASSERT_TRUE(course.removeStudent("S6"));
    ASSERT_TRUE(course.removeStudent("S7"));
    ASSERT_TRUE(course.removeStudent("S8"));
    ASSERT_TRUE(course.removeStudent("S9"));
    ASSERT_TRUE(course.removeStudent("S10"));
    ASSERT_FALSE(course.removeStudent("S11"));
    ASSERT_EQ(0, course.getEnrolledStudentsList().Size());
}

TEST(CourseTest, CourseAddDuplicatedStudent)
{
    Course course("S1", "C1", 3, 10, "Monday", "8:00-9:30");
    ASSERT_TRUE(course.addStudent("S1"));
    ASSERT_FALSE(course.addStudent("S1"));
    ASSERT_EQ(1, course.getEnrolledStudentsList().Size());
    ASSERT_TRUE(course.removeStudent("S1"));
    ASSERT_EQ(0, course.getEnrolledStudentsList().Size());
    ASSERT_TRUE(course.addStudent("S1"));
    ASSERT_EQ(1, course.getEnrolledStudentsList().Size());
    ASSERT_TRUE(course.addStudent("S2"));
    ASSERT_FALSE(course.addStudent("S2"));
    ASSERT_EQ(2, course.getEnrolledStudentsList().Size());
    ASSERT_TRUE(course.removeStudent("S1"));
    ASSERT_TRUE(course.removeStudent("S2"));
    ASSERT_EQ(0, course.getEnrolledStudentsList().Size());
}

TEST(CourseTest, CourseAddStudentToFullCourse)
{
    Course course("S1", "C1", 3, 2, "Monday", "8:00-9:30");
    ASSERT_TRUE(course.addStudent("S1"));
    ASSERT_TRUE(course.addStudent("S2"));
    ASSERT_FALSE(course.addStudent("S3"));
    ASSERT_EQ(2, course.getEnrolledStudentsList().Size());
    ASSERT_TRUE(course.removeStudent("S1"));
    ASSERT_TRUE(course.removeStudent("S2"));
    ASSERT_EQ(0, course.getEnrolledStudentsList().Size());
    ASSERT_TRUE(course.addStudent("S3"));
    ASSERT_FALSE(course.addStudent("S3"));
    ASSERT_TRUE(course.addStudent("S2"));
    ASSERT_EQ(2, course.getEnrolledStudentsList().Size());
    ASSERT_EQ("S3", course.getEnrolledStudentsList().Get(0));
    ASSERT_EQ("S2", course.getEnrolledStudentsList().Get(1));
    ASSERT_FALSE(course.removeStudent("S1"));
    ASSERT_TRUE(course.removeStudent("S2"));
    ASSERT_EQ(1, course.getEnrolledStudentsList().Size());
}
