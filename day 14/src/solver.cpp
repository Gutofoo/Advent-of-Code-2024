#include <cmath>
#include <iostream>
#include <vector>

#include "robot.hh"
#include "solver.hh"
#include "types.hh"

template<>
unsigned int Solver<Parts::PART1>::Solve() {

    // simulate the scene for 100 seconds, or 100 steps
    for(int i = 0; i < 100; i++) {
        for(Robot& robot : robots_) {
            robot.Update();
        }
    }

    // now count up the robots in each quadrant
    return SafetyScore();

}

template<>
unsigned int Solver<Parts::PART2>::Solve() {

    bool tree_found = false;

    const double STD_DEV_THRESHOLD = 9.5;

    double average_safety_score = 0.0;
    double safety_score_variance = 0.0;
    double sum_of_squares = 0.0;

    unsigned int seconds_to_find_tree = 0U;

    while(!tree_found) {

        seconds_to_find_tree++;

        // Update the robots
        for(Robot& robot : robots_) {
            robot.Update();
        }

        double safety_score = static_cast<double>(SafetyScore());

        // recursive average formula
        const double average_safety_score_this_frame = average_safety_score + (1.0/static_cast<double>(seconds_to_find_tree))*(safety_score - average_safety_score);
        
        // recusrive variance
        sum_of_squares += (safety_score - average_safety_score)*(safety_score - average_safety_score_this_frame);

        average_safety_score = average_safety_score_this_frame;
        safety_score_variance = sum_of_squares/static_cast<double>(seconds_to_find_tree);

        // The tree's safety score is a real outlier, > 9.5 sigma from the mean
        // Any lower will trip a false positive in this input set
        if(std::abs(safety_score - average_safety_score) > STD_DEV_THRESHOLD*std::sqrt(safety_score_variance)) {
            tree_found = true;
            // debug
            // Print();
        }

    }

    return seconds_to_find_tree;

}