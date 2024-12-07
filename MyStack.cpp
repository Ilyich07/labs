#include "MyStack.h"

    Stack::Stack() : capacity(10), size(0), data(new int[10]){}

    Stack& Stack::operator<<(int const a){
        if(size < capacity){
            data[size] = a;
            ++size;
        }
        if (size == capacity){
            int* newData = new int[capacity + 10];
            for(int i = 0; i < capacity; ++i){
                newData[i] = data[i];
            }
            newData[size] = a;
            delete []data;
            this->data = newData;
            this->capacity += 10;
            ++size;
        }
        return *this;
    }

    Stack& Stack::operator>> (int &a){
        if (size == 0){
            throw std::underflow_error("Stack is empty!");
        }
        --size;
        a = data[size];
        return *this;
    }

    int Stack::operator[](int index){
        return data[index-1];
    }

    Stack& Stack::operator=(const Stack& other){
        if(&other == this){
            return *this;
        }
        delete[]data;
        int* newData = new int[other.capacity];
        for(int i = 0; i < other.size; ++i){
            newData[i] = other.data[i];
        }
        this->data = newData;
        this->size = other.size;
        this->capacity = other.capacity;
        return *this;
    }

    bool Stack::operator== (const Stack& other){
        if (this->size == other.size){
            for(int i = 0; i < size; ++i){
                if(data[i] != other.data[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool Stack::operator< (const Stack& other){
        if(this->data[0] >= other.data[0]){
            return false;
        }
        return true;
    }