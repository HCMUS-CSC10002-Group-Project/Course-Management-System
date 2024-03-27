#include <gtest/gtest.h>
#include "semester.h"

TEST(SemesterTest, testConstructor)
{
    Date start_date(1, 1, 2020);
    Date end_date(1, 1, 2021);
    Semester semester("2020", "Học kỳ 1", start_date, end_date);
    ASSERT_EQ(semester.getYearID(), "2020");
    ASSERT_EQ(semester.getSemesterName(), "Học kỳ 1");
    ASSERT_EQ(semester.getStartDate().getDay(), 1);
    ASSERT_EQ(semester.getStartDate().getMonth(), 1);
    ASSERT_EQ(semester.getStartDate().getYear(), 2020);
    ASSERT_EQ(semester.getEndDate().getDay(), 1);
    ASSERT_EQ(semester.getEndDate().getMonth(), 1);
    ASSERT_EQ(semester.getEndDate().getYear(), 2021);
}

TEST(SemesterTest, Serialize)
{
    Date start_date(1, 1, 2020);
    Date end_date(1, 1, 2021);
    Semester semester("2020", "Hk1", start_date, end_date);
    string serialized = semester.serialize();
    Semester deserialized = Semester::deserialize(serialized);
    ASSERT_EQ(deserialized.getYearID(), "2020");
    ASSERT_EQ(deserialized.getSemesterName(), "Hk1");
    ASSERT_EQ(deserialized.getStartDate().getDay(), 1);
    ASSERT_EQ(deserialized.getStartDate().getMonth(), 1);
    ASSERT_EQ(deserialized.getStartDate().getYear(), 2020);
    ASSERT_EQ(deserialized.getEndDate().getDay(), 1);
    ASSERT_EQ(deserialized.getEndDate().getMonth(), 1);
    ASSERT_EQ(deserialized.getEndDate().getYear(), 2021);
}

TEST(SemesterTest, Deserialize)
{
    string serialized = "123,2020,Hk1,1-1-2020,1-1-2021";
    Semester semester = Semester::deserialize(serialized);
    ASSERT_EQ(semester.getYearID(), "2020");
    ASSERT_EQ(semester.getSemesterName(), "Hk1");
    ASSERT_EQ(semester.getStartDate().getDay(), 1);
    ASSERT_EQ(semester.getStartDate().getMonth(), 1);
    ASSERT_EQ(semester.getStartDate().getYear(), 2020);
    ASSERT_EQ(semester.getEndDate().getDay(), 1);
    ASSERT_EQ(semester.getEndDate().getMonth(), 1);
    ASSERT_EQ(semester.getEndDate().getYear(), 2021);
}