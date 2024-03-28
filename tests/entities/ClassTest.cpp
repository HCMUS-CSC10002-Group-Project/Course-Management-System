#include <gtest/gtest.h>
#include "class.h"

TEST(Class, Constructor)
{
    LinkedList<string> studentIDs;
    studentIDs.AddToEnd("S01");
    studentIDs.AddToEnd("S02");
    Class class_("C01", "OOP", studentIDs);
    EXPECT_EQ(class_.getClassID(), "C01");
    EXPECT_EQ(class_.getName(), "OOP");
    LinkedList<string> studentIDs_ = class_.getListOfStudentIDs();
    EXPECT_EQ(studentIDs_.Size(), 2);
    EXPECT_EQ(studentIDs_.Get(0), "S01");
    EXPECT_EQ(studentIDs_.Get(1), "S02");
}

TEST(Class, Serialize)
{
    LinkedList<string> studentIDs;
    studentIDs.AddToEnd("S01");
    studentIDs.AddToEnd("S02");
    Class class_("C01", "OOP", studentIDs);
    string serialized = class_.serialize();
    EXPECT_EQ(serialized, "C01,OOP,S01;S02");
}

TEST(Class, Deserialize)
{
    Class class_ = Class::deserialize("C01,OOP,S01;S02");
    EXPECT_EQ(class_.getClassID(), "C01");
    EXPECT_EQ(class_.getName(), "OOP");
    LinkedList<string> studentIDs = class_.getListOfStudentIDs();
    EXPECT_EQ(studentIDs.Size(), 2);
    EXPECT_EQ(studentIDs.Get(0), "S01");
    EXPECT_EQ(studentIDs.Get(1), "S02");
}
