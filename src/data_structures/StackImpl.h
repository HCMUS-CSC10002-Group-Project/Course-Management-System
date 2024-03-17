#include "Stack.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Constructor: Initializes an empty stack.
template <typename T>
Stack<T>::Stack() : topNode(nullptr), Size(0) {}

// Pushes an element onto the top of the stack.
template <typename T>
void Stack<T>::push(T element)
{
    Node<T> *newNode = new Node<T>(element);
    newNode->next = topNode;
    topNode = newNode;
    Size++;
}

// Pops the top element off the stack and returns it.
template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack is empty");
    }
    Node<T> *temp = topNode;
    T poppedData = temp->data;
    topNode = topNode->next;
    delete temp;
    Size--;
    return poppedData;
}

// Returns the top element of the stack without removing it.
template <typename T>
T Stack<T>::top() const
{
    if (isEmpty())
    {
        throw std::out_of_range("Stack is empty");
    }
    return topNode->data;
}

// Checks if the stack is empty.
template <typename T>
bool Stack<T>::isEmpty() const
{
    return Size == 0;
}

// Returns the number of elements in the stack.
template <typename T>
int Stack<T>::size() const
{
    return Size;
}

// Destructor: Deallocates memory used by the stack.
template <typename T>
Stack<T>::~Stack()
{
    while (topNode != nullptr)
    {
        Node<T> *temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
}
