#include <gtest/gtest.h>
#include "LinkedList.h"
#include <bits/stdc++.h>

class LinkedListParameterizedTest : public ::testing::TestWithParam<std::pair<std::vector<int>, int>>
{
};

TEST_P(LinkedListParameterizedTest, AddToFront)
{
    std::vector<int> initialElements = GetParam().first;
    int elementToAdd = GetParam().second;
    LinkedList<int> list;
    for (int element : initialElements)
    {
        list.AddToFront(element);
    }
    list.AddToFront(elementToAdd);
    for (int i = 0; i < initialElements.size(); i++)
    {
        EXPECT_EQ(list.Get(i + 1), initialElements[initialElements.size() - 1 - i]);
    }
    EXPECT_EQ(list.Get(0), elementToAdd);
}

TEST_P(LinkedListParameterizedTest, AddToEnd)
{
    std::vector<int> initialElements = GetParam().first;
    int elementToAdd = GetParam().second;
    LinkedList<int> list;
    for (int element : initialElements)
    {
        list.AddToEnd(element);
    }
    list.AddToEnd(elementToAdd);
    for (int i = 0; i < initialElements.size(); i++)
    {
        EXPECT_EQ(list.Get(i), initialElements[i]);
    }
    EXPECT_EQ(list.Get(list.Size() - 1), elementToAdd);
}

TEST_P(LinkedListParameterizedTest, Remove)
{
    std::vector<int> initialElements = GetParam().first;
    int elementToRemove = GetParam().second;
    LinkedList<int> list;
    for (int element : initialElements)
    {
        list.AddToEnd(element);
    }
    list.Remove(elementToRemove);
    if (std::find(initialElements.begin(), initialElements.end(), elementToRemove) == initialElements.end())
    {
        EXPECT_EQ(list.Size(), initialElements.size());
        for (int i = 0; i < list.Size(); i++)
        {
            EXPECT_EQ(list.Get(i), initialElements[i]);
        }
    }
    else
    {
        EXPECT_EQ(list.Size(), initialElements.size() - 1);
        for (int i = 0; i < list.Size(); i++)
        {
            EXPECT_NE(list.Get(i), elementToRemove);
        }
    }
}

TEST_P(LinkedListParameterizedTest, Find)
{
    std::vector<int> initialElements = GetParam().first;
    int elementToFind = GetParam().second;
    LinkedList<int> list;
    for (int element : initialElements)
    {
        list.AddToEnd(element);
    }
    Node<int> *node = list.Find(elementToFind);
    if (std::find(initialElements.begin(), initialElements.end(), elementToFind) == initialElements.end())
    {
        EXPECT_EQ(node, nullptr);
    }
    else
    {
        EXPECT_EQ(node->data, elementToFind);
    }
}

TEST_P(LinkedListParameterizedTest, Size)
{
    std::vector<int> initialElements = GetParam().first;
    LinkedList<int> list;
    for (int element : initialElements)
    {
        list.AddToEnd(element);
    }
    EXPECT_EQ(list.Size(), initialElements.size());
}

TEST_P(LinkedListParameterizedTest, IsEmpty)
{
    std::vector<int> initialElements = GetParam().first;
    LinkedList<int> list;
    EXPECT_TRUE(list.IsEmpty());
    for (int element : initialElements)
    {
        list.AddToEnd(element);
    }
    EXPECT_FALSE(list.IsEmpty());
}

TEST_P(LinkedListParameterizedTest, InsertAfter)
{
    std::vector<int> initialElements = GetParam().first;
    int elementToAdd = GetParam().second;
    LinkedList<int> list;
    for (int element : initialElements)
    {
        list.AddToEnd(element);
    }
    // get random node
    Node<int> *node = list.Find(initialElements[rand() % initialElements.size()]);
    list.InsertAfter(node, elementToAdd);
    EXPECT_EQ(list.Size(), initialElements.size() + 1);
    EXPECT_NE(list.Find(elementToAdd), nullptr);
}

TEST_P(LinkedListParameterizedTest, InsertBefore)
{
    std::vector<int> initialElements = GetParam().first;
    int elementToAdd = GetParam().second;
    LinkedList<int> list;
    for (int element : initialElements)
    {
        list.AddToEnd(element);
    }
    // get random node
    Node<int> *node = list.Find(initialElements[rand() % initialElements.size()]);
    list.InsertBefore(node, elementToAdd);
    EXPECT_EQ(list.Size(), initialElements.size() + 1);
    EXPECT_NE(list.Find(elementToAdd), nullptr);
}

