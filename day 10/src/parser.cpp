#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "grid.hh"
#include "parser.hh"
#include "types.hh"

Parser::Parser(std::fstream& input) {

    std::vector<std::vector<int>> map;
    std::string line = "";
    while(getline(input, line)) {
        std::vector<int> row;
        while(!line.empty()) {
            row.push_back(std::stoi(line.substr(0,1)));
            line = line.substr(1);
        }
        map.push_back(row);
    }
    data_.Set(map);
}

void Parser::Print() const {
    data_.Print();
}

const Grid<int>& Parser::GetData() const {
    return data_;
}