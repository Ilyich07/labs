#pragma once
#include <stdexcept>

class Stack{
public:
    Stack();
    Stack& operator<<(int const a);
    Stack& operator>> (int &a);
    Stack& operator=(const Stack& other);
    bool operator== (const Stack& other);
    bool operator< (const Stack& other);
    int operator[](int index);
private:
    int capacity;
    int size;
    int* data;
};
