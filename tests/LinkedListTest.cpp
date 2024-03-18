#include <gtest/gtest.h>
#include "LinkedList.h"
#include <bits/stdc++.h>

using namespace std;

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

INSTANTIATE_TEST_CASE_P(LinkedListTests, LinkedListParameterizedTest, ::testing::Values(make_pair(vector<int>{36, 27, 15, 43, 35, 36, 42, 49}, 7), make_pair(vector<int>{27, 40, 9, 13, 26, 40, 26, 22, 36, 11, 18, 17}, 5), make_pair(vector<int>{30, 12, 23, 17, 35, 29, 2}, 6), make_pair(vector<int>{19, 17, 43, 6, 11, 42, 29, 23}, 3), make_pair(vector<int>{34, 37, 48, 24, 15, 20, 13, 26, 41, 30, 6, 23, 12, 20, 46, 31, 5, 25, 34}, 15), make_pair(vector<int>{5, 46, 29, 13, 7, 24, 45, 32, 45, 14, 17}, 10), make_pair(vector<int>{43, 0, 37, 8, 26, 28, 38, 34, 3, 1, 4, 49, 32, 10}, 4), make_pair(vector<int>{39, 12, 26, 36, 44, 39, 45, 20, 34, 28, 17, 1, 47, 2, 17, 42, 2, 6}, 2), make_pair(vector<int>{36, 41, 15, 39, 44}, 9), make_pair(vector<int>{29, 31, 17, 47, 21, 31, 25, 9, 27, 17, 6, 47, 3, 36, 15}, 6), make_pair(vector<int>{19, 24, 28, 21, 32, 29, 3, 19}, 9), make_pair(vector<int>{8, 15, 40, 49, 46, 23, 18, 45, 46, 1, 21, 5, 29, 38, 14, 28, 41, 0}, 19), make_pair(vector<int>{34}, 4), make_pair(vector<int>{14, 37, 6, 43, 41, 27, 15, 9, 36, 32, 1, 37, 28, 25, 7, 24, 21, 8, 45, 29, 37, 35, 43, 18}, 27), make_pair(vector<int>{11, 28, 29, 26, 4, 43, 13, 13, 38, 6, 40, 4, 18, 28, 38, 19, 17, 17}, 13), make_pair(vector<int>{43, 20, 33, 40, 49, 22, 25, 44, 40, 5, 39, 4, 36, 19, 32, 42, 14, 47, 7, 5, 4, 48, 11, 22}, 16), make_pair(vector<int>{43, 46, 18, 40, 22, 11, 10, 5, 1, 11, 30, 28, 5, 20, 36, 44, 26, 22, 15, 8, 16, 32, 8, 24}, 24), make_pair(vector<int>{24, 0, 36, 2, 49, 29, 0, 18, 21, 23, 31, 31}, 12), make_pair(vector<int>{44, 10, 13, 49, 31, 49, 46, 9}, 11), make_pair(vector<int>{18, 40, 45, 26, 16, 34, 40, 40, 34, 26, 42, 36, 7}, 15), make_pair(vector<int>{29, 18, 37, 12, 48, 22}, 1), make_pair(vector<int>{36, 10, 42, 37, 6, 1, 13, 22, 21}, 9), make_pair(vector<int>{49, 21, 4, 39, 11, 40, 17, 5, 28, 27, 0, 34, 8, 20, 24, 22, 19, 46, 31}, 6), make_pair(vector<int>{42, 22, 22, 0, 25, 35, 22, 49, 40}, 2), make_pair(vector<int>{13, 48, 40, 24, 40, 9, 31, 19, 36, 32, 5, 44, 4, 29, 19, 23, 26, 0, 5, 10, 42, 29, 34}, 9), make_pair(vector<int>{21, 17, 4, 13, 11}, 4), make_pair(vector<int>{9}, 4), make_pair(vector<int>{2, 6}, 4), make_pair(vector<int>{42, 18, 28, 39, 22, 8, 8, 48, 36, 8, 3, 48, 3, 33, 33, 48, 40, 4, 17, 46, 18}, 15), make_pair(vector<int>{46}, 3), make_pair(vector<int>{49, 40, 3, 33, 13, 47, 3, 42, 36, 25, 2, 46, 25, 38, 7, 29, 36, 10, 14, 21, 10, 4}, 17), make_pair(vector<int>{0, 48}, 5), make_pair(vector<int>{44, 47}, 6), make_pair(vector<int>{39, 2, 28, 3, 0, 31, 47, 38, 9, 1, 35, 34, 39, 42, 15, 27, 4, 29}, 1), make_pair(vector<int>{35, 29, 43, 35, 27, 0, 38, 21, 49, 39, 17, 38, 42, 45}, 11), make_pair(vector<int>{29, 40, 32, 40, 41, 19, 26, 32, 11, 42, 10, 17, 23, 11, 31, 9, 40, 25, 46}, 15), make_pair(vector<int>{34, 40}, 5), make_pair(vector<int>{7, 14, 18, 5, 8, 12, 36, 0, 46, 26, 44, 16, 2, 28, 29, 46, 40, 47, 20, 1, 30, 31, 43, 7}, 25), make_pair(vector<int>{36, 14, 5, 12, 40, 12, 29, 10, 19, 39, 24, 5}, 12), make_pair(vector<int>{33, 37, 38, 38, 16, 20, 34, 6, 17, 6, 10, 49, 37, 5, 9, 17, 18, 45, 33, 23}, 8), make_pair(vector<int>{37, 39, 33, 7, 28, 7, 14, 21, 29, 0, 9, 18, 38, 25, 38, 24, 33, 7, 31, 43, 8, 20, 49}, 13), make_pair(vector<int>{19, 13, 22, 44, 23, 47, 31, 12, 32, 40, 42, 41, 7, 15}, 18), make_pair(vector<int>{24, 41, 47, 1, 31, 21, 37}, 8), make_pair(vector<int>{30, 48, 25, 31}, 7), make_pair(vector<int>{2, 31, 39, 46, 4, 38, 30, 18, 21, 20, 12, 12, 29, 27, 35, 36}, 18), make_pair(vector<int>{33}, 5), make_pair(vector<int>{7, 44, 49, 11, 27, 0, 36, 10, 18}, 9), make_pair(vector<int>{49, 44, 11, 5, 34, 41, 25, 5, 14, 39, 18, 43, 18}, 9), make_pair(vector<int>{22, 32, 17, 30, 43, 24, 26}, 1), make_pair(vector<int>{3, 43, 24, 14, 13, 29, 27, 12, 25, 38, 19}, 14), make_pair(vector<int>{44, 17, 46, 35, 37, 41, 3}, 11), make_pair(vector<int>{28, 25, 41, 10, 18, 17, 36, 13, 5, 40, 8, 30, 4, 21, 11, 33, 35, 39, 23, 4, 1, 5, 0}, 24), make_pair(vector<int>{35, 6, 45}, 7), make_pair(vector<int>{20, 17, 26, 13, 27, 46, 31, 15, 10, 36, 5, 20, 18, 11, 42, 32, 46, 29, 21, 20, 34, 22, 27, 34}, 26), make_pair(vector<int>{22, 48, 30, 13, 47, 0, 30, 23}, 6), make_pair(vector<int>{22, 47, 24, 32, 35, 32, 4, 4, 43}, 0), make_pair(vector<int>{40, 28, 9, 12, 12, 33, 41, 48, 23, 24, 22}, 2), make_pair(vector<int>{35, 21, 7, 15}, 0), make_pair(vector<int>{26, 19, 18, 1, 3, 3, 33, 7, 9, 28, 6, 47, 20, 34, 8, 34, 48, 41, 26, 48, 15}, 20), make_pair(vector<int>{39, 9, 6, 10, 16, 24, 9, 39, 0, 28, 9, 3, 31, 14, 38, 39, 26, 17, 47, 23, 37}, 17), make_pair(vector<int>{22, 31, 25, 0, 29, 40, 4}, 6), make_pair(vector<int>{13, 7, 44, 31, 31, 3}, 0), make_pair(vector<int>{32, 31, 37, 15, 46, 25, 4, 22}, 8), make_pair(vector<int>{47}, 4), make_pair(vector<int>{31, 6, 15, 7, 8, 45, 49, 12, 47}, 13), make_pair(vector<int>{4}, 5), make_pair(vector<int>{37, 32, 32, 21, 16, 13, 10, 32, 11}, 7), make_pair(vector<int>{35, 30, 40, 33, 14, 26, 16, 20, 42, 25, 28}, 7), make_pair(vector<int>{40}, 1), make_pair(vector<int>{18, 43, 37, 28, 32, 21, 10, 5, 38, 25}, 5), make_pair(vector<int>{37, 3, 8, 22, 33, 0, 7, 47, 27, 26, 19, 21, 1, 49, 10, 28, 39, 48, 38, 10}, 18), make_pair(vector<int>{40, 26}, 6), make_pair(vector<int>{31, 37}, 4), make_pair(vector<int>{7, 16, 2, 17, 41, 35, 18, 48, 34, 45, 26, 5, 16, 28, 4, 28, 8, 43, 28, 47, 5, 22, 24, 45}, 7), make_pair(vector<int>{47}, 3), make_pair(vector<int>{27, 32, 21, 43, 34, 39, 34, 21, 9, 35, 7, 4}, 6), make_pair(vector<int>{22, 41, 16, 2, 0, 12, 32, 49, 17, 4, 23, 15}, 16), make_pair(vector<int>{14}, 2), make_pair(vector<int>{41, 22, 37, 37, 9, 28, 21, 30, 37, 6, 40, 41, 20}, 0), make_pair(vector<int>{11, 19, 17, 11, 33, 1, 12, 0, 6, 38, 17, 14, 39, 32, 4}, 4), make_pair(vector<int>{29}, 1), make_pair(vector<int>{38, 19, 36, 20, 6, 44, 10, 49, 14, 15, 14, 26}, 5), make_pair(vector<int>{39, 19, 35, 2, 21, 43, 40, 39}, 8), make_pair(vector<int>{23, 14, 35, 48, 45, 27}, 9), make_pair(vector<int>{48, 49, 5, 5, 43, 18, 6, 10}, 9), make_pair(vector<int>{36, 21, 8, 27, 40, 45, 31, 11, 40, 23, 0, 0, 4, 25, 14, 42, 24, 9, 19, 39, 44, 19, 38}, 27), make_pair(vector<int>{33}, 5), make_pair(vector<int>{43, 4, 6, 31, 25, 16, 11, 17}, 4), make_pair(vector<int>{29, 2, 18, 31, 2, 24, 7, 18, 16, 33, 27, 37, 22, 23, 7, 12, 25}, 9), make_pair(vector<int>{46, 18, 41, 3, 26, 24, 30, 43, 35, 48, 5, 30, 29, 9, 48, 10, 12, 24, 19, 30, 41, 2}, 1), make_pair(vector<int>{26, 33, 39, 40, 8}, 3), make_pair(vector<int>{7, 43, 31, 10, 20, 5, 40, 13, 41, 38, 20, 21, 17}, 15), make_pair(vector<int>{30, 43, 45, 49, 24, 38, 4, 36, 19, 32, 19, 10, 23, 30, 33, 13, 37, 29, 44, 49, 49}, 17), make_pair(vector<int>{14, 42, 30, 36, 15, 49, 15, 36, 31, 11, 34, 33, 37, 22}, 18), make_pair(vector<int>{43, 19, 42, 4, 44, 24, 39, 9, 13, 18, 3, 12, 19, 5, 4, 33, 49, 34, 19, 15, 35, 37, 3}, 9), make_pair(vector<int>{37}, 2), make_pair(vector<int>{12, 39, 10, 5, 10, 4, 11, 7, 29, 3, 16, 42}, 8), make_pair(vector<int>{5, 43, 29, 11, 28, 28, 47, 0, 45, 32, 37, 49, 1, 39, 36, 3, 26, 48, 44, 36, 6, 7}, 20), make_pair(vector<int>{14, 21, 20, 30, 16, 44, 4, 23, 37, 33, 34, 17, 12, 31, 17, 9, 15}, 20), make_pair(vector<int>{19, 45, 45, 22, 21, 45, 19, 9}, 6), make_pair(vector<int>{2}, 5), make_pair(vector<int>{25, 43, 22, 41, 39, 27, 16, 28, 12, 0, 46, 24, 33, 13, 36}, 19), make_pair(vector<int>{44, 18, 15, 41, 42, 39, 37, 13, 48, 40, 39, 2, 13, 31, 28, 7, 4, 21, 46, 33}, 13), make_pair(vector<int>{45}, 0), make_pair(vector<int>{22, 26, 34, 8, 25, 6, 2, 45, 22, 46, 39, 11, 33, 3, 11, 25, 42, 16, 39, 24, 44}, 2), make_pair(vector<int>{17, 44, 13, 7, 19}, 0), make_pair(vector<int>{42}, 2), make_pair(vector<int>{29}, 2), make_pair(vector<int>{35, 45, 48}, 3), make_pair(vector<int>{37, 20, 26, 40, 34, 1, 33, 0, 42, 9, 46, 40, 39, 13, 35, 4}, 11), make_pair(vector<int>{14, 23, 1, 49, 1, 30}, 6), make_pair(vector<int>{15, 36, 2, 25}, 0), make_pair(vector<int>{47, 7, 34, 31, 11, 19, 31, 3, 28, 27, 44, 19, 43, 31, 23, 18}, 18), make_pair(vector<int>{43, 38, 38, 44, 20, 30, 48, 36, 18, 2, 13, 48, 45, 10}, 1), make_pair(vector<int>{42, 16, 48, 25}, 0), make_pair(vector<int>{3, 16, 47}, 4), make_pair(vector<int>{22, 16, 36, 12, 9, 27, 0, 3, 47, 32, 3, 35, 1, 7, 48, 49, 4, 11, 6, 34, 3, 25}, 11), make_pair(vector<int>{47, 13, 33}, 3), make_pair(vector<int>{31, 14, 35, 47, 0, 47, 8, 29, 49, 13}, 4), make_pair(vector<int>{16, 14, 35, 25, 15, 36, 30, 26, 42}, 6), make_pair(vector<int>{19, 2, 9, 16}, 1), make_pair(vector<int>{33, 28, 26, 47, 13, 26, 0, 12, 36, 29, 13, 0, 8, 47, 16, 25, 32, 44, 40, 20}, 1), make_pair(vector<int>{15, 44, 49, 34, 46, 8, 3, 12, 3, 36, 42, 32, 34, 7, 10, 34, 19, 46}, 0), make_pair(vector<int>{46, 24, 32, 15, 1, 16, 11, 43, 37}, 13), make_pair(vector<int>{2, 31, 10, 38, 29, 20, 41, 43, 24, 28, 35}, 12), make_pair(vector<int>{42, 20, 46, 13, 16, 11, 0, 15, 37, 34, 32, 40}, 5), make_pair(vector<int>{33, 39, 30, 44, 43, 13, 4, 32, 44, 25, 23, 38, 1, 1, 23, 11, 15, 18}, 2), make_pair(vector<int>{33, 49, 27, 35, 14, 14, 19, 46, 7, 22, 41, 40, 11}, 9), make_pair(vector<int>{7, 36, 43, 39, 31, 20, 14, 21, 21, 18, 46, 34}, 2), make_pair(vector<int>{17, 47, 0, 17, 24, 35, 33, 40, 7, 32, 49, 29, 23, 40}, 15), make_pair(vector<int>{29, 49, 35, 22, 40, 18, 43, 5, 39, 16, 25, 36, 3, 10, 2, 20, 7, 4, 37, 33, 40, 21}, 19), make_pair(vector<int>{5, 27, 28, 28, 19, 20, 27, 48, 20, 13, 21, 10, 33, 16, 17, 23, 32, 42, 11, 35, 3, 13}, 25), make_pair(vector<int>{18, 45, 48, 10, 18, 26, 9, 23, 3, 37, 4, 23}, 4), make_pair(vector<int>{23, 29, 46, 44, 42, 30}, 1), make_pair(vector<int>{5, 47, 4, 16, 34, 9, 31, 42, 23}, 13), make_pair(vector<int>{21, 13, 8, 49, 22, 34, 5, 11, 40, 30, 21, 23, 3}, 8), make_pair(vector<int>{0, 42, 2, 12, 4, 7, 9, 8, 25, 44, 17, 8, 36, 40, 10, 26, 14, 23, 37, 15}, 23), make_pair(vector<int>{20, 9, 13, 0, 32, 36, 4, 33, 8, 6, 27, 10, 18, 31, 19, 28, 41, 46, 24, 8, 5}, 16), make_pair(vector<int>{15}, 3), make_pair(vector<int>{40, 26, 32, 38, 49, 5, 0, 12, 7, 32, 48, 11, 17, 7, 19, 47, 19}, 2), make_pair(vector<int>{39, 18, 20}, 1), make_pair(vector<int>{30, 42, 4, 33, 7, 43, 0, 0, 21, 35, 38, 20, 40, 40, 34, 47, 25}, 21), make_pair(vector<int>{44, 42, 30, 41, 13, 20, 20, 4, 38, 42, 42}, 2), make_pair(vector<int>{34, 35, 8, 44, 30, 8, 44, 2, 45, 34, 22, 37, 25, 7, 35, 2, 42, 48, 46, 36, 30, 40}, 9), make_pair(vector<int>{12}, 4), make_pair(vector<int>{4, 48, 22, 28, 32, 7, 38, 26, 37, 47, 20, 39, 44, 5}, 8), make_pair(vector<int>{32, 23, 19, 36, 15, 17, 34}, 1), make_pair(vector<int>{24, 4, 0, 36, 10, 42, 42, 8, 14, 23, 41, 21, 11, 19, 10, 10, 40, 2, 5, 47, 16, 39, 31, 39}, 4), make_pair(vector<int>{6, 25, 1, 11, 24, 28, 15, 27, 16, 26, 19, 11, 34, 33, 36, 27, 6}, 5), make_pair(vector<int>{16, 10, 39, 20, 17, 36, 36, 8, 17, 27, 16, 36, 35, 43, 37, 46, 19, 17, 12, 46, 34, 40}, 10), make_pair(vector<int>{24, 0, 31, 2, 8, 30, 1, 25, 42, 40, 47, 11, 26, 34, 19, 45, 13, 35, 31, 1}, 5), make_pair(vector<int>{47, 0, 38, 11, 46, 24, 1, 14, 19, 28, 16, 2, 32, 25, 32, 33, 2, 27, 23, 49}, 15), make_pair(vector<int>{35}, 4), make_pair(vector<int>{49, 47, 29, 2, 28, 49, 49, 28, 39, 13, 26, 13, 16, 40, 34, 44, 9, 36, 26, 34, 21}, 19), make_pair(vector<int>{0, 34, 39, 40, 35, 25, 0, 31, 26, 0, 12, 28, 28}, 2), make_pair(vector<int>{8, 3, 44, 34}, 1), make_pair(vector<int>{27, 5, 7, 36, 42, 34, 22, 15, 45, 10, 15}, 8), make_pair(vector<int>{7, 17, 26, 8, 1, 2, 10, 13, 32, 38, 27, 14, 46, 33, 8, 30, 4, 19, 7, 9, 27, 45, 1, 13}, 14), make_pair(vector<int>{10, 29, 35, 42, 31, 43, 12, 7, 3, 13, 12, 13, 28, 46, 1, 6, 10, 49}, 21), make_pair(vector<int>{31, 45, 40, 39, 4, 19, 36, 8, 32, 4, 26, 45, 33, 14, 37, 14, 7, 1, 24}, 2), make_pair(vector<int>{38, 23, 43, 34, 26, 1, 45, 25, 44, 16, 6, 39, 6, 47}, 16), make_pair(vector<int>{34}, 3), make_pair(vector<int>{40, 32, 5, 23, 48, 45, 40, 5, 46, 16}, 12), make_pair(vector<int>{4, 40, 8, 40, 18, 11, 35, 43, 5, 1, 1, 44, 10}, 11), make_pair(vector<int>{38, 35, 47, 48, 25, 31, 6, 0, 29, 1, 42, 34, 49, 10, 1, 14}, 1), make_pair(vector<int>{22, 5, 11, 33, 42, 6, 40, 46, 9, 36, 8, 10, 28, 46, 47, 25, 44, 24}, 4), make_pair(vector<int>{25}, 0), make_pair(vector<int>{19, 21, 5}, 0), make_pair(vector<int>{19, 46, 17, 44, 3, 30, 29, 46, 36, 20, 44, 45, 8, 2, 8, 36, 48, 5, 13, 44, 30, 21, 47, 7}, 27), make_pair(vector<int>{28}, 4), make_pair(vector<int>{8, 3, 29, 7, 22, 25, 10}, 2), make_pair(vector<int>{8, 40, 26, 2}, 6), make_pair(vector<int>{6, 46, 23, 4, 1, 37, 1, 33, 10, 48}, 12), make_pair(vector<int>{0, 21, 0, 8, 31, 6, 37, 38, 28, 12, 1, 33, 18, 9, 23, 45, 14, 11, 32}, 12), make_pair(vector<int>{7, 29, 11, 44, 30, 44, 7}, 6), make_pair(vector<int>{26, 28, 10, 28, 36, 41, 34, 25, 32, 15, 39, 33}, 3), make_pair(vector<int>{44, 23, 5, 10, 35, 39, 33, 44}, 5), make_pair(vector<int>{5, 43, 42, 0, 0, 20, 39, 28, 0, 49, 6, 37}, 3), make_pair(vector<int>{14, 24, 8, 4, 9, 8, 14, 4, 31, 19, 16, 18, 10, 49, 13, 6}, 9), make_pair(vector<int>{49, 5, 20, 1, 27, 11, 29, 28, 12, 36, 17, 5, 29, 33, 29, 39, 37, 39}, 13), make_pair(vector<int>{45, 30, 24}, 3), make_pair(vector<int>{34, 11, 14, 43, 26, 34, 42, 32, 7, 46, 11, 18, 25, 41, 31, 13, 10, 36, 44, 44, 17, 35, 33, 8}, 22), make_pair(vector<int>{3, 15, 13, 17, 14, 48, 30, 30, 41, 6, 14, 35}, 13), make_pair(vector<int>{31, 2, 42, 9, 45, 25, 24, 6, 13, 21, 2, 30, 6, 35, 41, 39, 24, 44, 6, 38, 11, 20, 38}, 17), make_pair(vector<int>{29, 48}, 4), make_pair(vector<int>{38, 42, 0, 42, 34, 9, 38, 11, 35, 46, 24, 6, 48, 6, 13, 35}, 13), make_pair(vector<int>{12, 44, 10, 2}, 5), make_pair(vector<int>{40, 1, 36, 21, 49, 4, 39}, 5), make_pair(vector<int>{39, 34, 32, 0, 22, 43, 36, 18, 19, 42, 18, 26, 7, 3, 25, 13, 15, 19, 25, 19, 27}, 11), make_pair(vector<int>{30, 45, 32, 31, 0, 22, 20, 46, 13}, 8), make_pair(vector<int>{14, 28, 24, 0}, 6), make_pair(vector<int>{44, 18, 22, 4, 22, 47, 17, 39, 19, 43, 9, 48, 4, 20, 28, 0, 5, 9, 0}, 13), make_pair(vector<int>{48, 42, 38, 27, 6, 18}, 2), make_pair(vector<int>{19, 48, 3, 37, 20, 7, 11, 19}, 8), make_pair(vector<int>{40, 21, 14}, 0), make_pair(vector<int>{36}, 2), make_pair(vector<int>{41}, 3), make_pair(vector<int>{22, 9, 26}, 5), make_pair(vector<int>{4, 23, 17, 8, 32, 38, 8, 37, 26, 30, 44, 39, 1, 22, 42, 42, 44, 6, 30, 22, 43, 49, 48, 36}, 4), make_pair(vector<int>{9}, 3)));
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
