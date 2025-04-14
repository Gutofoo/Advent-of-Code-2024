#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "types.hh"

template<Parts p>
class Solver {

  public:
    Solver(const parsed_t& parsedInput) :
        data_(parsedInput) { }
    unsigned int Solve();

  private:
    const parsed_t& data_;

};

#endif