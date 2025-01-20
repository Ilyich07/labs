#pragma once

template <typename Type>
class Stack {
public:

    Stack() : capacity(10), size(0), data(new Type[10]) {};

    bool isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

    int getSize() {
        return size;
    }

    void pop() {
        if (size == 0) {
            throw std::runtime_error("Stack is empty!");
        }
        --size;
    }

    Type getTop() {
        if (size == 0) {
            throw std::underflow_error("Stack is empty!");
        }
        return data[size - 1];
    }

    Stack<Type>& operator<<(const Type& a) {
        if (size < capacity) {
            data[size] = a;
            ++size;
        }
        if (size == capacity) {
            Type* newData = new Type[capacity + 10];
            for (int i = 0; i < capacity; ++i) {
                newData[i] = data[i];
            }
            newData[size] = a;
            delete[]data;
            this->data = newData;
            this->capacity += 10;
            ++size;
        }
        return *this;
    }


    Stack<Type>& operator>> (Type& a) {
        if (size == 0) {
            throw std::underflow_error("Stack is empty!");
        }
        a = data[size - 1];
        --size;
        return *this;
    }

    Stack<Type>& operator=(const Stack& other) {
        if (this != &other) { 
           delete[] data; 
           data = new Type[other.capacity];
           for (int i = 0; i < other.size; ++i) {
               data[i] = other.data[i];
           } 
           size = other.size; 
           capacity = other.capacity;
        } 
        return *this;
    }


    bool operator== (const Stack& other) {
        if (this->size == other.size) {
            for (int i = 0; i < size; ++i) {
                if (data[i] != other.data[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }


    bool operator< (const Stack& other) {
        if (this->data[0] >= other.data[0] && this->size != 0) {
            return false;
        }
        return true;
    }

    Type operator[](int index) {
        if (index > size || index < size) {
            throw std::invalid_argument("You are out of stack bounds!");
        }
        return data[index - 1];
    }
private:
    int capacity;
    int size;
    Type* data;
};
