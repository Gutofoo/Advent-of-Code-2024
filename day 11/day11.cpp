#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "parser.hh"
#include "rock.hh"
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
    parser.Print();

    Rock& data = parser.GetData();

    Solver<Parts::PART1> part_1(data);
    Solver<Parts::PART2> part_2(data);

    int part_1_solution = part_1.Solve();
    int part_2_solution = part_2.Solve();

    std::cout << "Part 1: " << part_1_solution << "\n";
    std::cout << "Part 2: " << part_2_solution << "\n";

    return 0;
}