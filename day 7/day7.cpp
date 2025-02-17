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
    }

    Parser parser(input);

    input.close();

    // debug: see what was parsed
    // parser.Print();

    const std::vector<CalibrationEquation>& parsed_input = parser.GetParsedInput();

    Solver<Parts::PART1> part_1(parsed_input);
    Solver<Parts::PART2> part_2(parsed_input);

    int part_1_solution = part_1.solve();
    int part_2_solution = part_2.solve();

    std::cout << "Part 1: " << part_1_solution << "\n";
    std::cout << "Part 2: " << part_2_solution << "\n";

    return 0;
}