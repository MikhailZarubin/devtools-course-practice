// Copyright 2022 Samoiluk Anastasiya

#ifndef MODULES_SAMOILUK_A_STACK_INCLUDE_STACK_H_
#define MODULES_SAMOILUK_A_STACK_INCLUDE_STACK_H_

#include <string>
#include <vector>

template <class T>
class Stack {
    T* mem;
    int size;
    int index;
 public:
    explicit Stack(int _size = 100);
    explicit Stack(const std::vector<T>& data);
    Stack(const Stack& s);
    ~Stack();

    void push(const T& value);
    T pop();

    T getLast();
    T getSize();

    bool isEmpty();
    bool isFull();

    std::string convertToString() const;

    Stack& operator=(const Stack& s);
};

template <class T>
Stack<T>::Stack(int _size) : size(_size) {
    if (size < 0) throw "Negative stack size";
    index = -1;
    mem = new T[size];
}

template <class T>
Stack<T>::Stack(const std::vector<T>& data) : Stack<T>(data.size() * 2) {
    for (const T elem : data) {
        this->push(elem);
    }
}

template <class T>
Stack<T>::Stack(const Stack& s) {
    size = s.size;
    index = s.index;
    mem = new T[size];
    for (int j = 0; j < index + 1; j++)
        mem[j] = s.mem[j];
}

template <class T>
Stack<T>::~Stack() {
    if (mem != nullptr)
        delete[] mem;
}

template <class T>
void Stack<T>::push(const T& value) {
    if (isFull()) throw "isFull";
    index++;
    mem[index] = value;
}

template <class T>
T Stack<T>::pop() {
    if (isEmpty()) throw "isEmpty";
    T value = mem[index];
    index--;
    return value;
}

template <class T>
T Stack<T>::getLast() { return mem[index]; }

template <class T>
T Stack<T>::getSize() { return size; }

template <class T>
bool Stack<T>::isEmpty() { return index < 0; }

template <class T>
bool Stack<T>::isFull() { return index >= size - 1; }

template <class T>
std::string Stack<T>::convertToString() const {
    Stack<T> copyStack(*this);
    std::string result = "";
    while (!copyStack.isEmpty()) {
        result.append(std::to_string(copyStack.pop()) + " ");
    }
    return result;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
    if (&s == this) return *this;
    size = s.size;
    index = s.index;
    delete mem;
    mem = new T[size];
    for (int j = 0; j < index + 1; j++)
        mem[j] = s.mem[j];
    return *this;
}

#endif  // MODULES_SAMOILUK_A_STACK_INCLUDE_STACK_H_
