#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "types.hh"

template<parts p>
class Solver {

    public:
        Solver(const report_t& parsedInput) :
            data(parsedInput) { }
        int solve();

        enum safety {
            UNSAFE = 0,
            SAFE = 1
        };

    private:
        report_t data;

        safety determineSafety(const levels_t&);


};

template<parts p>
typename Solver<p>::safety Solver<p>::determineSafety(const levels_t& level) {

    int lastDelta = 0;
    for(size_t i = 1; i < level.size(); i++) {

        // start with the difference between this data point and the last
        int delta = level[i] - level[i-1];

        // no change -> unsafe
        if(delta == 0) {
            return Solver::UNSAFE;
        }

        // change is too big -> unsafe
        if(std::abs(delta) > 3) {
            return Solver::UNSAFE;
        }

        // change is not all increasing or all decreasing -> unsafe
        if(delta*lastDelta < 0) {
            return Solver::UNSAFE;
        }

        lastDelta = delta;

    }

    return Solver::SAFE;

}

#endif