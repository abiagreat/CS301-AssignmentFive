//
// Created by Abia Khan on 10/8/23.
//

#include <iostream>
#include <fstream>
#include "DynamicStack.h"

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
