#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "types.hh"

template<parts p>
class Solver {

    public:
        Solver(const parsed_t& parsedInput) :
            data(parsedInput) { }
        int solve();

    private:
        parsed_t data;

};

#endif