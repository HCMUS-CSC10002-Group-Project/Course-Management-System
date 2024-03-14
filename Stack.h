#include <stdexcept>
#include <iostream>

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
    int Size;

    Stack();
    void push(T element);
    T pop();
    T top() const;
    bool isEmpty() const;
    int size() const;
    ~Stack();
};
