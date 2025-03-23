#include "solver.hh"

#include <algorithm>
#include <map>
#include <vector>

#include "coordinate.hh"
#include "types.hh"

template<>
int Solver<Parts::PART1>::Solve() {

    // First step, organize the data into a map of frequencies to positions
    std::map<frequency, std::vector<Coordinate>> points_per_frequency;

    for (const Antenna& antenna : data_.GetAntennae()) {
        points_per_frequency[antenna.GetFrequency()].push_back(antenna.GetPosition());
    }

    // Calculate antinodes, create a map 
    std::map<frequency, std::vector<Coordinate>> antinodes_per_frequency;
    for (auto it = points_per_frequency.begin(); it != points_per_frequency.end(); it++) {

        const char& current_frequency = it->first;
        const std::vector<Coordinate>& current_antenna_positions = it->second;

        // compare each antenna to each other with the same frequency to compute their antinodes
        for (size_t i = 0; i < current_antenna_positions.size()-1; i++) {
            for (size_t j = i+1; j < current_antenna_positions.size(); j++) {

                const Coordinate& position_a = current_antenna_positions[i];
                const Coordinate& position_b = current_antenna_positions[j];

                const int x_slope = position_b.x_ - position_a.x_;
                const int y_slope = position_b.y_ - position_a.y_;

                const Coordinate antinode_1 = {
                    position_a.x_ - x_slope,
                    position_a.y_ - y_slope
                };
                const Coordinate antinode_2 = {
                    position_b.x_ + x_slope,
                    position_b.y_ + y_slope
                };

                // per antinode, add it to the map if it is within bounds
                if (antinode_1.x_ >= 0 && antinode_1.x_ < data_.GetMaxX() && antinode_1.y_ >= 0 && antinode_1.y_ < data_.GetMaxY()) {
                    antinodes_per_frequency[current_frequency].push_back(antinode_1);
                }
                if (antinode_2.x_ >= 0 && antinode_2.x_ < data_.GetMaxX() && antinode_2.y_ >= 0 && antinode_2.y_ < data_.GetMaxY()) {
                    antinodes_per_frequency[current_frequency].push_back(antinode_2);
                }

            }
        }

    }

    // lastly, take all the antinodes, and count up the unique positions
    std::vector<Coordinate> unique_antinode_positions;
    for (auto it = antinodes_per_frequency.begin(); it != antinodes_per_frequency.end(); it++) {
        for (const Coordinate& current_position : it->second) {
            if (std::none_of(unique_antinode_positions.begin(), unique_antinode_positions.end(),
              [current_position](const Coordinate& input){ return input == current_position; })) {
                unique_antinode_positions.push_back(current_position);
            }
        }
    }

    return unique_antinode_positions.size();

}

template<>
int Solver<Parts::PART2>::Solve() {

    // First step, organize the data into a map of frequencies to positions
    std::map<frequency, std::vector<Coordinate>> points_per_frequency;

    for (const Antenna& antenna : data_.GetAntennae()) {
        points_per_frequency[antenna.GetFrequency()].push_back(antenna.GetPosition());
    }

    // Calculate antinodes, create a map 
    std::map<frequency, std::vector<Coordinate>> antinodes_per_frequency;
    for (auto it = points_per_frequency.begin(); it != points_per_frequency.end(); it++) {

        const char& current_frequency = it->first;
        const std::vector<Coordinate>& current_antenna_positions = it->second;

        // compare each antenna to each other with the same frequency to compute their antinodes
        for (size_t i = 0; i < current_antenna_positions.size()-1; i++) {
            for (size_t j = i+1; j < current_antenna_positions.size(); j++) {

                Coordinate position_a = current_antenna_positions[i];
                Coordinate position_b = current_antenna_positions[j];

                const int x_slope = position_b.x_ - position_a.x_;
                const int y_slope = position_b.y_ - position_a.y_;

                // cycle through antinodes until it goes off the map
                while(true) {

                    const Coordinate antinode = {
                        position_a.x_ + x_slope,
                        position_a.y_ + y_slope
                    };

                    const bool within_bounds = antinode.x_ >= 0 && antinode.x_ < data_.GetMaxX() &&
                                               antinode.y_ >= 0 && antinode.y_ < data_.GetMaxY();

                    // if the antinode is out of bounds, break out of the loop
                    if(!within_bounds) {
                        break;
                    }

                    // if it's within bounds, add it to the list of antinodes
                    antinodes_per_frequency[current_frequency].push_back(antinode);

                    // propagate to the next by resetting the position to the antinode
                    position_a = antinode;

                }

                // cycle through antinodes until it goes off the map
                while(true) {

                    const Coordinate antinode = {
                        position_b.x_ - x_slope,
                        position_b.y_ - y_slope
                    };

                    const bool within_bounds = antinode.x_ >= 0 && antinode.x_ < data_.GetMaxX() &&
                                               antinode.y_ >= 0 && antinode.y_ < data_.GetMaxY();

                    // if the antinode is out of bounds, break out of the loop
                    if(!within_bounds) {
                        break;
                    }

                    // if it's within bounds, add it to the list of antinodes
                    antinodes_per_frequency[current_frequency].push_back(antinode);

                    // propagate to the next by resetting the position to the antinode
                    position_b = antinode;

                }
            }
        }
    }

    // lastly, take all the antinodes, and count up the unique positions
    std::vector<Coordinate> unique_antinode_positions;
    for (auto it = antinodes_per_frequency.begin(); it != antinodes_per_frequency.end(); it++) {
        for (const Coordinate& current_position : it->second) {
            if (std::none_of(unique_antinode_positions.begin(), unique_antinode_positions.end(),
              [current_position](const Coordinate& input){ return input == current_position; })) {
                unique_antinode_positions.push_back(current_position);
            }
        }
    }

    return unique_antinode_positions.size();

}