#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "parser.hh"
#include "types.hh"

Parser::Parser(std::fstream& input) {

    std::string line = "";
    // while(getline(input, line)) {

    // }

    while(!input.eof()) {

        getline(input, line);

        if(line.empty()) continue; // if a break between claw games is reached, skip to the next one

        // parse Button A
        std::string a_x_string = line.substr(line.find("X+")+2, line.find(",")-(line.find("X+")+2));
        std::string a_y_string = line.substr(line.find("Y+")+2);
        Slope a_slope = {std::stoi(a_x_string), std::stoi(a_y_string)};

        getline(input, line);

        // parse Button B
        std::string b_x_string = line.substr(line.find("X+")+2, line.find(",")-(line.find("X+")+2));
        std::string b_y_string = line.substr(line.find("Y+")+2);
        Slope b_slope = {std::stoi(b_x_string), std::stoi(b_y_string)};

        getline(input, line);

        // parse the prize
        std::string prize_x_string = line.substr(line.find("X=")+2, line.find(",")-(line.find("X=")+2));
        std::string prize_y_string = line.substr(line.find("Y=")+2);
        Position prize_position = {std::stoi(prize_x_string), std::stoi(prize_y_string)};

        data_.emplace_back(Claw(a_slope, b_slope, prize_position));

    }

}

void Parser::Print() const {
    for(const Claw& claw : data_) {
        claw.Print();
        std::cout << "\n";
    }
}

const std::vector<Claw>& Parser::GetData() const {
    return data_;
}
