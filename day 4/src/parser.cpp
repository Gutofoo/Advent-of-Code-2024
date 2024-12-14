#include <array>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "parser.hh"
#include "types.hh"
#include "wordsearch.hh"

Parser::Parser(std::fstream& input) {

    std::string line = "";

    while(getline(input, line)) {

        std::vector<XMAS> row;
        for(const char& c : line) {
            row.push_back(CHAR_TO_XMAS_MAP.at(c));
        }

        grid.push_back(row);

    }

}

std::vector<std::vector<XMAS>> Parser::getParsedInput() {
    return grid;
}

void Parser::print() const {
    for(size_t y = 0; y < grid.size(); y ++) {
        for(size_t x = 0; x < grid[0].size(); x++) {
            std::cout << XMAS_TO_CHAR_MAP.at(grid[y][x]);
        }
        std::cout << "\n";
    }
}
