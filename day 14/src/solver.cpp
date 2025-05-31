#include <cmath>
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
    unsigned int top_left = 0U;
    unsigned int top_right = 0U;
    unsigned int bottom_left = 0U;
    unsigned int bottom_right = 0U;

    for(const Robot& robot : robots_) {
        const Position& position = robot.GetPosition();

        if(position.x < MAX_WIDTH/2 && position.y < MAX_HEIGHT/2) {
            top_left++;
        } else if(position.x >= (MAX_WIDTH/2) + 1 && position.y < MAX_HEIGHT/2) {
            top_right++;
        }else if(position.x < MAX_WIDTH/2 && position.y >= (MAX_HEIGHT/2) + 1) {
            bottom_left++;
        } else if(position.x >= (MAX_WIDTH/2) + 1 && position.y >= (MAX_HEIGHT/2) + 1) {
            bottom_right++;
        }
    }

    // debug
    // Print();

    return top_left * top_right * bottom_left * bottom_right;


}

template<>
unsigned int Solver<Parts::PART2>::Solve() {

    const double CENTER_X = static_cast<double>(MAX_WIDTH)/2.0;
    const double CENTER_Y = static_cast<double>(MAX_HEIGHT)/2.0;

    double average = 0.0;
    double variance = 0.0;
    double sum_squares_of_differences = 0.0;

    bool tree_found = false;

    unsigned int seconds_to_form_tree = 0UL;

    // get the initial statistical measures
    double average_this_frame = 0.0;
    for(const Robot& robot : robots_) {
        const Position& position = robot.GetPosition();
        // const double radial_position = std::sqrt(static_cast<double>(position.x*position.x) + static_cast<double>(position.y*position.y));
        const double offset_x = static_cast<double>(position.x) - CENTER_X;
        const double offset_y = static_cast<double>(position.y) - CENTER_Y;
        const double radial_position = std::sqrt(static_cast<double>(offset_x*offset_x) + static_cast<double>(offset_y*offset_y));
        average_this_frame += radial_position/static_cast<double>(robots_.size());
    }

    // initialized stats: average is the singular data point, variance is 0.0
    average = average_this_frame;

    while(!tree_found && seconds_to_form_tree < __SIZE_MAX__-2UL) {

        // Update the robots
        for(Robot& robot : robots_) {
            robot.Update();
        }
        seconds_to_form_tree++;

        // number of samples is 1 + the seconds, since the starting frame counts as a sample
         const unsigned int n = seconds_to_form_tree + 1UL;

        // update the stats
        average_this_frame = 0.0;
        for(const Robot& robot : robots_) {
            const Position& position = robot.GetPosition();
            const double offset_x = static_cast<double>(position.x) - CENTER_X;
            const double offset_y = static_cast<double>(position.y) - CENTER_Y;
            const double radial_position = std::sqrt(static_cast<double>(offset_x*offset_x) + static_cast<double>(offset_y*offset_y));
            average_this_frame += radial_position/static_cast<double>(robots_.size());
        }

        // "average_this_frame" is the new datapoint in the set, it is the average of the radial positions of the robots this frame
        // across frames, that value is averaged and varianced to find the outlier
        
        double new_average = average + (average_this_frame - average)/n;

        sum_squares_of_differences += (average_this_frame - average)*(average_this_frame - new_average);

        variance = sum_squares_of_differences/n;

        // get intermediate calculations for the new variance
        // const double first_term = (average_this_frame - new_average)*(average_this_frame - new_average);
        // const double second_term = n*(average - new_average)*(average - new_average);

        // use recursive formula to update the variance
        // variance += first_term + second_term;
        // variance += average*average - new_average*new_average + (average_this_frame*average_this_frame - variance*variance - average*average)/(n+1);

        // now set the running average to the new_average
        average = new_average;

        // now see if this data point is an outlier, >= 3 standard deviations
        tree_found = (average_this_frame >= (6.0*std::sqrt(variance))+average || average_this_frame <= average-(6.0*std::sqrt(variance)));

        std::cout << "rolling average: " << average << "\n";
        std::cout << "rolling variance: " << variance << "\n";
        std::cout << "current frame's value: " << average_this_frame << "\n";
        std::cout << "\n";

        // const double progress = static_cast<double>(seconds_to_form_tree)/static_cast<double>(__SIZE_MAX__-2UL);
        // std::cout << progress << "%" << "\n";

    }

    // debug
    Print();

    return seconds_to_form_tree;

}