#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "grid.hh"
#include "types.hh"

template<Parts p>
class Solver {

  public:
    Solver(const Grid<Plant>& parsedInput) :
        data_(parsedInput) { }
    unsigned int Solve();

  private:
    const Grid<Plant>& data_;

};

#endif