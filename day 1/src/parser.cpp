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
        std::string left = line.substr(0, line.find_first_of(" ")+1);
        std::string right = line.substr(line.find_last_of(" ")+1);

        lists[LEFT].push_back(std::stoi(left));
        lists[RIGHT].push_back(std::stoi(right));
    }

}

void Parser::print() const {

    std::cout << "Left parsed list:\n";
    for(size_t i = 0; i < lists[LEFT].size(); i++) {
        std::cout << lists[LEFT][i] << "\n";
    }
    std::cout << "Right parsed list:\n";
    for(size_t i = 0; i < lists[RIGHT].size(); i++) {
        std::cout << lists[RIGHT][i] << "\n";
    }

}

parsed_t Parser::getParsedInput() const {
    return lists;
}