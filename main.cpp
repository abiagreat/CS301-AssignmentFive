// Group 3: Abia Khan and Mario Salinas
// NetID: ac6212 and ry7931 
// CS 301-03 
// 10/10/23


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

    int inputNum;
    while (inputFile >> inputNum) {
        intStack.push(inputNum);
    }

    std::cout << "Int Stack Is Empty: " << intStack.isEmpty() << std::endl;
    outputFile << "Int Stack is Empty: " << intStack.isEmpty() << endl;

    stringStack.push("Hello");
    stringStack.push("World");

    std::cout << "String Stack Is Empty: " << stringStack.isEmpty() << std::endl;
    cout << "String stack is empty: " << stringStack.isEmpty() << endl;

    while (!intStack.isEmpty()) {
        std::cout << "Popped: " << intStack.top->data << std::endl;
        outputFile << "Popped: " << intStack.top->data << endl;
        intStack.pop();
    }

    while (!stringStack.isEmpty()) {
        std::cout << "Popped: " << stringStack.top->data << std::endl;
        outputFile << "Popped: " << stringStack.top->data << endl;
        stringStack.pop();
    }

    std::cout << "Int Stack Is Empty: " << intStack.isEmpty() << std::endl;
    std::cout << "String Stack Is Empty: " << stringStack.isEmpty() << std::endl;


    inputFile.close();
    outputFile.close();
    return 0;
}

