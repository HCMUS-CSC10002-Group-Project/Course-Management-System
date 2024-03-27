#include <gtest/gtest.h>
#include "StringUtils.h"
#include "LinkedList.h"

TEST(StringUtilsTest, Split)
{
    std::string str = "Hello,World,!";
    DynamicArray<std::string> parts = split(str, ',');
    ASSERT_EQ(parts.Size(), 3);
    ASSERT_EQ(parts.Get(0), "Hello");
    ASSERT_EQ(parts.Get(1), "World");
    ASSERT_EQ(parts.Get(2), "!");
}

TEST(StringUtilsTest, Join)
{
    DynamicArray<std::string> parts;
    parts.Add("Hello");
    parts.Add("World");
    parts.Add("!");
    std::string joined = join(parts, ',');
    ASSERT_EQ(joined, "Hello,World,!");
}

TEST(StringUtilsTest, SplitMultipleDelimiter)
{
    std::string str = "Hello,World,1;2;3";
    DynamicArray<std::string> parts = split(str, ',');
    ASSERT_EQ(parts.Size(), 3);
    ASSERT_EQ(parts.Get(0), "Hello");
    ASSERT_EQ(parts.Get(1), "World");
    ASSERT_EQ(parts.Get(2), "1;2;3");
    DynamicArray<std::string> parts2 = split(parts.Get(2), ';');
    ASSERT_EQ(parts2.Size(), 3);
    ASSERT_EQ(parts2.Get(0), "1");
    ASSERT_EQ(parts2.Get(1), "2");
    ASSERT_EQ(parts2.Get(2), "3");
}

TEST(StringUtilsTest, JoinMultipleDelimiter)
{
    DynamicArray<std::string> parts;
    parts.Add("Hello");
    parts.Add("World");
    parts.Add("1;2;3");
    std::string joined = join(parts, ',');
    ASSERT_EQ(joined, "Hello,World,1;2;3");
}

TEST(StringUtilsTest, SplitEmptyString)
{
    std::string str = "";
    DynamicArray<std::string> parts = split(str, ',');
    ASSERT_EQ(parts.Size(), 0);
    LinkedList<std::string> parts2;
    for (int i = 0; i < parts.Size(); i++)
    {
        parts2.AddToEnd(parts.Get(i));
    }
    ASSERT_EQ(parts2.Size(), 0);
}