TEST_P(LinkedListParameterizedTest, RemoveAt)
{
    std::vector<int> initialElements = GetParam().first;
    int indexToRemove = GetParam().second;
    LinkedList<int> list;
    for (int element : initialElements)
    {
        list.AddToEnd(element);
    }
    if (indexToRemove < 0 || indexToRemove >= list.Size())
    {
        EXPECT_THROW(list.RemoveAt(indexToRemove), std::out_of_range);
        return;
    }
    list.RemoveAt(indexToRemove);
    EXPECT_EQ(list.Size(), initialElements.size() - 1);
    for (int i = 0; i < list.Size(); i++)
    {
        if (i < indexToRemove)
        {
            EXPECT_EQ(list.Get(i), initialElements[i]);
        }
        else
        {
            EXPECT_EQ(list.Get(i), initialElements[i + 1]);
        }
    }
}

TEST_P(LinkedListParameterizedTest, Get)
{
    std::vector<int> initialElements = GetParam().first;
    LinkedList<int> list;
    for (int element : initialElements)
    {
        list.AddToEnd(element);
    }
    for (int i = 0; i < initialElements.size(); i++)
    {
        EXPECT_EQ(list.Get(i), initialElements[i]);
    }
}

TEST_P(LinkedListParameterizedTest, Set)
{
    std::vector<int> initialElements = GetParam().first;
    int indexToSet = GetParam().second;
    LinkedList<int> list;
    for (int element : initialElements)
    {
        list.AddToEnd(element);
    }
    if (indexToSet < 0 || indexToSet >= list.Size())
    {
        EXPECT_THROW(list.Set(indexToSet, 0), std::out_of_range);
        return;
    }
    list.Set(indexToSet, 0);
    EXPECT_EQ(list.Get(indexToSet), 0);
}

TEST_P(LinkedListParameterizedTest, Clear)
{
    std::vector<int> initialElements = GetParam().first;
    LinkedList<int> list;
    for (int element : initialElements)
    {
        list.AddToEnd(element);
    }
    list.Clear();
    EXPECT_EQ(list.Size(), 0);
    EXPECT_TRUE(list.IsEmpty());
}

INSTANTIATE_TEST_CASE_P(LinkedListTests, LinkedListParameterizedTest, ::testing::Values(std::make_pair(std::vector<int>{1, 2, 3}, 4), std::make_pair(std::vector<int>{1, 2, 3}, 2), std::make_pair(std::vector<int>{1, 2, 3}, 1), std::make_pair(std::vector<int>{1, 2, 3}, 3), std::make_pair(std::vector<int>{1, 2, 3}, 0), std::make_pair(std::vector<int>{56, 47, 8, 14, 27, 56, 3, 78, 86, 80}, 11), std::make_pair(std::vector<int>{93}, 3), std::make_pair(std::vector<int>{85, 92, 26, 73, 0, 29, 41, 20, 76, 66}, 12), std::make_pair(std::vector<int>{80, 15, 5, 24, 23, 19, 79}, 8), std::make_pair(std::vector<int>{59, 31}, 5), std::make_pair(std::vector<int>{97, 1, 51, 67, 44}, 6), std::make_pair(std::vector<int>{61, 51, 82, 96, 61, 75}, 6), std::make_pair(std::vector<int>{86}, 4), std::make_pair(std::vector<int>{21, 97, 57, 84, 16, 70, 14, 95, 52, 61}, 10), std::make_pair(std::vector<int>{49}, 1), std::make_pair(std::vector<int>{85, 5, 22, 46, 95}, 5), std::make_pair(std::vector<int>{72, 72, 79, 93, 15, 63, 41, 87, 95, 40}, 8), std::make_pair(std::vector<int>{22, 32, 90, 6, 3, 32, 88}, 10), std::make_pair(std::vector<int>{23, 23, 70, 45, 16, 10, 67}, 7), std::make_pair(std::vector<int>{19, 31}, 5), std::make_pair(std::vector<int>{67, 82, 24, 84, 86}, 4), std::make_pair(std::vector<int>{89, 77, 76, 84, 59, 95, 50}, 9), std::make_pair(std::vector<int>{34, 54, 5, 42, 12, 19, 95, 95}, 6), std::make_pair(std::vector<int>{79}, 3), std::make_pair(std::vector<int>{81, 18, 40, 53, 39}, 3), std::make_pair(std::vector<int>{42, 6}, 4), std::make_pair(std::vector<int>{23, 22, 34, 54, 21}, 4), std::make_pair(std::vector<int>{31, 50, 5, 41, 33}, 5), std::make_pair(std::vector<int>{41, 40, 97}, 6), std::make_pair(std::vector<int>{28, 99, 54, 13, 27, 28, 63, 16, 43}, 8), std::make_pair(std::vector<int>{27, 53, 45, 55, 40, 33, 38, 2, 74}, 7), std::make_pair(std::vector<int>{71, 40, 63, 44, 31, 84, 1, 0, 21, 23}, 13), std::make_pair(std::vector<int>{5, 50, 55, 28, 36, 45, 80}, 5), std::make_pair(std::vector<int>{39, 17, 39, 66}, 4)));
TEST(LinkedListTest, ConstructorWithNoArguments)
{
    LinkedList<int> list;
    EXPECT_EQ(list.Size(), 0);
}

