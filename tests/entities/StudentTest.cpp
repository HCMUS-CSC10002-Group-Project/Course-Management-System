#include <gtest/gtest.h>
#include "student.h"
#include "date.h"

using namespace std;

const string fullName = "John Doe";
const string department = "Computer Science";
const string email = "john.doe@example.com";
const string username = "johndoe";
const string password = "password123";
const string socialID = "123456789";

TEST(StudentTest, StudentConstructor)
{
    Date dateOfBirth(1, 1, 2000);
    Student student(fullName, department, email, username, password, "class1", "male", dateOfBirth, "major1", 2020, socialID);
    ASSERT_EQ("class1", student.getClassID());
    ASSERT_NE("", student.getStudentID());
    ASSERT_EQ("male", student.getGender());
    ASSERT_EQ(dateOfBirth, student.getDateOfBirth());
    ASSERT_EQ("major1", student.getMajor());
    ASSERT_EQ(2020, student.getCohort());
    ASSERT_EQ(socialID, student.getSocialID());
}

TEST(StudentTest, SetClassID)
{
    Date dateOfBirth(1, 1, 2000);
    Student student(fullName, department, email, username, password, "class1", "male", dateOfBirth, "major1", 2020, socialID);
    ASSERT_TRUE(student.setClassID("class2"));
    ASSERT_EQ("class2", student.getClassID());
    ASSERT_FALSE(student.setClassID(""));
    ASSERT_EQ("class2", student.getClassID());
}

TEST(StudentTest, AddCourse)
{
    Date dateOfBirth(1, 1, 2000);
    Student student(fullName, department, email, username, password, "class1", "male", dateOfBirth, "major1", 2020, socialID);
    ASSERT_TRUE(student.addCourse("course1"));
    ASSERT_TRUE(student.addCourse("course2"));
    ASSERT_TRUE(student.addCourse("course3"));
    ASSERT_TRUE(student.addCourse("course4"));
    ASSERT_FALSE(student.addCourse("course1"));
    ASSERT_FALSE(student.addCourse(""));
    LinkedList<string> courseIDs = student.getCourseIDs();
    ASSERT_EQ(4, courseIDs.Size()); // Assuming LinkedList has a Size() method to check the count
}

TEST(StudentTest, RemoveCourse)
{
    Date dateOfBirth(1, 1, 2000);
    Student student(fullName, department, email, username, password, "class1", "male", dateOfBirth, "major1", 2020, socialID);
    student.addCourse("course1");
    student.addCourse("course2");
    student.addCourse("course3");
    student.addCourse("course4");
    ASSERT_TRUE(student.removeCourse("course2"));
    LinkedList<string> courseIDs = student.getCourseIDs();
    ASSERT_EQ(3, courseIDs.Size()); // Assuming LinkedList has a Size() method to check the count
    ASSERT_FALSE(student.removeCourse("course2"));
    ASSERT_FALSE(student.removeCourse(""));
    ASSERT_EQ(3, courseIDs.Size()); // Assuming LinkedList has a Size() method to check the count
}

TEST(StudentTest, SetGender)
{
    Date dateOfBirth(1, 1, 2000);
    Student student(fullName, department, email, username, password, "class1", "male", dateOfBirth, "major1", 2020, socialID);
    ASSERT_EQ("male", student.getGender());
    ASSERT_TRUE(student.setGender("female"));
    ASSERT_EQ("female", student.getGender());
    ASSERT_FALSE(student.setGender(""));
}

TEST(StudentTest, SetDateOfBirth)
{
    Date dateOfBirth(1, 1, 2000);
    Student student(fullName, department, email, username, password, "class1", "female", dateOfBirth, "major1", 2020, socialID);
    ASSERT_EQ(dateOfBirth, student.getDateOfBirth());
    Date newDateOfBirth(2, 2, 2002);
    ASSERT_TRUE(student.setDateOfBirth(newDateOfBirth));
    ASSERT_EQ(newDateOfBirth, student.getDateOfBirth());
}

TEST(StudentTest, SetMajor)
{
    Date dateOfBirth(1, 1, 2000);
    Student student(fullName, department, email, username, password, "class1", "female", dateOfBirth, "major1", 2020, socialID);
    ASSERT_EQ("major1", student.getMajor());
    ASSERT_TRUE(student.setMajor("major2"));
    ASSERT_EQ("major2", student.getMajor());
}

TEST(StudentTest, SetCohort)
{
    Date dateOfBirth(1, 1, 2000);
    Student student(fullName, department, email, username, password, "class1", "male", dateOfBirth, "major1", 2020, socialID);
    ASSERT_EQ(student.getCohort(), 2020);
    ASSERT_TRUE(student.setCohort(2021));
    ASSERT_EQ(student.getCohort(), 2021);
    ASSERT_FALSE(student.setCohort(0));
    ASSERT_EQ(student.getCohort(), 2021);
    ASSERT_FALSE(student.setCohort(-1));
    ASSERT_EQ(student.getCohort(), 2021);
}

TEST(StudentTest, SetSocialID)
{
    Date dateOfBirth(1, 1, 2000);
    Student student(fullName, department, email, username, password, "class1", "male", dateOfBirth, "major1", 2020, socialID);
    ASSERT_EQ(socialID, student.getSocialID());
    ASSERT_TRUE(student.setSocialID("987654321"));
    ASSERT_EQ("987654321", student.getSocialID());
    ASSERT_FALSE(student.setSocialID(""));
    ASSERT_EQ("987654321", student.getSocialID());
}