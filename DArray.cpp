
#include "DArray.h"


DArray::DArray()
{
    arr = nullptr;
    size = 0;
    capacity = 0;
}


void DArray::push_back(int num)
{
    if (size == capacity)
    {
        int newCapacity;

        if (capacity == 0)
            newCapacity = 1;
        else
            newCapacity = capacity * 2;

        int* temp = new int[newCapacity];

        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }

        delete[] arr;

        arr = temp;
        capacity = newCapacity;
    }

    arr[size] = num;
    size++;
}

DArray& DArray::operator=(const DArray& rhs)
{
    if (this != &rhs)
    {
        delete[] arr;

        size = rhs.size;
        capacity = rhs.capacity;

        arr = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            arr[i] = rhs.arr[i];
        }
    }

    return *this;
}


const int* DArray::get(int& n) const
{
    n = size;
    return arr;
}
ostream& operator<<(ostream& os, const DArray& obj)
{
    int n;
    const int* p = obj.get(n);

    for (int i = 0; i < n; i++)
    {
        os << p[i] << " ";
    }

    return os;
}


DArray::~DArray()
{
    delete[] arr;
}