TEST(LinkedListTest, AddToFront)
{
    LinkedList<int> list;
    list.AddToFront(1);
    list.AddToFront(2);
    list.AddToFront(3);
    EXPECT_EQ(list.Size(), 3);
    EXPECT_EQ(list.Get(0), 3);
    EXPECT_EQ(list.Get(1), 2);
    EXPECT_EQ(list.Get(2), 1);
}

TEST(LinkedListTest, AddToEnd)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    EXPECT_EQ(list.Size(), 3);
    EXPECT_EQ(list.Get(0), 1);
    EXPECT_EQ(list.Get(1), 2);
    EXPECT_EQ(list.Get(2), 3);
}

TEST(LinkedListTest, Remove)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    list.Remove(2);
    EXPECT_EQ(list.Size(), 2);
    EXPECT_EQ(list.Get(0), 1);
    EXPECT_EQ(list.Get(1), 3);
}

TEST(LinkedListTest, Find)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    Node<int> *node = list.Find(2);
    EXPECT_EQ(node->data, 2);
}

TEST(LinkedListTest, Size)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    EXPECT_EQ(list.Size(), 3);
}

TEST(LinkedListTest, IsEmpty)
{
    LinkedList<int> list;
    EXPECT_TRUE(list.IsEmpty());
    list.AddToEnd(1);
    EXPECT_FALSE(list.IsEmpty());
}

TEST(LinkedListTest, InsertAfter)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    Node<int> *node = list.Find(2);
    list.InsertAfter(node, 4);
    EXPECT_EQ(list.Size(), 4);
    EXPECT_EQ(list.Get(2), 4);
}

TEST(LinkedListTest, InsertBefore)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    Node<int> *node = list.Find(2);
    list.InsertBefore(node, 4);
    EXPECT_EQ(list.Size(), 4);
    EXPECT_EQ(list.Get(1), 4);
}

TEST(LinkedListTest, InsertBeforeHead)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    Node<int> *node = list.Find(1);
    list.InsertBefore(node, 4);
    EXPECT_EQ(list.Size(), 4);
    EXPECT_EQ(list.Get(0), 4);
}

TEST(LinkedListTest, InsertBeforeTail)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    Node<int> *node = list.Find(3);
    list.InsertBefore(node, 4);
    EXPECT_EQ(list.Size(), 4);
    EXPECT_EQ(list.Get(2), 4);
}

TEST(LinkedListTest, InsertAfterTail)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    Node<int> *node = list.Find(3);
    list.InsertAfter(node, 4);
    EXPECT_EQ(list.Size(), 4);
    EXPECT_EQ(list.Get(3), 4);
}

TEST(LinkedListTest, InsertAfterHead)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    Node<int> *node = list.Find(1);
    list.InsertAfter(node, 4);
    EXPECT_EQ(list.Size(), 4);
    EXPECT_EQ(list.Get(1), 4);
}

TEST(LinkedListTest, InsertAfterEmpty)
{
    LinkedList<int> list;
    list.InsertAfter(nullptr, 4);
    EXPECT_EQ(list.Size(), 0);
}

