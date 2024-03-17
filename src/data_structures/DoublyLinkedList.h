// DoublyLinkedList.h
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

using namespace std;

template <typename T>
struct DNode
{
    T data;
    DNode *prev, *next;

    DNode(T data) : data(data), prev(nullptr), next(nullptr) {}
};

template <typename T>
struct DoublyLinkedList
{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void AddToFront(T element);
    void AddToEnd(T element);
    void Remove(T element);
    DNode<T> *Find(T element);
    int Size();
    bool isEmpty();
    void InsertAfter(DNode<T> *node, T element);
    void InsertBefore(DNode<T> *node, T element);
    void RemoveAt(int index);
    T Get(int index) const;
    void Set(int index, T element);
    void Clear();

private:
    DNode<T> *head;
    DNode<T> *tail;
    int size;
};