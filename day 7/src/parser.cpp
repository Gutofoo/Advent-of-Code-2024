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

        // step 1: split on ":" and take the left as the result
        CalibrationEquation current_equation;
        std::string result_string = line.substr(0, line.find(":"));
        current_equation.result = std::stol(result_string);

        // step 2: take the right side of ":" and parse the numbers into the operands
        std::string operands_string = line.substr(line.find(":")+1) + " ";
        while(!operands_string.empty()) {

            if(isdigit(operands_string[0])) {
                std::string number = operands_string.substr(0, operands_string.find_first_of(" "));
                current_equation.operands.push_back(std::stol(number));
                operands_string = operands_string.substr(number.length());
            } else {
                operands_string = operands_string.substr(1);
            }
        }

        // step 3: realize the number of operations is the length of the operands, minus 1
        current_equation.number_of_operations = current_equation.operands.size()-1;

        data_.push_back(current_equation);
    }

}

const std::vector<CalibrationEquation>& Parser::GetParsedInput() const {
    return data_;
}


void Parser::Print() const {
    for(const CalibrationEquation& current_equation : data_) {
        std::cout << current_equation.result << ":";
        for(const int& current_operand : current_equation.operands) {
            std::cout << " " << current_operand;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
