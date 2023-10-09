#include <iostream>
#include <fstream>
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
    DynamicStack<char> charStack;

    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    if (!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        charStack.push(ch);
    }

    while (!charStack.isEmpty()) {
        outputFile.put(charStack.top->data);
        charStack.pop();
    }

    inputFile.close();
    outputFile.close();

    std::cout << "File reversed successfully!" << std::endl;

    return 0;
}
