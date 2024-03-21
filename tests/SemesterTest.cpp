#include <gtest/gtest.h>
#include "semester.h"

using namespace std;

TEST(SemesterTest, SemesterConstructor)
{
    Date start_date(1, 1, 2021);
    Date end_date(1, 1, 2022);
    Semester semester("2021", start_date, end_date);
    EXPECT_NE(semester.getSemesterID(), "");
    EXPECT_EQ(semester.getYearID(), "2021");
    EXPECT_EQ(semester.getStartDate(), start_date);
    EXPECT_EQ(semester.getEndDate(), end_date);
}

TEST(SemesterTest, SemesterSetter)
{
    Date start_date(1, 1, 2021);
    Date end_date(1, 1, 2022);
    Semester semester("2021", start_date, end_date);
    Date new_start_date(1, 1, 2022);
    Date new_end_date(1, 1, 2023);
    semester.setStartDate(new_start_date);
    semester.setEndDate(new_end_date);
    EXPECT_EQ(semester.getStartDate(), new_start_date);
    EXPECT_EQ(semester.getEndDate(), new_end_date);
    Date invalid_start_date(1, 1, 2024);
    Date invalid_end_date(1, 1, 2023);
    EXPECT_FALSE(semester.setStartDate(invalid_start_date));
    EXPECT_FALSE(semester.setEndDate(invalid_end_date));
    EXPECT_EQ(semester.getStartDate(), new_start_date);
    EXPECT_EQ(semester.getEndDate(), new_end_date);
    Date invalid_date(30, 2, 2024);
    EXPECT_FALSE(semester.setStartDate(invalid_date));
    EXPECT_FALSE(semester.setEndDate(invalid_date));
    EXPECT_EQ(semester.getStartDate(), new_start_date);
    EXPECT_EQ(semester.getEndDate(), new_end_date);
}
