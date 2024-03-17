// LinkedList.h
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
struct LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void AddToFront(T element);
    void AddToEnd(T element);
    void Remove(T element);
    Node<T> *Find(T element);
    int Size() const;
    bool IsEmpty() const;
    void InsertAfter(Node<T> *node, T element);
    void InsertBefore(Node<T> *node, T element);
    void RemoveAt(int index);
    T Get(int index) const;
    void Clear();

private:
    Node<T> *head;
    int size;
};

#include "LinkedList.tpp"
#endif // LINKED_LIST_H