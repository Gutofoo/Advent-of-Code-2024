#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "parser.hh"
#include "solver.hh"
#include "types.hh"

enum Parts {PART1, PART2};

int main(int argc, char* argv[]) {

    // file to target taken as command line input; default to "example.txt"
    std::string target = (argc > 1) ? argv[1] : "example.txt";

    target = "input/" + target;

    std::fstream input(target.c_str());

    if(!input) {
        std::cerr << "Error: file not found or unable to be opened.\n";
    }

    Parser parser(input);

    input.close();

    // debug: see what was parsed
    // parser.print();

    instructions_t parsedInput = parser.getParsedInput();

    Solver<parts::PART1> part1(parsedInput);
    Solver<parts::PART2> part2(parsedInput);

    int part1Solution = part1.solve();
    int part2Solution = part2.solve();

    std::cout << "Part 1: " << part1Solution << "\n";
    std::cout << "Part 2: " << part2Solution << "\n";




    return 0;
}