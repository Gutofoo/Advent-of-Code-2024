#include <array>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "parser.hh"
#include "types.hh"

Parser::Parser(std::fstream& input) {

    std::vector<std::vector<Plant>> map;
    std::string line = "";
    while(getline(input, line)) {
        std::vector<Plant> row;
        while(!line.empty()) {
            row.push_back(line[0]);
            line = line.substr(1);
        }
        map.push_back(row);
    }
    data_.Set(map);
}

void Parser::Print() const {
    data_.Print();
}

const Grid<Plant>& Parser::GetData() const {
    return data_;
}