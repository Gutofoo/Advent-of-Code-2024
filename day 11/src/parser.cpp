#include <iostream>
#include <fstream>
#include <string>

#include "parser.hh"
#include "types.hh"

Parser::Parser(std::fstream& input) {

    std::string line = "";
    getline(input, line);
    while(!line.empty()) {

        if(!isdigit(line[0])) {
            line = line.substr(1);
        }

        std::string number_string = line.substr(0, line.find(" "));
        unsigned long number = stoul(number_string);
        line = line.substr(number_string.length());

        if(data_ != nullptr) {
            data_->Insert(number);
        } else {
            data_ = new Rock(number);
        }

    }

}

Rock& Parser::GetData() const {
    return *data_;
}

void Parser::Print() const {
    if(data_) {
        data_->Print();
        std::cout << "\n";
    }
}
