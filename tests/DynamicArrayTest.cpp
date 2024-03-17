#include "DynamicArray.h"
#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <gtest/gtest-param-test.h>
#include <gtest/gtest-typed-test.h>

using namespace std;

class DynamicArrayParameterizedTest : public ::testing::TestWithParam<pair<vector<int>, int>>
{
};

TEST_P(DynamicArrayParameterizedTest, AddElementToTheEnd)
{
    vector<int> initialElements = GetParam().first;
    int elementToAdd = GetParam().second;
    DynamicArray<int> arr(initialElements.size());
    for (int element : initialElements)
    {
        arr.Add(element);
    }
    arr.Add(elementToAdd);
    for (int i = 0; i < initialElements.size(); i++)
    {
        EXPECT_EQ(arr.Get(i), initialElements[i]);
    }
    EXPECT_EQ(arr.Get(arr.Size() - 1), elementToAdd);
}

TEST_P(DynamicArrayParameterizedTest, RemoveElementAtIndex)
{
    vector<int> initialElements = GetParam().first;
    int indexToRemove = GetParam().second;
    DynamicArray<int> arr(initialElements.size());
    for (int element : initialElements)
    {
        arr.Add(element);
    }
    arr.Remove(indexToRemove);
    for (int i = 0; i < indexToRemove; i++)
    {
        EXPECT_EQ(arr.Get(i), initialElements[i]);
    }
    for (int i = indexToRemove; i < arr.Size(); i++)
    {
        EXPECT_EQ(arr.Get(i), initialElements[i + 1]);
    }
}

TEST_P(DynamicArrayParameterizedTest, InsertElementAtIndex)
{
    vector<int> initialElements = GetParam().first;
    int indexToInsert = GetParam().second;
    DynamicArray<int> arr(initialElements.size());
    for (int element : initialElements)
    {
        arr.Add(element);
    }
    arr.Insert(indexToInsert, 100);
    for (int i = 0; i < indexToInsert; i++)
    {
        EXPECT_EQ(arr.Get(i), initialElements[i]);
    }
    EXPECT_EQ(arr.Get(indexToInsert), 100);
    for (int i = indexToInsert + 1; i < arr.Size(); i++)
    {
        EXPECT_EQ(arr.Get(i), initialElements[i - 1]);
    }
}

TEST_P(DynamicArrayParameterizedTest, FindElement)
{
    vector<int> initialElements = GetParam().first;
    int elementToFind = GetParam().second;
    DynamicArray<int> arr(initialElements.size());
    for (int element : initialElements)
    {
        arr.Add(element);
    }
    int index = arr.Find(elementToFind);
    if (find(initialElements.begin(), initialElements.end(), elementToFind) != initialElements.end())
    {
        EXPECT_EQ(arr.Get(index), elementToFind);
    }
    else
    {
        EXPECT_EQ(index, -1);
    }
}

TEST_P(DynamicArrayParameterizedTest, ClearArray)
{
    vector<int> initialElements = GetParam().first;
    DynamicArray<int> arr(initialElements.size());
    for (int element : initialElements)
    {
        arr.Add(element);
    }
    arr.Clear();
    EXPECT_EQ(arr.Size(), 0);
}

TEST_P(DynamicArrayParameterizedTest, GetElementAtIndex)
{
    vector<int> initialElements = GetParam().first;
    int indexToGet = GetParam().second;
    DynamicArray<int> arr(initialElements.size());
    for (int element : initialElements)
    {
        arr.Add(element);
    }
    if (indexToGet < initialElements.size())
    {
        EXPECT_EQ(arr.Get(indexToGet), initialElements[indexToGet]);
    }
    else
    {
        ASSERT_THROW(arr.Get(indexToGet), std::out_of_range);
    }
}

TEST_P(DynamicArrayParameterizedTest, CapacityIncreasesWhenFull)
{
    vector<int> initialElements = GetParam().first;
    DynamicArray<int> arr(initialElements.size());
    for (int element : initialElements)
    {
        arr.Add(element);
    }
    arr.Add(100);
    EXPECT_EQ(arr.Capacity(), initialElements.size() * 2);
}

TEST_P(DynamicArrayParameterizedTest, CapacityDoesNotIncreaseWhenNotFull)
{
    vector<int> initialElements = GetParam().first;
    DynamicArray<int> arr(initialElements.size());
    for (int element : initialElements)
    {
        arr.Add(element);
    }
    EXPECT_EQ(arr.Capacity(), initialElements.size());
}

