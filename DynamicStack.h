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

public:
    DynamicStack();

    [[noreturn]] ~DynamicStack();
    void push(const T& item);
    void pop();
    bool isEmpty() const;

    Node* top;
};
