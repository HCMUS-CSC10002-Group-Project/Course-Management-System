#include "DynamicArray.h"
#include <gtest/gtest.h>

// Test Constructor
TEST(DynamicArrayTest, ConstructsWithInitialCapacity)
{
    DynamicArray<int> arr(5);
    EXPECT_EQ(arr.Capacity(), 5);
    EXPECT_EQ(arr.Size(), 0);
}

// Test Add Method
TEST(DynamicArrayTest, AddsElementToTheEnd)
{
    DynamicArray<int> arr;
    arr.Add(1);
    EXPECT_EQ(arr.Get(0), 1);
    EXPECT_EQ(arr.Size(), 1);
}

// Test Remove Method
TEST(DynamicArrayTest, RemovesElementAtIndex)
{
    DynamicArray<int> arr;
    arr.Add(1);
    arr.Add(2);
    arr.Remove(0);
    EXPECT_EQ(arr.Get(0), 2);
    EXPECT_EQ(arr.Size(), 1);
}

// Test Clear Method
TEST(DynamicArrayTest, ClearsArray)
{
    DynamicArray<int> arr;
    arr.Add(1);
    arr.Clear();
    EXPECT_EQ(arr.Size(), 0);
}

// ...Continue writing tests for the other methods
