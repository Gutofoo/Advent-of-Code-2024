#include <algorithm>
#include <array>
#include <vector>

#include "solver.hh"
#include "types.hh"

template<>
unsigned long Solver<Parts::PART1>::Solve() {

    unsigned long total_cost = 0U;

    // use linear algebra and solve for the one combination of A and B presses that solves each claw machine
    for(const Claw& claw : data_) {

        // the slopes of A and B are horizontally concatenated into a 2x2 matrix
        // Hx = z
        // where H is the 2x2 matrix, x is a vector a A and B button presses, and z is the prize location
        // just invert H 

        // calculate the determinant of the matrix
        const long det = claw.a_.x*claw.b_.y - claw.b_.x*claw.a_.y;
        if (det == 0) continue; // determinant == 0 means no solution to this one

        const long a_presses = (claw.b_.y*claw.prize_.x - claw.b_.x*claw.prize_.y)/det;
        const long b_presses = (claw.a_.x*claw.prize_.y - claw.a_.y*claw.prize_.x)/det;

        // final check: ensure there is an integer answer by making sure these presses get to the prize location
        if(a_presses*claw.a_.x + b_presses*claw.b_.x == claw.prize_.x && a_presses*claw.a_.y + b_presses*claw.b_.y == claw.prize_.y) {
            total_cost += A_TOKEN_COST*a_presses + B_TOKEN_COST*b_presses;
        }
    }

    return total_cost;

}

template<>
unsigned long Solver<Parts::PART2>::Solve() {

    const long PRIZE_POSITION_OFFSET = 10000000000000;

    unsigned long total_cost = 0U;

    // exact same logic as in part 1, only now the prize position is offset in both X and Y
    for(const Claw& claw : data_) {

        const Position offset_prize = {claw.prize_.x+PRIZE_POSITION_OFFSET, claw.prize_.y+PRIZE_POSITION_OFFSET};

        // calculate the determinant of the matrix
        const long det = claw.a_.x*claw.b_.y - claw.b_.x*claw.a_.y;
        if (det == 0) continue; // determinant == 0 means no solution to this one

        const long a_presses = (claw.b_.y*offset_prize.x - claw.b_.x*offset_prize.y)/det;
        const long b_presses = (claw.a_.x*offset_prize.y - claw.a_.y*offset_prize.x)/det;

        // final check: ensure there is an integer answer by making sure these presses get to the prize location
        if(a_presses*claw.a_.x + b_presses*claw.b_.x == offset_prize.x && a_presses*claw.a_.y + b_presses*claw.b_.y == offset_prize.y) {
            total_cost += A_TOKEN_COST*a_presses + B_TOKEN_COST*b_presses;
        }
    }

    return total_cost;

    return 0;

}