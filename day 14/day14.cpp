#include <fstream>
#include <iostream>
#include <string>

#include "parser.hh"
#include "solver.hh"
#include "types.hh"

int MAX_WIDTH;
int MAX_HEIGHT;

int main(int argc, char* argv[]) {

    // file to target taken as command line input; default to "example.txt"
    std::string target = (argc > 1) ? argv[1] : "example.txt";

    target = "input/" + target;

    const bool using_example = target.compare("input/example.txt") == 0;

    MAX_WIDTH = (using_example) ? 11 : 101;
    MAX_HEIGHT = (using_example) ? 7 : 103;

    std::fstream input(target.c_str());

    if(!input) {
        std::cerr << "Error: file not found or unable to be opened.\n";
    }

    Parser parser(input);

    input.close();

    // debug: see what was parsed
    // parser.Print();

    const std::vector<Robot> parsed_input = parser.GetData();

    Solver<Parts::PART1> part_1(parsed_input);
    Solver<Parts::PART2> part_2(parsed_input);

    unsigned int part_1_solution = part_1.Solve();

    // unique to this day, part 2 doesn't work on the example at all!
    unsigned int part_2_solution = (using_example) ? 0U : part_2.Solve();

    std::cout << "Part 1: " << part_1_solution << "\n";
    std::cout << "Part 2: " << part_2_solution << "\n";

    return 0;
}