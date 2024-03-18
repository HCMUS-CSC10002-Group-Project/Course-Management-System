#include <gtest/gtest.h>
#include "Stack.h"
#include <bits/stdc++.h>

using namespace std;

class StackParameterizedTest : public ::testing::TestWithParam<pair<vector<int>, int>>
{
};

TEST_P(StackParameterizedTest, ParamTest)
{
    vector<int> initialElements = GetParam().first;
    int elementToAdd = GetParam().second;
    Stack<int> st;
    EXPECT_TRUE(st.IsEmpty());
    EXPECT_EQ(st.Size(), 0);
    for (auto element : initialElements)
    {
        st.Push(element);
    }
    EXPECT_FALSE(st.IsEmpty());
    EXPECT_EQ(st.Size(), initialElements.size());
    st.Push(elementToAdd);
    EXPECT_EQ(st.Size(), initialElements.size() + 1);
    EXPECT_EQ(st.Top(), elementToAdd);
    EXPECT_EQ(st.Pop(), elementToAdd);
    for (int i = 0; i < initialElements.size(); i++)
    {
        EXPECT_EQ(st.Top(), initialElements[initialElements.size() - 1 - i]);
        EXPECT_EQ(st.Pop(), initialElements[initialElements.size() - 1 - i]);
    }
    EXPECT_THROW(st.Top(), out_of_range);
    EXPECT_THROW(st.Pop(), out_of_range);
    EXPECT_TRUE(st.IsEmpty());
}

INSTANTIATE_TEST_SUITE_P(Default, StackParameterizedTest, ::testing::Values(std::make_pair(std::vector<int>{1, 2, 3}, 4), std::make_pair(std::vector<int>{1, 2, 3}, 2), std::make_pair(std::vector<int>{1, 2, 3}, 1), std::make_pair(std::vector<int>{1, 2, 3}, 3), std::make_pair(std::vector<int>{1, 2, 3}, 0), std::make_pair(std::vector<int>{56, 47, 8, 14, 27, 56, 3, 78, 86, 80}, 11), std::make_pair(std::vector<int>{93}, 3), std::make_pair(std::vector<int>{85, 92, 26, 73, 0, 29, 41, 20, 76, 66}, 12), std::make_pair(std::vector<int>{80, 15, 5, 24, 23, 19, 79}, 8), std::make_pair(std::vector<int>{59, 31}, 5), std::make_pair(std::vector<int>{97, 1, 51, 67, 44}, 6), std::make_pair(std::vector<int>{61, 51, 82, 96, 61, 75}, 6), std::make_pair(std::vector<int>{86}, 4), std::make_pair(std::vector<int>{21, 97, 57, 84, 16, 70, 14, 95, 52, 61}, 10), std::make_pair(std::vector<int>{49}, 1), std::make_pair(std::vector<int>{85, 5, 22, 46, 95}, 5), std::make_pair(std::vector<int>{72, 72, 79, 93, 15, 63, 41, 87, 95, 40}, 8), std::make_pair(std::vector<int>{22, 32, 90, 6, 3, 32, 88}, 10), std::make_pair(std::vector<int>{23, 23, 70, 45, 16, 10, 67}, 7), std::make_pair(std::vector<int>{19, 31}, 5), std::make_pair(std::vector<int>{67, 82, 24, 84, 86}, 4), std::make_pair(std::vector<int>{89, 77, 76, 84, 59, 95, 50}, 9), std::make_pair(std::vector<int>{34, 54, 5, 42, 12, 19, 95, 95}, 6), std::make_pair(std::vector<int>{79}, 3), std::make_pair(std::vector<int>{81, 18, 40, 53, 39}, 3), std::make_pair(std::vector<int>{42, 6}, 4), std::make_pair(std::vector<int>{23, 22, 34, 54, 21}, 4), std::make_pair(std::vector<int>{31, 50, 5, 41, 33}, 5), std::make_pair(std::vector<int>{41, 40, 97}, 6), std::make_pair(std::vector<int>{28, 99, 54, 13, 27, 28, 63, 16, 43}, 8), std::make_pair(std::vector<int>{27, 53, 45, 55, 40, 33, 38, 2, 74}, 7), std::make_pair(std::vector<int>{71, 40, 63, 44, 31, 84, 1, 0, 21, 23}, 13), std::make_pair(std::vector<int>{5, 50, 55, 28, 36, 45, 80}, 5), std::make_pair(std::vector<int>{39, 17, 39, 66}, 4)));

TEST(StackTest, EmptyStack)
{
    Stack<int> st;
    EXPECT_TRUE(st.IsEmpty());
    EXPECT_EQ(st.Size(), 0);
    EXPECT_THROW(st.Top(), out_of_range);
    EXPECT_THROW(st.Pop(), out_of_range);
}

TEST(StackTest, OneElement)
{
    Stack<int> st;
    st.Push(1);
    EXPECT_FALSE(st.IsEmpty());
    EXPECT_EQ(st.Size(), 1);
    EXPECT_EQ(st.Top(), 1);
    EXPECT_EQ(st.Pop(), 1);
    EXPECT_TRUE(st.IsEmpty());
    EXPECT_EQ(st.Size(), 0);
    EXPECT_THROW(st.Top(), out_of_range);
    EXPECT_THROW(st.Pop(), out_of_range);
}

TEST(StackTest, MultipleElements)
{
    Stack<int> st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    EXPECT_FALSE(st.IsEmpty());
    EXPECT_EQ(st.Size(), 3);
    EXPECT_EQ(st.Top(), 3);
    EXPECT_EQ(st.Pop(), 3);
    EXPECT_EQ(st.Size(), 2);
    EXPECT_EQ(st.Top(), 2);
    EXPECT_EQ(st.Pop(), 2);
    EXPECT_EQ(st.Size(), 1);
    EXPECT_EQ(st.Top(), 1);
    EXPECT_EQ(st.Pop(), 1);
    EXPECT_TRUE(st.IsEmpty());
    EXPECT_EQ(st.Size(), 0);
    EXPECT_THROW(st.Top(), out_of_range);
    EXPECT_THROW(st.Pop(), out_of_range);
}