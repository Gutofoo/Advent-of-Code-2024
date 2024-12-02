// Advent of Code 2024

#include <iostream>
#include <string>
#include <fstream>

enum Parts {PART1, PART2};

int main(int argc, char* argv[]) {

    // file to target taken as command line input; default to "example.txt"
    const char* target = (argc > 1) ? argv[1] : "example.txt";

    std::fstream input(target);

    if(!input) {
        std::cerr << "Error: file not found or unable to be opened.\n";
    }

    input.close();

    return 0;
}