#include <gtest/gtest.h>
#include "schoolyear.h"

using namespace std;

TEST(SchoolYearTest, constructor)
{
    Date start_date(1, 1, 2022);
    Date end_date(1, 1, 2021);
    ASSERT_THROW(SchoolYear schoolYear(start_date, end_date), invalid_argument);
    Date start_date2(1, 1, 2020);
    Date end_date2(1, 1, 2021);
    SchoolYear schoolYear2(start_date2, end_date2);
    ASSERT_EQ(schoolYear2.getStartDate(), start_date2);
    ASSERT_EQ(schoolYear2.getEndDate(), end_date2);
}

TEST(SchoolYearTest, getyearID)
{
    Date start_date(1, 1, 2020);
    Date end_date(1, 1, 2021);
    SchoolYear schoolYear(start_date, end_date);
    string yearID = schoolYear.getYearID();
    ASSERT_NE(yearID, "");
}

TEST(SchoolYearTest, getStartDate)
{
    Date start_date(1, 1, 2020);
    Date end_date(1, 1, 2021);
    SchoolYear schoolYear(start_date, end_date);
    Date startDate = schoolYear.getStartDate();
    ASSERT_EQ(startDate, start_date);
}

TEST(SchoolYearTest, getEndDate)
{
    Date start_date(1, 1, 2020);
    Date end_date(1, 1, 2021);
    SchoolYear schoolYear(start_date, end_date);
    Date endDate = schoolYear.getEndDate();
    ASSERT_EQ(endDate, end_date);
}

TEST(SchoolYearTest, getSemesters)
{
    Date start_date(1, 1, 2020);
    Date end_date(1, 1, 2021);
    SchoolYear schoolYear(start_date, end_date);
    LinkedList<Semester> semesters = schoolYear.getSemesters();
    ASSERT_EQ(semesters.Size(), 0);
    Semester semester1(schoolYear.getYearID(), start_date, end_date);
    schoolYear.addSemester(semester1);
    semesters = schoolYear.getSemesters();
    ASSERT_EQ(semesters.Size(), 1);
    Semester semester2(schoolYear.getYearID(), start_date, end_date);
    schoolYear.addSemester(semester2);
    semesters = schoolYear.getSemesters();
    ASSERT_EQ(semesters.Size(), 2);
}

TEST(SchoolYearTest, setStartDate)
{
    Date start_date(1, 1, 2020);
    Date end_date(1, 1, 2021);
    SchoolYear schoolYear(start_date, end_date);
    Date newStartDate(1, 1, 2021);
    EXPECT_TRUE(schoolYear.setStartDate(newStartDate));
    Date startDate = schoolYear.getStartDate();
    ASSERT_EQ(startDate, newStartDate);
    Date newStartDate2(1, 1, 2022);
    EXPECT_FALSE(schoolYear.setStartDate(newStartDate2));
}

TEST(SchoolYearTest, setEndDate)
{
    Date start_date(1, 1, 2020);
    Date end_date(1, 1, 2021);
    SchoolYear schoolYear(start_date, end_date);
    Date newEndDate(1, 1, 2022);
    EXPECT_TRUE(schoolYear.setEndDate(newEndDate));
    Date endDate = schoolYear.getEndDate();
    ASSERT_EQ(endDate, newEndDate);
    Date newEndDate2(1, 1, 2019);
    EXPECT_FALSE(schoolYear.setEndDate(newEndDate2));
}

TEST(SchoolYearTest, getNumSemester)
{
    Date start_date(1, 1, 2020);
    Date end_date(1, 1, 2021);
    SchoolYear schoolYear(start_date, end_date);
    ASSERT_EQ(schoolYear.getNumSemester(), 0);
    Semester semester1(schoolYear.getYearID(), start_date, end_date);
    schoolYear.addSemester(semester1);
    ASSERT_EQ(schoolYear.getNumSemester(), 1);
    Semester semester2(schoolYear.getYearID(), start_date, end_date);
    schoolYear.addSemester(semester2);
    ASSERT_EQ(schoolYear.getNumSemester(), 2);
}

TEST(SchoolYearTest, addSemester)
{
    Date start_date(1, 1, 2020);
    Date end_date(1, 1, 2021);
    SchoolYear schoolYear(start_date, end_date);
    Semester semester1(schoolYear.getYearID(), start_date, end_date);
    EXPECT_TRUE(schoolYear.addSemester(semester1));
    ASSERT_EQ(schoolYear.getNumSemester(), 1);
    Semester semester2(schoolYear.getYearID(), start_date, end_date);
    EXPECT_TRUE(schoolYear.addSemester(semester2));
    ASSERT_EQ(schoolYear.getNumSemester(), 2);
    Semester semester3(schoolYear.getYearID(), start_date, end_date);
    EXPECT_FALSE(schoolYear.addSemester(semester3));
    ASSERT_EQ(schoolYear.getNumSemester(), 2);
}

TEST(SchoolYearTest, removeSemester)
{
    Date start_date(1, 1, 2020);
    Date end_date(1, 1, 2021);
    SchoolYear schoolYear(start_date, end_date);
    Semester semester1(schoolYear.getYearID(), start_date, end_date);
    schoolYear.addSemester(semester1);
    ASSERT_EQ(schoolYear.getNumSemester(), 1);
    EXPECT_TRUE(schoolYear.removeSemester(semester1));
    ASSERT_EQ(schoolYear.getNumSemester(), 0);
    Semester semester2(schoolYear.getYearID(), start_date, end_date);
    schoolYear.addSemester(semester2);
    ASSERT_EQ(schoolYear.getNumSemester(), 1);
    Semester semester3(schoolYear.getYearID(), start_date, end_date);
    EXPECT_FALSE(schoolYear.removeSemester(semester3));
    ASSERT_EQ(schoolYear.getNumSemester(), 1);
}
