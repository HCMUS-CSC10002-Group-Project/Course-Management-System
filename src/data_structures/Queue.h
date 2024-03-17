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
    int Size;

public:
    Queue();
    void enqueue(T element);
    T dequeue();
    T front();
    bool isEmpty() const;
    int size() const;
    ~Queue();
};