// DynamicArray.h
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

using namespace std;

template <typename T>
struct DynamicArray
{
    T *arr;
    int capacity;
    int size;

    DynamicArray(int initialCapacity = 10); // Constructor
    ~DynamicArray();                        // Destructor

    void Add(T element);
    void Insert(int index, T element);
    void Remove(int index);
    T Get(int index) const;
    int Size() const;
    int Capacity() const;
    void Clear();
    int Find(T element) const;
    bool Contains(T element) const;
    void Set(int index, T element);

private:
    void Resize(int newCapacity);
};

#include "DynamicArrayImpl.h"
#endif // DYNAMIC_ARRAY_H