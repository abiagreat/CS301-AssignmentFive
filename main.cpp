#include <iostream>
#include <fstream>
#include <stack>
#include <string>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Cannot open input file." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error: Cannot open output file." << std::endl;
        return 1;
    }

    std::stack<char> charStack;
    char ch;

    // Read characters from the input file and push them onto the stack
    while (inputFile.get(ch)) {
        charStack.push(ch);
    }

    // Pop characters from the stack and write them to the output file
    while (!charStack.empty()) {
        ch = charStack.top();
        charStack.pop();
        outputFile << ch;
    }

    std::cout << "File reversed and saved successfully." << std::endl;

    // Close the file streams
    inputFile.close();
    outputFile.close();

    return 0;
}
