#include <gtest/gtest.h>
#include "student.h"
#include "date.h"

using namespace std;

TEST(StudentTest, StudentConstructor)
{
    Date dateOfBirth(1, 1, 2000);
    Student student("class1", "male", dateOfBirth, "major1", 2020);
    ASSERT_EQ("class1", student.getClassID());
    ASSERT_NE("", student.getStudentID());
    ASSERT_EQ("male", student.getGender());
    ASSERT_EQ(dateOfBirth, student.getDateOfBirth());
    ASSERT_EQ("major1", student.getMajor());
    ASSERT_EQ(2020, student.getCohort());
}

TEST(StudentTest, SetClassID)
{
    Date dateOfBirth(1, 1, 2000);
    Student student("class1", "male", dateOfBirth, "major1", 2020);
    ASSERT_TRUE(student.setClassID("class2"));
    ASSERT_EQ("class2", student.getClassID());
}

TEST(StudentTest, AddCourse)
{
    Date dateOfBirth(1, 1, 2000);
    Student student("class1", "male", dateOfBirth, "major1", 2020);
    ASSERT_TRUE(student.addCourse("course1"));
    ASSERT_TRUE(student.addCourse("course2"));
    ASSERT_TRUE(student.addCourse("course3"));
    ASSERT_TRUE(student.addCourse("course4"));
    LinkedList<string> courseIDs = student.getCourseIDs();
    ASSERT_EQ("course1", courseIDs.Get(0));
    ASSERT_EQ("course2", courseIDs.Get(1));
    ASSERT_EQ("course3", courseIDs.Get(2));
    ASSERT_EQ("course4", courseIDs.Get(3));
}

TEST(StudentTest, RemoveCourse)
{
    Date dateOfBirth(1, 1, 2000);
    Student student("class1", "male", dateOfBirth, "major1", 2020);
    student.addCourse("course1");
    student.addCourse("course2");
    student.addCourse("course3");
    student.addCourse("course4");
    ASSERT_TRUE(student.removeCourse("course2"));
    LinkedList<string> courseIDs = student.getCourseIDs();
    ASSERT_EQ("course1", courseIDs.Get(0));
    ASSERT_EQ("course3", courseIDs.Get(1));
    ASSERT_EQ("course4", courseIDs.Get(2));
}

TEST(StudentTest, SetGender)
{
    Date dateOfBirth(1, 1, 2000);
    Student student("class1", "male", dateOfBirth, "major1", 2020);
    ASSERT_EQ(student.getGender(), "male");
    ASSERT_TRUE(student.setGender("female"));
    ASSERT_EQ(student.getGender(), "female");
}

TEST(StudentTest, SetDateOfBirth)
{
    Date dateOfBirth(1, 1, 2000);
    Student student("class1", "female", dateOfBirth, "major1", 2020);
    ASSERT_EQ(student.getDateOfBirth(), dateOfBirth);
    Date newDateOfBirth(2, 2, 2002);
    ASSERT_TRUE(student.setDateOfBirth(newDateOfBirth));
    ASSERT_EQ(student.getDateOfBirth(), newDateOfBirth);
}

TEST(StudentTest, SetMajor)
{
    Date dateOfBirth(1, 1, 2000);
    Student student("class1", "female", dateOfBirth, "major1", 2020);
    ASSERT_EQ(student.getMajor(), "major1");
    ASSERT_TRUE(student.setMajor("major2"));
    ASSERT_EQ(student.getMajor(), "major2");
}

TEST(StudentTest, SetCohort)
{
    Date dateOfBirth(1, 1, 2000);
    Student student("class1", "male", dateOfBirth, "major1", 2020);
    ASSERT_EQ(student.getCohort(), 2020);
    ASSERT_TRUE(student.setCohort(2021));
    ASSERT_EQ(student.getCohort(), 2021);
    ASSERT_FALSE(student.setCohort(0));
    ASSERT_EQ(student.getCohort(), 2021);
    ASSERT_FALSE(student.setCohort(-1));
    ASSERT_EQ(student.getCohort(), 2021);
}
