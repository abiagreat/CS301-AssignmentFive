#pragma once
#include <stdexcept>

template <typename T>
class DynamicStack {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* top;

public:
    DynamicStack();
    ~DynamicStack();
    void push(const T& item);
    void pop();
    bool isEmpty() const;
    T peek() const;
};

#include "DynamicStack.cpp" // Include the source file for template instantiation

