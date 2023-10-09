#include <iostream>
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
    DynamicStack() : top(nullptr) {}

    ~DynamicStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& item) {
        Node* newNode = new Node{item, top};
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
};

int main() {
    DynamicStack<int> intStack;
    DynamicStack<std::string> stringStack;

    intStack.push(5);
    intStack.push(10);
    intStack.push(15);

    std::cout << "Int Stack Is Empty: " << intStack.isEmpty() << std::endl;

    stringStack.push("Hello");
    stringStack.push("World");

    std::cout << "String Stack Is Empty: " << stringStack.isEmpty() << std::endl;

    while (!intStack.isEmpty()) {
        std::cout << "Popped: " << intStack.top->data << std::endl;
        intStack.pop();
    }

    while (!stringStack.isEmpty()) {
        std::cout << "Popped: " << stringStack.top->data << std::endl;
        stringStack.pop();
    }

    std::cout << "Int Stack Is Empty: " << intStack.isEmpty() << std::endl;
    std::cout << "String Stack Is Empty: " << stringStack.isEmpty() << std::endl;

    return 0;
}