TEST_P(DynamicArrayParameterizedTest, ContainsElement)
{
    vector<int> initialElements = GetParam().first;
    int elementToFind = GetParam().second;
    DynamicArray<int> arr(initialElements.size());
    for (int element : initialElements)
    {
        arr.Add(element);
    }
    if (find(initialElements.begin(), initialElements.end(), elementToFind) != initialElements.end())
    {
        EXPECT_TRUE(arr.Contains(elementToFind));
    }
    else
    {
        EXPECT_FALSE(arr.Contains(elementToFind));
    }
}

TEST_P(DynamicArrayParameterizedTest, SizeIncreasesWhenElementAdded)
{
    vector<int> initialElements = GetParam().first;
    int elementToAdd = GetParam().second;
    DynamicArray<int> arr(initialElements.size());
    for (int element : initialElements)
    {
        arr.Add(element);
    }
    arr.Add(elementToAdd);
    EXPECT_EQ(arr.Size(), initialElements.size() + 1);
}

INSTANTIATE_TEST_SUITE_P(Default, DynamicArrayParameterizedTest, ::testing::Values(make_pair(vector<int>{1, 2, 3}, 1), make_pair(vector<int>{1, 2, 3}, 2), make_pair(vector<int>{1, 2, 3}, 0), make_pair(vector<int>{1}, 0), make_pair(vector<int>{1, 2, 3, 4, 5}, 3), make_pair(vector<int>{1, 2, 3, 4, 5}, 4)));
// Test Constructor
TEST(DynamicArrayTest, ConstructsWithInitialCapacity)
{
    DynamicArray<int> arr(5);
    EXPECT_EQ(arr.Capacity(), 5);
    EXPECT_EQ(arr.Size(), 0);
}

// Test Add Method
TEST(DynamicArrayTest, AddsElementToEndOutOfCapacity)
{
    DynamicArray<int> arr(1);
    arr.Add(1);
    arr.Add(2);
    EXPECT_EQ(arr.Get(0), 1);
    EXPECT_EQ(arr.Get(1), 2);
    EXPECT_EQ(arr.Size(), 2);
}

// Test Remove Method
TEST(DynamicArrayTest, RemovesElementAtIndexOutOfRange)
{
    DynamicArray<int> arr;
    arr.Add(1);
    ASSERT_THROW(arr.Remove(1), std::out_of_range);
    EXPECT_EQ(arr.Size(), 1);
    arr.Remove(0);
    EXPECT_EQ(arr.Size(), 0);
    ASSERT_THROW(arr.Remove(0), std::out_of_range);
}

// Test Clear Method
TEST(DynamicArrayTest, ClearsArray)
{
    DynamicArray<int> arr;
    arr.Add(1);
    arr.Clear();
    EXPECT_EQ(arr.Size(), 0);
    arr.Clear();
    EXPECT_EQ(arr.Size(), 0);
}

TEST(DynamicArrayTest, GetReturnsElementAtIndex)
{
    DynamicArray<int> arr;
    arr.Add(1);
    arr.Add(2);
    arr.Add(3);
    EXPECT_EQ(arr.Get(1), 2);
}

TEST(DynamicArrayTest, GetReturnsElementAtIndexOutOfRange)
{
    DynamicArray<int> arr;
    arr.Add(1);
    ASSERT_THROW(arr.Get(1), std::out_of_range);
}

TEST(DynamicArrayTest, CapacityIncreasesWhenFull)
{
    DynamicArray<int> arr(1);
    arr.Add(1);
    arr.Add(2);
    EXPECT_EQ(arr.Capacity(), 2);
}

TEST(DynamicArrayTest, InsertElementAtIndex)
{
    DynamicArray<int> arr;
    arr.Add(1);
    arr.Add(3);
    arr.Insert(1, 2);
    EXPECT_EQ(arr.Get(1), 2);
    EXPECT_EQ(arr.Get(2), 3);
}

TEST(DynamicArrayTest, InsertElementAtIndexOutOfRange)
{
    DynamicArray<int> arr;
    arr.Add(1);
    ASSERT_THROW(arr.Insert(2, 2), std::out_of_range);
}

TEST(DynamicArrayTest, SizeDoesNotIncreaseWhenElementNotFound)
{
    DynamicArray<int> arr;
    arr.Add(1);
    arr.Add(2);
    arr.Add(3);
    EXPECT_THROW(arr.Remove(4), std::out_of_range);
    EXPECT_EQ(arr.Size(), 3);
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}