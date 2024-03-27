#include <gtest/gtest.h>
#include "academicStaff.h"

TEST(AcademicStaff, Constructor)
{
    AcademicStaff academicStaff("1", "Nguyen Van A", "Compsci", "ba@gmail.com", "user", "pass", "0123456789");
    EXPECT_EQ(academicStaff.getID(), "1");
    EXPECT_EQ(academicStaff.getFullName(), "Nguyen Van A");
    EXPECT_EQ(academicStaff.getDepartment(), "Compsci");
    EXPECT_EQ(academicStaff.getEmail(), "ba@gmail.com");
    EXPECT_EQ(academicStaff.getUsername(), "user");
    EXPECT_EQ(academicStaff.getPassword(), "pass");
    EXPECT_EQ(academicStaff.getStaffID(), "0123456789");
}

TEST(AcademicStaff, Serialize)
{
    AcademicStaff academicStaff("1", "Nguyen Van A", "Compsci", "ba@gmail.com", "user", "pass", "0123456789");
    string serialized = academicStaff.serialize();
    EXPECT_EQ(serialized, "1,Nguyen Van A,Compsci,ba@gmail.com,user,pass,0123456789");
}

TEST(AcademicStaff, Deserialize)
{
    AcademicStaff academicStaff = AcademicStaff::deserialize("1,Nguyen Van A,Compsci,ba@gmail.com,user,pass,0123456789");
    EXPECT_EQ(academicStaff.getID(), "1");
    EXPECT_EQ(academicStaff.getFullName(), "Nguyen Van A");
    EXPECT_EQ(academicStaff.getDepartment(), "Compsci");
    EXPECT_EQ(academicStaff.getEmail(), "ba@gmail.com");
    EXPECT_EQ(academicStaff.getUsername(), "user");
    EXPECT_EQ(academicStaff.getPassword(), "pass");
    EXPECT_EQ(academicStaff.getStaffID(), "0123456789");
}
