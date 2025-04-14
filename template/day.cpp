#include <fstream>
#include <iostream>
#include <string>

#include "parser.hh"
#include "solver.hh"
#include "types.hh"

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
    // parser.Print();

    // parsed_t parsedInput = parser.getParsedInput();

    // Solver<Parts::PART1> part_1(parsedInput);
    // Solver<Parts::PART2> part_2(parsedInput);

    // unsigned int part_1_solution = part_1.Solve();
    // unsigned int part_2_solution = part_2.Solve();

    // std::cout << "Part 1: " << part_1_solution << "\n";
    // std::cout << "Part 2: " << part_2_solution << "\n";

    return 0;
}