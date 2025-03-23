#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "grid.hh"
#include "types.hh"

template<Parts p>
class Solver {

  public:
    Solver(const Grid& parsedInput) :
      data_(parsedInput) { }
    int Solve();
    void Print();

  private:
    const Grid& data_;

};

#endif