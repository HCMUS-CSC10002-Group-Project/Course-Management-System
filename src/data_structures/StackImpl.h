#include "Stack.h"
#include <stdexcept>

using namespace std;

// Constructor: Initializes an empty stack.
template <typename T>
Stack<T>::Stack() : topNode(nullptr), size(0) {}

// Pushes an element onto the top of the stack.
template <typename T>
void Stack<T>::Push(T element)
{
    Node<T> *newNode = new Node<T>(element);
    newNode->next = topNode;
    topNode = newNode;
    size++;
}

// Pops the top element off the stack and returns it.
template <typename T>
T Stack<T>::Pop()
{
    if (IsEmpty())
    {
        throw std::out_of_range("Stack is empty");
    }
    Node<T> *temp = topNode;
    T poppedData = temp->data;
    topNode = topNode->next;
    delete temp;
    size--;
    return poppedData;
}

// Returns the top element of the stack without removing it.
template <typename T>
T Stack<T>::Top() const
{
    if (IsEmpty())
    {
        throw std::out_of_range("Stack is empty");
    }
    return topNode->data;
}

// Checks if the stack is empty.
template <typename T>
bool Stack<T>::IsEmpty() const
{
    return size == 0;
}

// Returns the number of elements in the stack.
template <typename T>
int Stack<T>::Size() const
{
    return size;
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
