#include <gtest/gtest.h>
#include "class.h"

TEST(ClassTest, testConstructor)
{
    Class c("Intro to Computer Science", LinkedList<Student>());
    ASSERT_NE(c.getClassID(), "");
    ASSERT_EQ(c.getName(), "Intro to Computer Science");
    ASSERT_EQ(c.getListOfStudents().Size(), 0);
}

TEST(ClassTest, testSetName)
{
    Class c("Intro to Computer Science", LinkedList<Student>());
    EXPECT_TRUE(c.setName("Intro to Computer Science 2"));
    ASSERT_EQ(c.getName(), "Intro to Computer Science 2");
    EXPECT_FALSE(c.setName(""));
    ASSERT_EQ(c.getName(), "Intro to Computer Science 2");
}

TEST(ClassTest, testAddStudent)
{
    Class c("Intro to Computer Science", LinkedList<Student>());
    Date d(1, 1, 2000);
    Student s("John Doe", "Computer Science", "ababa@gmail.com", "johndoe", "password", c.getClassID(), "male", d, "Computer Science", 2023, "123456789");
    EXPECT_TRUE(c.addStudent(s));
    ASSERT_EQ(c.getListOfStudents().Size(), 1);
    EXPECT_FALSE(c.addStudent(s));
    ASSERT_EQ(c.getListOfStudents().Size(), 1);
}

TEST(ClassTest, testRemoveStudent)
{
    Class c("Intro to Computer Science", LinkedList<Student>());
    Date d(1, 1, 2000);
    Student s("John Doe", "Computer Science", "ababa@gmail.com", "johndoe", "password", c.getClassID(), "male", d, "Computer Science", 2023, "123456789");
    c.addStudent(s);
    EXPECT_TRUE(c.removeStudent(s));
    ASSERT_EQ(c.getListOfStudents().Size(), 0);
    EXPECT_FALSE(c.removeStudent(s));
    ASSERT_EQ(c.getListOfStudents().Size(), 0);
}
