#pragma once
#include <stdexcept>

template <typename T>
class DynamicStack {
private:
    struct Node {
        T data;
        Node* next;
    };

public:
    DynamicStack();
    ~DynamicStack();
    void push(const T& item);
    void pop();
    bool isEmpty() const;
    T peek() const;

    Node* top;
};

#include "DynamicStack.cpp" // Include the source file for template instantiation

