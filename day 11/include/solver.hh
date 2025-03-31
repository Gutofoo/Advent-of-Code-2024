#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "rock.hh"
#include "types.hh"

template<Parts p>
class Solver {

  public:
    Solver(Rock& parsedInput) :
        data_(parsedInput) { }
    int Solve();

  private:
    Rock& data_;

};

#endif