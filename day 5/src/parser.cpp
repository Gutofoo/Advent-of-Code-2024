#include <array>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

#include "parser.hh"
#include "types.hh"

Parser::Parser(std::fstream& input) {

    std::vector<rule> rules;
    std::vector<update> updates;

    std::string line = "";

    getline(input, line);

    // phase one: parse the page ordering rules
    while(line.compare("") != 0) {

        std::string prereq_string = line.substr(0, line.find("|"));
        std::string page_string = line.substr(line.find("|")+1);

        rules.emplace_back(std::make_pair(std::stoi(prereq_string), std::stoi(page_string)));

        getline(input, line);

    }

    // phase two: parse updates
    while(getline(input, line)) {

        update current_update;

        while(!line.empty()) {

            if(isdigit(line[0])) {
                std::string number = line.substr(0, line.find_first_of(","));
                current_update.push_back(std::stoi(number));
                line = line.substr(number.length());
            } else {
                line = line.substr(1);
            }
        }

        updates.push_back(current_update);

    }

    data_ = {
        rules,
        updates
    };

}

const RulesAndUpdates& Parser::getParsedInput() const {
    return data_;
}

void Parser::print() const {

    for(size_t i = 0; i < data_.rules.size(); i++) {
        std::cout << data_.rules[i].first;
        std::cout << "|";
        std::cout << data_.rules[i].second;
        std::cout << "\n";
    }

    std::cout << "\n";

    for(size_t i = 0; i < data_.updates.size(); i++) {

        for(size_t j = 0; j < data_.updates[i].size()-1; j++) {
            std::cout << data_.updates[i][j];
            std::cout << ",";
        }
        std::cout << data_.updates[i][data_.updates[i].size()-1];
        std::cout << "\n";

    }

}
