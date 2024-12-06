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

        levels_t level;
        while(!line.empty()) {

            if(isdigit(line[0])) {
                std::string number = line.substr(0, line.find_first_of(" "));
                level.push_back(std::stoi(number));
                line = line.substr(number.length());
            } else {
                line = line.substr(1);
            }
        }

        data.push_back(level);

    }

}

report_t Parser::getParsedInput() const {
    return data;
}

void Parser::print() const {
    for(size_t i = 0; i < data.size(); i++) {
        for(size_t j = 0; j < data[i].size(); j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
}
