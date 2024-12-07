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
        data.push_back(line);
    }

}

instructions_t Parser::getParsedInput() {
    return data;
}

void Parser::print() const {
    for(size_t i =0; i < data.size(); i++) {
        std::cout << data[i] << "\n";
    }
}
