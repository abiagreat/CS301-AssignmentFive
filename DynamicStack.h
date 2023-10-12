#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

#include <stdexcept>
using namespace std;

#include "DynamicStack.cpp" // Include the source file for template instantiation

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
    void push(T item);
    void pop();
    bool isEmpty() const;
    bool isFull() const;
    T peek() const;

    Node* top;
};

template <typename T>
DynamicStack<T>::DynamicStack() {
    top = nullptr;
}

template <typename T>
DynamicStack<T>::~DynamicStack() {
    while (top != nullptr) {
        pop();
    }
}

template <typename T>
void DynamicStack<T>::push(T item) {
    Node* location;
    location = new Node;
    location->data = item;
    location->next = top;
    top = location;
}

template <typename T>
void DynamicStack<T>::pop() {
    Node* temp = top;
    top = top->next;
    delete temp;
}

template <typename T>
bool DynamicStack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
bool DynamicStack<T>::isFull() const {
    try {
        Node* location = new Node;
        delete location;
        return false;
    } catch (bad_alloc exception) {
        return true;
    }
}

template <typename T>
T DynamicStack<T>::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return top->data;
}

#endif

