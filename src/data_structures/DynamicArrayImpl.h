#include "DynamicArray.h"
#include <stdexcept>

using namespace std;

// Constructor
template <typename T>
DynamicArray<T>::DynamicArray(int initialCapacity) : capacity(initialCapacity), size(0)
{
    arr = new T[capacity];
}

// Destructor
template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] arr;
}

// Add element to the end of the array
template <typename T>
void DynamicArray<T>::Add(T element)
{
    if (size == capacity)
        Resize(capacity * 2);

    arr[size++] = element;
}

// Insert element at specified index
template <typename T>
void DynamicArray<T>::Insert(int index, T element)
{
    if (index < 0 || index > size)
        throw std::out_of_range("Index out of range");

    if (size == capacity)
        Resize(capacity * 2);

    for (int i = size; i > index; --i)
        arr[i] = arr[i - 1];

    arr[index] = element;
    size++;
}

// Remove element at specified index
template <typename T>
void DynamicArray<T>::Remove(int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    for (int i = index; i < size - 1; ++i)
        arr[i] = arr[i + 1];

    size--;
}

// Get element at specified index
template <typename T>
T DynamicArray<T>::Get(int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    return arr[index];
}

// Get number of elements in the array
template <typename T>
int DynamicArray<T>::Size() const
{
    return size;
}

// Get current capacity of the array
template <typename T>
int DynamicArray<T>::Capacity() const
{
    return capacity;
}

// Resize the array to a new capacity
template <typename T>
void DynamicArray<T>::Resize(int newCapacity)
{
    T *temp = new T[newCapacity];

    for (int i = 0; i < size; ++i)
        temp[i] = arr[i];

    delete[] arr;
    arr = temp;
    capacity = newCapacity;
}

// Removes all elements from the array
template <typename T>
void DynamicArray<T>::Clear()
{
    delete[] arr;
    capacity = 10;
    size = 0;
    arr = new T[capacity];
}

// Returns the index of the element if it exists, otherwise -1
template <typename T>
int DynamicArray<T>::Find(T element) const
{
    for (int i = 0; i < size; ++i)
        if (arr[i] == element)
            return i;

    return -1; // Not found
}

// Checks if the array contains the specified element
template <typename T>
bool DynamicArray<T>::Contains(T element) const
{
    return Find(element) != -1;
}

// Set element at specified index
template <typename T>
void DynamicArray<T>::Set(int index, T element)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");

    arr[index] = element;
}