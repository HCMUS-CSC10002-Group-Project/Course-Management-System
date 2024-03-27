#include <gtest/gtest.h>
#include "date.h"
#include <string>

using std::string;

TEST(DateTest, Constructor)
{
    Date date(1, 1, 2000);
    ASSERT_EQ(date.getDay(), 1);
    ASSERT_EQ(date.getMonth(), 1);
    ASSERT_EQ(date.getYear(), 2000);
}

TEST(DateTest, IsValid)
{
    Date date(1, 1, 2000);
    ASSERT_TRUE(date.isValid());
    date = Date(29, 2, 2000);
    ASSERT_TRUE(date.isValid());
    date = Date(29, 2, 2001);
    ASSERT_FALSE(date.isValid());
    date = Date(31, 4, 2000);
    ASSERT_FALSE(date.isValid());
    date = Date(31, 12, 2000);
    ASSERT_TRUE(date.isValid());
    date = Date(32, 12, 2000);
    ASSERT_FALSE(date.isValid());
    date = Date(31, 0, 2000);
    ASSERT_FALSE(date.isValid());
    date = Date(31, 1, 2000);
    ASSERT_TRUE(date.isValid());
    date = Date(31, 1, -2000);
    ASSERT_FALSE(date.isValid());
}

TEST(DateTest, Serialize)
{
    Date date(1, 1, 2000);
    string serialized = date.serialize();
    ASSERT_EQ(serialized, "1-1-2000");
}

TEST(DateTest, Deserialize)
{
    string serialized = "1-1-2000";
    Date date = Date::deserialize(serialized);
    ASSERT_EQ(date.getDay(), 1);
    ASSERT_EQ(date.getMonth(), 1);
    ASSERT_EQ(date.getYear(), 2000);
}
