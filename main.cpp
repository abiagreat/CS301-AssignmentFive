#include <iostream>
#include "DynamicStack.h"

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

