#include <gtest/gtest.h>
#include "student.h"

TEST(StudentTest, Constructor)
{
    LinkedList<string> courseIDs;
    Student student("1", "John Doe", "IT", "aa@gmail.com", "admin", "admin", "2312", "12", courseIDs, "male", Date(1, 1, 2000), "IT", "2020", "123456789");
    ASSERT_EQ(student.getID(), "1");
    ASSERT_EQ(student.getFullName(), "John Doe");
    ASSERT_EQ(student.getDepartment(), "IT");
    ASSERT_EQ(student.getEmail(), "aa@gmail.com");
    ASSERT_EQ(student.getUsername(), "admin");
    ASSERT_EQ(student.getPassword(), "admin");
    ASSERT_EQ(student.getStudentID(), "2312");
    ASSERT_EQ(student.getClassID(), "12");
    ASSERT_EQ(student.getCourseIDs().Size(), 0);
    ASSERT_EQ(student.getGender(), "male");
    ASSERT_EQ(student.getDateOfBirth().getDay(), 1);
    ASSERT_EQ(student.getDateOfBirth().getMonth(), 1);
    ASSERT_EQ(student.getDateOfBirth().getYear(), 2000);
    ASSERT_EQ(student.getMajor(), "IT");
    ASSERT_EQ(student.getCohort(), "2020");
    ASSERT_EQ(student.getSocialID(), "123456789");
}

TEST(StudentTest, Serialize)
{
    LinkedList<string> courseIDs;
    Student student("1", "John Doe", "IT", "aa@gmail.com", "admin", "admin", "2312", "12", courseIDs, "male", Date(1, 1, 2000), "IT", "2020", "123456789");
    string serialized = student.serialize();
    ASSERT_EQ(serialized, "1,John Doe,IT,aa@gmail.com,admin,admin,2312,12,,male,1-1-2000,IT,2020,123456789");
}

TEST(StudentTest, Deserialize)
{
    string serialized = "1,John Doe,IT,aa@gmail.com,admin,admin,2312,12,2;3;4,male,1-1-2000,IT,2020,123456789";
    Student student = Student::deserialize(serialized);
    ASSERT_EQ(student.getID(), "1");
    ASSERT_EQ(student.getFullName(), "John Doe");
    ASSERT_EQ(student.getDepartment(), "IT");
    ASSERT_EQ(student.getEmail(), "aa@gmail.com");
    ASSERT_EQ(student.getUsername(), "admin");
    ASSERT_EQ(student.getPassword(), "admin");
    ASSERT_EQ(student.getStudentID(), "2312");
    ASSERT_EQ(student.getClassID(), "12");
    ASSERT_EQ(student.getCourseIDs().Size(), 3);
    ASSERT_EQ(student.getGender(), "male");
    ASSERT_EQ(student.getDateOfBirth().getDay(), 1);
    ASSERT_EQ(student.getDateOfBirth().getMonth(), 1);
    ASSERT_EQ(student.getDateOfBirth().getYear(), 2000);
    ASSERT_EQ(student.getMajor(), "IT");
    ASSERT_EQ(student.getCohort(), "2020");
    ASSERT_EQ(student.getSocialID(), "123456789");
}