#include "parser.hh"

#include <iostream>
#include <fstream>
#include <string>

#include "types.hh"

Parser::Parser(std::fstream& input) {

    // This puzzle only has a single line input
    std::string line = "";
    getline(input, line);

    long id = 0;

    bool more_to_process = true;

    while(more_to_process) {

        const std::string files_string = line.substr(0, 1);
        const std::string free_space_string = line.substr(1, 1);

        if(free_space_string.empty()) {
            more_to_process = false;
        }

        const long file = std::stol(files_string);

        // push new blocks for the file
        for(size_t i = 0; i < file; i++) {
            data_.Push_Back(new Block(id));
        }

        // have to increment the ID for the next file
        id++;

        // then push empty space following the file, if there is any
        if(more_to_process) {
            const long free_space = std::stol(free_space_string);
            for(size_t i = 0; i < free_space; i++) {
                data_.Push_Back(nullptr);
            }
            // now process the rest of the line
            line = line.substr(2);
        }

    }


}

void Parser::Print() const {
    data_.Print();
}

const DiskMap& Parser::GetData() const {
    return data_;
}