TEST(LinkedListTest, InsertAfterNull)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    list.InsertAfter(nullptr, 4);
    EXPECT_EQ(list.Size(), 3);
}

TEST(LinkedListTest, InsertBeforeNull)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    list.InsertBefore(nullptr, 4);
    EXPECT_EQ(list.Size(), 3);
}

TEST(LinkedListTest, RemoveNull)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    list.Remove(4);
    EXPECT_EQ(list.Size(), 3);
}

TEST(LinkedListTest, RemoveHead)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    list.Remove(1);
    EXPECT_EQ(list.Size(), 2);
    EXPECT_EQ(list.Get(0), 2);
    EXPECT_EQ(list.Get(1), 3);
}

TEST(LinkedListTest, RemoveTail)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    list.Remove(3);
    EXPECT_EQ(list.Size(), 2);
    EXPECT_EQ(list.Get(0), 1);
    EXPECT_EQ(list.Get(1), 2);
}

TEST(LinkedListTest, RemoveMiddle)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    list.Remove(2);
    EXPECT_EQ(list.Size(), 2);
    EXPECT_EQ(list.Get(0), 1);
    EXPECT_EQ(list.Get(1), 3);
}

TEST(LinkedListTest, RemoveEmpty)
{
    LinkedList<int> list;
    list.Remove(1);
    EXPECT_EQ(list.Size(), 0);
}

TEST(LinkedListTest, RemoveAt)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    list.RemoveAt(1);
    EXPECT_EQ(list.Size(), 2);
    EXPECT_EQ(list.Get(0), 1);
    EXPECT_EQ(list.Get(1), 3);
}

TEST(LinkedListTest, RemoveAtEmpty)
{
    LinkedList<int> list;
    EXPECT_THROW(list.RemoveAt(0), std::out_of_range);
}

TEST(LinkedListTest, RemoveAtOutofBounds)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    EXPECT_THROW(list.RemoveAt(3), std::out_of_range);
}

TEST(LinkedListTest, RemoveSizeDecrease)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    EXPECT_EQ(list.Size(), 3);
    list.Remove(3);
    EXPECT_EQ(list.Size(), 2);
    EXPECT_EQ(list.Get(0), 1);
    list.RemoveAt(0);
    EXPECT_EQ(list.Size(), 1);
    EXPECT_EQ(list.Get(0), 2);
}

TEST(LinkedListTest, RemoveSizeNotIncrease)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    EXPECT_EQ(list.Size(), 3);
    list.Remove(4);
    EXPECT_EQ(list.Size(), 3);
    EXPECT_THROW(list.RemoveAt(4), std::out_of_range);
    EXPECT_EQ(list.Size(), 3);
}

TEST(LinkedListTest, Get)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    EXPECT_EQ(list.Get(0), 1);
    EXPECT_EQ(list.Get(1), 2);
    EXPECT_EQ(list.Get(2), 3);
}

TEST(LinkedListTest, GetEmpty)
{
    LinkedList<int> list;
    EXPECT_THROW(list.Get(0), std::out_of_range);
    EXPECT_THROW(list.Get(1), std::out_of_range);
    EXPECT_THROW(list.Get(2), std::out_of_range);
}

TEST(LinkedListTest, GetOutofBounds)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    EXPECT_THROW(list.Get(3), std::out_of_range);
}

TEST(LinkedListTest, Set)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    list.Set(1, 4);
    EXPECT_EQ(list.Get(0), 1);
    EXPECT_EQ(list.Get(1), 4);
    EXPECT_EQ(list.Get(2), 3);
    EXPECT_EQ(list.Size(), 3);
}

TEST(LinkedListTest, SetEmpty)
{
    LinkedList<int> list;
    EXPECT_THROW(list.Set(0, 4), std::out_of_range);
}

TEST(LinkedListTest, SetOutofBounds)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    EXPECT_THROW(list.Set(3, 4), std::out_of_range);
}

TEST(LinkedListTest, Clear)
{
    LinkedList<int> list;
    list.AddToEnd(1);
    list.AddToEnd(2);
    list.AddToEnd(3);
    EXPECT_FALSE(list.IsEmpty());
    list.Clear();
    EXPECT_EQ(list.Size(), 0);
    EXPECT_TRUE(list.IsEmpty());
}
