#include <gtest/gtest.h>
#include "academicStaff.h"

TEST(AcademicStaffTest, getStaffID)
{
    AcademicStaff staff;
    EXPECT_NE(staff.getStaffID(), "");
}