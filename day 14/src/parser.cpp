#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "parser.hh"
#include "types.hh"

Parser::Parser(std::fstream& input) {

    std::string line = "";
    while(getline(input, line)) {

        std::string position_string = line.substr(0, line.find(" "));
        std::string velocity_string = line.substr(line.find(" ")+1);

        std::string pos_x_string = position_string.substr(position_string.find("p=")+2, position_string.find(",")-(position_string.find("p=")+2));
        std::string pos_y_string = position_string.substr(position_string.find(",")+1);

        std::string vel_x_string = velocity_string.substr(velocity_string.find("v=")+2, velocity_string.find(",")-(velocity_string.find("v=")+2));
        std::string vel_y_string = velocity_string.substr(velocity_string.find(",")+1);

        const Position parsed_position = {stoi(pos_x_string), stoi(pos_y_string)};
        const Velocity parsed_velocity = {stoi(vel_x_string), stoi(vel_y_string)};

        data_.emplace_back(Robot(parsed_position, parsed_velocity));

    }

}

void Parser::Print() const {
    for(const Robot& robot : data_) {
        robot.Print();
    }
    std::cout << "\n";
}

const std::vector<Robot>& Parser::GetData() const {
    return data_;
}
