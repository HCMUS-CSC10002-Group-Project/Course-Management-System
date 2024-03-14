#include "DoublyLinkedList.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

// Destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Clear();
}

// Inserts a new node with the given element after the specified node.
template <typename T>
void DoublyLinkedList<T>::AddToFront(T element)
{
    DNode<T> *newNode = new DNode<T>(element);
    if (!head)
        head = tail = newNode;
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    ++size;
}

// Inserts a new node with the given element after the specified node in the doubly linked list.
template <typename T>
void DoublyLinkedList<T>::AddToEnd(T element)
{
    DNode<T> *newNode = new DNode<T>(element);
    if (!head)
        head = tail = newNode;
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++size;
}

// Finds the first occurrence of the specified element in the doubly linked list
template <typename T>
void DoublyLinkedList<T>::Remove(T element)
{
    DNode<T> *current = head;
    while (current)
    {
        if (current->data == element)
        {
            if (current == head)
            {
                head = head->next;
                if (head)
                    head->prev = nullptr;
            }
            else if (current == tail)
            {
                tail = tail->prev;
                if (tail)
                    tail->next = nullptr;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            --size;
            return;
        }
        current = current->next;
    }
}

// Finds and returns the node containing the specified element
template <typename T>
DNode<T> *DoublyLinkedList<T>::Find(T element)
{
    DNode<T> *current = head;
    while (current)
    {
        if (current->data == element)
            return current;
        current = current->next;
    }
    return nullptr;
}

// Returns the size of the doubly linked list
template <typename T>
int DoublyLinkedList<T>::Size()
{
    return size;
}

// Checks if the doubly linked list is empty
template <typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return size == 0;
}

// Inserts an element after the specified node in the doubly linked list
template <typename T>
void DoublyLinkedList<T>::InsertAfter(DNode<T> *node, T element)
{
    if (!node)
        return;

    DNode<T> *newNode = new DNode<T>(element);
    newNode->next = node->next;
    if (node->next)
        node->next->prev = newNode;
    node->next = newNode;
    newNode->prev = node;
    if (node == tail)
        tail = newNode;
    ++size;
}

// Inserts a new node with the specified element after the given node.
template <typename T>
void DoublyLinkedList<T>::InsertBefore(DNode<T> *node, T element)
{
    if (!node)
        return;

    DNode<T> *newNode = new DNode<T>(element);
    newNode->prev = node->prev;
    if (node->prev)
        node->prev->next = newNode;
    node->prev = newNode;
    newNode->next = node;
    if (node == head)
        head = newNode;
    size++;
}
// Removes the node at the specified index from the doubly linked list.
template <typename T>
void DoublyLinkedList<T>::RemoveAt(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    DNode<T> *current;
    if (index < size / 2)
    {
        current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
    }
    else
    {
        current = tail;
        for (int i = size - 1; i > index; --i)
            current = current->prev;
    }

    if (current == head)
    {
        head = head->next;
        if (head)
            head->prev = nullptr;
    }
    else if (current == tail)
    {
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    delete current;
    size--;
}

// Retrieves the data stored in the node at the specified index in the doubly linked list.
template <typename T>
T DoublyLinkedList<T>::Get(int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    DNode<T> *current;
    if (index < size / 2)
    {
        current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
    }
    else
    {
        current = tail;
        for (int i = size - 1; i > index; --i)
            current = current->prev;
    }
    return current->data;
}

// clears the entire doubly linked list by deallocating memory for each node and resetting the size to zero.
template <typename T>
void DoublyLinkedList<T>::Clear()
{
    while (head)
    {
        DNode<T> *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}
