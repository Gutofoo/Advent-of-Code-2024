#include <algorithm>
#include <array>
#include <vector>

#include "solver.hh"
#include "types.hh"

template<>
int Solver<parts::PART1>::solve() {

    // sort the two arrays
    std::sort(data[LEFT].begin(), data[LEFT].end());
    std::sort(data[RIGHT].begin(), data[RIGHT].end());

    int sum = 0;
    // traverse the two and sum the difference
    for(size_t i = 0; i < data[LEFT].size(); i++) {
        sum += std::abs(data[RIGHT][i] - data[LEFT][i]);
    }

    return sum;

}

template<>
int Solver<parts::PART2>::solve() {

    // this part does not require the list be sorted!
    int similarity = 0;
    for(size_t i = 0; i < data[LEFT].size(); i++) {
        similarity += data[LEFT][i] * std::count(data[RIGHT].begin(), data[RIGHT].end(), data[LEFT][i]);
    }

    return similarity;

}