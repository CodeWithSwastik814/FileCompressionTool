#include <iostream>
#include <fstream>
#include <vector>
#include <string>


void compress(const std::string& inputFileName, const std::string& outputFileName) {
    // Read file
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cout << "Failed to open " << inputFileName << '\n';
        return;
    }
    std::string text(
        (std::istreambuf_iterator<char>(inputFile)),
        std::istreambuf_iterator<char>()
    );
    inputFile.close();

    // Compress
    std::vector<char> output;
    int i = 0;
    while (i < (int)text.size()) {
        char c = text[i];
        int count = 0;
        while (i < (int)text.size() && text[i] == c) {
            i++;
            count++;
        }
        output.push_back(c);
        // Supports counts > 9
        std::string cnt = std::to_string(count);
        for (char digit : cnt) {
            output.push_back(digit);
        }
    }

    // Write compressed data
    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cout << "Failed to create " << outputFileName << '\n';
        return;
    }
    for (char c : output) {
        outputFile << c;
    }
    outputFile.close();
    std::cout << "Compression complete.\n";
}


void decompress(const std::string& inputFileName, const std::string& outputFileName) {

    // Read file
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cout << "Failed to open " << inputFileName << '\n';
        return;
    }
    std::string compressed(
        (std::istreambuf_iterator<char>(inputFile)),
        std::istreambuf_iterator<char>()
    );
    inputFile.close();

    // Create output file
    std::ofstream outputFile(outputFileName);

    if (!outputFile) {
        std::cout << "Failed to create " << outputFileName << '\n';
        return;
    }
    int i = 0;
    while (i < (int)compressed.size()) {
        char c = compressed[i++];
        std::string countStr;
        while (i < (int)compressed.size() &&
               std::isdigit(compressed[i])) {
            countStr += compressed[i];
            i++;
               }
        int count = std::stoi(countStr);
        for (int j = 0; j < count; j++) {
            outputFile << c;
        }
    }

    outputFile.close();
    std::cout << "Decompression complete.\n";
}



int main() {
    int choice;

    std::cout << "Enter Given Number :";
    std::cout << "\n 1 for Compress \n 2 for Decompress \n 3 for Exit \n";
    std::cout << "Enter Choice : ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            compress("input.txt", "output.swastik");
            break;
        case 2:
            decompress("output.swastik", "Input2.txt");
            break;
        case 3:
            std::cout << "Exiting...\n";
            break;

        default:
            std::cout << "Invalid Choice!\n";
    }
    return 0;
}