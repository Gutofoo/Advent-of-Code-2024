#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "scene.hh"
#include "types.hh"

#include <iostream>
#include <string>
#include <vector>

template<parts p>
class Solver {

  public:
    Solver(const std::vector<std::vector<GridItem>>& grid_input) :
      scene_(grid_input) { }
    int solve();

  private:

    void Print(const std::vector<Coordinate> visited_locations) const;

    Scene scene_;


};

template<parts p>
void Solver<p>::Print(const std::vector<Coordinate> visited_locations) const {

    std::vector<std::string> scene_string = scene_.ToString();
    const Coordinate& guard_location = scene_.ReportGuardPosition();

    // First, mark all the visited locations with 'X'
    for(size_t i = 0; i < visited_locations.size(); i++) {
        const Coordinate& current_location = visited_locations[i];
        if(current_location == guard_location) {
            continue;
        }
        scene_string[current_location.y_][current_location.x_] = 'X';
    }

    // now print the scene
    for(size_t i = 0; i < scene_string.size(); i++) {
        std::cout << scene_string[i] << "\n";
    }
    std::cout << "\n";

}

#endif