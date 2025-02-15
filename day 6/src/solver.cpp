#include <algorithm>
#include <array>
#include <iostream>
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

    // First, simulate the original scene and create a list of places visited by the Guard
    std::vector<Coordinate> visited_locations;
    Scene original_scene = Scene(scene_);
    while(!original_scene.EndConditionReached()) {
        // Check the guard's position and update the list of unique locations
        const Coordinate guard_position = original_scene.ReportGuardPosition();
        // check if the location to be added has not already been added
        if(!std::any_of(visited_locations.begin(), visited_locations.end(), [guard_position](Coordinate input) { return input == guard_position; })) {
            visited_locations.push_back(guard_position);
        }
        original_scene.Update();
    }

    // create a list of all the Coordinates with a potential new obstacle to test
    std::vector<Coordinate> new_obstacles;
    const std::vector<Coordinate>& original_obstacles = scene_.GetObstacles();
    for(unsigned long y = 0; y < scene_.GetMaxY(); y++) {
        for(unsigned long x = 0; x < scene_.GetMaxX(); x++) {
            Coordinate current_coordinate = {x, y};
            // filter out obstacles that are already in the scene OR that are the original position of the guard
            if(std::any_of(original_obstacles.begin(), original_obstacles.end(), [current_coordinate](const Coordinate& input) { return current_coordinate == input; })
              || current_coordinate == scene_.ReportGuardPosition()) {
                continue;
            }
            // only test this location if it would impede the Guard's movement
            if(std::any_of(visited_locations.begin(), visited_locations.end(), [current_coordinate](const Coordinate& input){ return current_coordinate == input; })) {
                new_obstacles.push_back(current_coordinate);
            }
        }
    }

    // debug: print total cases to test
    // int total_test_cases = new_obstacles.size();
    // std::cout << "Total test cases: " << total_test_cases << "\n";
    // int cases_remaining = total_test_cases;
    // std::string cases_remaining_string = "";

    // now, loop over the new obstacles and test them
    int new_obstruction_positions = 0;
    for(const Coordinate& new_obstacle : new_obstacles) {

        // debug: print how many remain
        // std::cout << "\r";
        // for(size_t i = 0; i < cases_remaining_string.size(); i++) {
        //     std::cout << " ";
        // }
        // std::cout << "\r";
        // cases_remaining_string = "Cases remaining: " + std::to_string(cases_remaining);
        // std::cout << cases_remaining_string << std::flush;

        // construct a new list of obstacles that includes the current one under test
        std::vector<Coordinate> obstacles_under_test = original_obstacles;
        obstacles_under_test.push_back(new_obstacle);

        // construct a new Scene with this modified list and the original Guard
        Scene scene_under_test = Scene(scene_.GetMaxX(), scene_.GetMaxY(), obstacles_under_test, scene_.ReportGuardState());

        std::vector<GuardState> guard_states;
        while(!scene_under_test.EndConditionReached()) {

            // check that the current guard state has not already been visited
            const GuardState current_guard_state = scene_under_test.ReportGuardState();

            // if the current state has already been visited, the Guard is stuck in a loop!
            //   increment the total obstructions, and continue to the next scene to test
            if(std::any_of(guard_states.begin(), guard_states.end(),
              [current_guard_state](const GuardState& input){ return current_guard_state.position == input.position && current_guard_state.heading == input.heading; })) {
                new_obstruction_positions++;
                break; // break out of the while loop only
            }

            // otherwise, add the current guard state to the list of previous states
            guard_states.push_back(current_guard_state);

            // and then update the scene
            scene_under_test.Update();

        }
        // debug
        // cases_remaining--;
    }
    std::cout << "\n\n";

    return new_obstruction_positions;
}