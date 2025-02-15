#include <array>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "parser.hh"
#include "types.hh"

Parser::Parser(std::fstream& input) {

    std::string line = "";

    while(getline(input, line)) {

        std::vector<GridItem> row;
        for(const char& c : line) {
            row.push_back(CHAR_TO_GRID_MAP.at(c));
        }

        grid_.push_back(row);

    }

}

void Parser::print() const {
    for(size_t y = 0; y < grid_.size(); y++) {
        for(size_t x = 0; x < grid_[y].size(); x++) {
            std::cout << GRID_TO_CHAR_MAP.at(grid_[y][x]);
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

const std::vector<std::vector<GridItem>>& Parser::GetParsedInput() const {
    return grid_;
}