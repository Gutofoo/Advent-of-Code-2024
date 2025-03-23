#include "parser.hh"

#include <array>
#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "antenna.hh"
#include "grid.hh"
#include "types.hh"

Parser::Parser(std::fstream& input) {

    std::vector<Antenna> antennae;

    std::string line = "";
    int y = 0;
    int max_x = 0;
    while(getline(input, line)) {
        
        max_x = line.length();
        for(int x = 0; x < max_x; x++) {

            if(line.at(x) != '.') { // found a frequency
                Antenna found_antenna = {line.at(x), {x, y}};
                antennae.push_back(found_antenna);
            }

        }

        y++;

    }

    int max_y = y;

    data_ = Grid(antennae, max_x, max_y);

}

const Grid& Parser::GetData() const {
    return data_;
}

void Parser::Print() const {

    std::vector<std::string> to_print;
    for (size_t y = 0; y < data_.GetMaxY(); y++) {

        std::string line = "";
        for (size_t x = 0; x < data_.GetMaxX(); x++) {
            line += ".";
        }
        to_print.push_back(line);

    }

    const std::vector<Antenna>& antennae = data_.GetAntennae();
    for (const Antenna& antenna : antennae) {
        const Coordinate& coordinate = antenna.GetPosition();
        const long x = coordinate.x_;
        const long y = coordinate.y_;
        to_print[y][x] = antenna.GetFrequency();
    }

    for (size_t y = 0; y < data_.GetMaxY(); y++) {
        std::cout << to_print[y] << "\n";
    }

}
