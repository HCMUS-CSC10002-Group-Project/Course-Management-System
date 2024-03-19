// Queue.h
#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
struct Queue
{
private:
    Node<T> *frontNode;
    Node<T> *rearNode;
    int size;

public:
    Queue();
    void EnQueue(T element);
    T DeQueue();
    T Front();
    bool IsEmpty() const;
    int Size() const;
    ~Queue();
};

#include "QueueImpl.h"
#endif // QUEUE_H