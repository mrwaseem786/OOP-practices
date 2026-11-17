#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

class DArray
{
private:
    int *arr{};
    int size{};
    int capacity{};

public:
    DArray();
    void push_back(int);
    DArray & operator=(const DArray &);
    const int* get(int &) const;
    ~DArray();
};

ostream & operator<<(ostream &os, const DArray &);

#endif