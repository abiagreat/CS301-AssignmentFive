#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "DynamicStack.h"
#include "DynamicStack.cpp"

int main() {
    string inputFileName, outputFileName;
    ifstream inputFile;
    ofstream outputFile;
    string command;        // operation to be executed

    DynamicStack<int> intStack;
    DynamicStack<string> stringStack;
    DynamicStack<string> charStack;

    inputFileName = "input.txt";
    inputFile.open(inputFileName.c_str());

    outputFileName = "output.txt";
    outputFile.open(outputFileName.c_str());

    if (!inputFile.good()) {
        cout << "I/O error. Can't find the input file! \n";
        exit(2);
    }

    intStack.push(5);
    intStack.push(10);
    intStack.push(15);

    std::cout << "Int Stack Is Empty: " << intStack.isEmpty() << std::endl;

    stringStack.push("Hello");
    stringStack.push("World");

    std::cout << "String Stack Is Empty: " << stringStack.isEmpty() << std::endl;

    while (!intStack.isEmpty()) {
        std::cout << "Popped: " << intStack.top->data << std::endl;
        outputFile << "Popped: " << intStack.top->data << endl;
        intStack.pop();
    }

    while (!stringStack.isEmpty()) {
        std::cout << "Popped: " << stringStack.top->data << std::endl;
        stringStack.pop();
    }

    std::cout << "Int Stack Is Empty: " << intStack.isEmpty() << std::endl;
    std::cout << "String Stack Is Empty: " << stringStack.isEmpty() << std::endl;


    inputFile.close();
    outputFile.close();
    return 0;
}

