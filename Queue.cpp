#include "Queue.h"

// Constructor: Initializes frontNode, rearNode, and Size
template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), Size(0) {}

// Enqueues an element to the end of the queue
template <typename T>
void Queue<T>::enqueue(T element)
{

    Node<T> *newNode = new Node<T>(element);

    if (isEmpty())
    {
        frontNode = newNode;
    }
    else
    {
        rearNode->next = newNode;
    }

    rearNode = newNode;
    Size++;
}

// Dequeues an element from the front of the queue
template <typename T>
T Queue<T>::dequeue()
{

    if (isEmpty())
    {
        throw std::out_of_range("Queue is empty");
    }

    Node<T> *temp = frontNode;
    T dequeuedData = temp->data;

    frontNode = frontNode->next;

    if (frontNode == nullptr)
    {
        rearNode = nullptr;
    }

    delete temp;
    Size--;
    return dequeuedData;
}

// Returns the data of the element at the front of the queue without removing it
template <typename T>
T Queue<T>::front()
{
    if (isEmpty())
    {
        throw std::out_of_range("Queue is empty");
    }

    return frontNode->data;
}

// Checks if the queue is empty
template <typename T>
bool Queue<T>::isEmpty() const
{
    return Size == 0;
}

// Returns the number of elements in the queue
template <typename T>
int Queue<T>::size() const
{
    return Size;
}

// Destructor: Deallocates memory by deleting all nodes in the queue
template <typename T>
Queue<T>::~Queue()
{
    while (frontNode != nullptr)
    {
        Node<T> *temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
}
