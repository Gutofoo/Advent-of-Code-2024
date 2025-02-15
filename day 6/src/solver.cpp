#include <algorithm>
#include <array>
#include <vector>

#include "solver.hh"
#include "types.hh"

template<>
int Solver<parts::PART1>::solve() {

    std::vector<Coordinate> visited_locations;

    while(!scene_.EndConditionReached()) {

        // Check the guard's position and update the list of unique locations
        const Coordinate guard_position = scene_.ReportGuardPosition();

        // check if the location to be added has not already been added
        if(!std::any_of(visited_locations.begin(), visited_locations.end(), [guard_position](Coordinate input) { return input == guard_position; })) {
            visited_locations.push_back(guard_position);
        }

        scene_.Update();

        // debug: print the current state of the scene
        // Print(visited_locations);

    }

    return visited_locations.size();

}

template<>
int Solver<parts::PART2>::solve() {

    // create a list of all the Coordinates with a potential new obstacle to test
    std::vector<Coordinate> new_obstacles;
    for(unsigned long y = 0; y < scene_.GetMaxY(); y++) {
        for(unsigned long x = 0; x < scene_.GetMaxX(); x++) {
            
        }
    }


    return 0;
}