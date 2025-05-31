#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include <algorithm>
#include <iostream>
#include <string>

#include "robot.hh"
#include "types.hh"

template<Parts p>
class Solver {

  public:
    Solver(const std::vector<Robot>& parsedInput) :
        robots_(parsedInput) { }
    unsigned int Solve();

  private:
    std::vector<Robot> robots_;
    void Print() const;

};

template<Parts p>
void Solver<p>::Print() const {

    struct MutiplicityPosition {
        Position pos;
        int multiplicty = 0;
    };

    std::vector<MutiplicityPosition> position_counts;

    for(const Robot& robot : robots_) {

        const Position& position = robot.GetPosition();

        auto comp = [position](const MutiplicityPosition& key) { return key.pos.x == position.x && key.pos.y == position.y; };

        if(std::any_of(position_counts.begin(), position_counts.end(), comp)) {
            // find the matching position, increment its multiplicty
            for(MutiplicityPosition& key : position_counts) {
                if(comp(key)) {
                    key.multiplicty++;
                    break;
                }
            }
        } else {
            // otherwise, add a new unique position of multiplicity 1
            MutiplicityPosition unique_position = {position, 1};
            position_counts.push_back(unique_position);
        }

    }

    std::vector<std::string> print_frame;
    for(int y = 0; y < MAX_HEIGHT; y++) {
        std::string line = "";
        for(int x = 0; x < MAX_WIDTH; x++) {
            line.append(".");
        }
        print_frame.push_back(line);
    }

    for(const MutiplicityPosition& key : position_counts) {
        std::string multiplicty_string = std::to_string(key.multiplicty);
        const char to_print = (key.multiplicty > 9) ? '+' : multiplicty_string[0];
        print_frame[key.pos.y][key.pos.x] = to_print;
    }

    for(int y = 0; y < MAX_HEIGHT; y++) {
        std::cout << print_frame[y] << "\n";
    }
    std::cout << "\n";

}

#endif