// Stack.h
#ifndef STACK_H
#define STACK_H

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
struct Stack
{
    Node<T> *topNode;
    int size;

    Stack();
    void Push(T element);
    T Pop();
    T Top() const;
    bool IsEmpty() const;
    int Size() const;
    ~Stack();
};

#include "StackImpl.h"
#endif // STACK_H