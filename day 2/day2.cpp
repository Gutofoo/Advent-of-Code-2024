#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
        return 1;
    }

    Parser parser(input);

    input.close();

    // debug: see what was parsed
    // parser.print();

    report_t parsedInput = parser.getParsedInput();

    Solver<parts::PART1> part1(parsedInput);
    Solver<parts::PART2> part2(parsedInput);

    int part1Solution = part1.solve();
    int part2Solution = part2.solve();

    std::cout << "Part 1: " << part1Solution << "\n";
    std::cout << "Part 2: " << part2Solution << "\n";

    return 0;
}