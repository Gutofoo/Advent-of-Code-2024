#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include <vector>

#include "claw.hh"
#include "types.hh"

template<Parts p>
class Solver {

  public:
    Solver(const std::vector<Claw>& parsedInput) :
        data_(parsedInput) { }
    unsigned long Solve();

  private:
    const std::vector<Claw>& data_;

};

#endif