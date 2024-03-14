#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Constructor: Initializes an empty linked list.
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}

// Destructor: Deallocates memory used by the linked list.
template <typename T>
LinkedList<T>::~LinkedList()
{
    Clear();
}

// Adds an element to the front of the linked list.
template <typename T>
void LinkedList<T>::AddToFront(T element)
{
    Node<T> *newNode = new Node<T>(element);
    newNode->next = head;
    head = newNode;
    size++;
}

// Adds an element to the end of the linked list.
template <typename T>
void LinkedList<T>::AddToEnd(T element)
{
    if (!head)
    {
        AddToFront(element);
        return;
    }

    Node<T> *newNode = new Node<T>(element);
    Node<T> *current = head;
    while (current->next)
        current = current->next;

    current->next = newNode;
    size++;
}

// Removes the first occurrence of the given element from the linked list.
template <typename T>
void LinkedList<T>::Remove(T element)
{
    if (!head)
        return;

    if (head->data == element)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    Node<T> *current = head;
    while (current->next)
    {
        if (current->next->data == element)
        {
            Node<T> *temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
            return;
        }
        current = current->next;
    }
}

// Finds and returns a pointer to the first occurrence of the given element in the linked list.
template <typename T>
Node<T> *LinkedList<T>::Find(T element)
{
    Node<T> *current = head;
    while (current)
    {
        if (current->data == element)
            return current;

        current = current->next;
    }
    return nullptr;
}

// Returns the number of elements in the linked list.
template <typename T>
int LinkedList<T>::Size() const
{
    return size;
}

// Checks if the linked list is empty.
template <typename T>
bool LinkedList<T>::IsEmpty() const
{
    return size == 0;
}

// Inserts an element after the specified node in the linked list.
template <typename T>
void LinkedList<T>::InsertAfter(Node<T> *node, T element)
{
    if (!node)
        return;

    Node<T> *newNode = new Node<T>(element);
    newNode->next = node->next;
    node->next = newNode;
    size++;
}

// Inserts an element before the specified node in the linked list.
template <typename T>
void LinkedList<T>::InsertBefore(Node<T> *node, T element)
{
    if (!node)
        return;

    if (node == head)
    {
        AddToFront(element);
        return;
    }

    Node<T> *current = head;
    while (current && current->next != node)
        current = current->next;

    if (current)
    {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = node;
        current->next = newNode;
        size++;
    }
}

// Removes the element at the specified index from the linked list.
template <typename T>
void LinkedList<T>::RemoveAt(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    if (index == 0)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return;
    }

    Node<T> *current = head;
    for (int i = 0; i < index - 1; ++i)
        current = current->next;

    Node<T> *temp = current->next;
    current->next = current->next->next;
    delete temp;
    size--;
}

// Returns the element at the specified index in the linked list.
template <typename T>
T LinkedList<T>::Get(int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    Node<T> *current = head;
    for (int i = 0; i < index; ++i)
        current = current->next;

    return current->data;
}

// Clears the linked list, deallocating memory used by all nodes.
template <typename T>
void LinkedList<T>::Clear()
{
    while (head)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}
