#include <algorithm>
#include <array>
#include <vector>

#include <iostream>

#include "solver.hh"
#include "types.hh"

template<>
int Solver<parts::PART1>::solve() {

    int safeReports = 0;

    for(size_t i = 0; i < data.size(); i++) {
        safeReports += determineSafety(data[i]);
    }

    return safeReports;

}

template<>
int Solver<parts::PART2>::solve() {

    int safereports = 0;

    for(size_t i = 0; i < data.size(); i++) {

        if(determineSafety(data[i]) == SAFE) {
            goto SAFE_REPORT;
        }

        // BRUTE FORCE! Remove elements one at a time and retest the safety
        for(size_t j = 0; j < data[i].size(); j++) {

            // create a new vector
            levels_t newlevel = data[i];
            newlevel.erase(newlevel.begin()+j);

            if(determineSafety(newlevel) == SAFE) {
                goto SAFE_REPORT;
            }

        }

        continue;

SAFE_REPORT:
        safereports++;

    }

    return safereports;

}

