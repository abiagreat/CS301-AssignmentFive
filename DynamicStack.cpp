#include "DynamicStack.h"

template <typename T>
DynamicStack<T>::DynamicStack() : top(nullptr) {}

template <typename T>
DynamicStack<T>::~DynamicStack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void DynamicStack<T>::push(const T& item) {
    Node* newNode = new Node{item, top};
    top = newNode;
}

template <typename T>
void DynamicStack<T>::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

template <typename T>
bool DynamicStack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
T DynamicStack<T>::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return top->data;
}

