#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "types.hh"

template<Parts p>
class Solver {

  public:
    Solver(const std::vector<CalibrationEquation>& parsed_input) :
      data_(parsed_input) { }
    int solve();

  private:
    const std::vector<CalibrationEquation>& data_;
    bool ProcessEquation(long result, long argument, Operators operation, std::vector<long> remaining_args);

};

#endif