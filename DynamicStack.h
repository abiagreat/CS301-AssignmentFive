#pragma once
#include <stdexcept>
#include <string>

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
};

