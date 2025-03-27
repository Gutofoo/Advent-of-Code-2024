#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "types.hh"

template<Parts p>
class Solver {

  public:
    Solver(const parsed_t& parsedInput) :
        data(parsedInput) { }
    int Solve();

  private:

};

#endif