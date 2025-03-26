#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "grid.hh"
#include "types.hh"

template<Parts p>
class Solver {

  public:
    Solver(const Grid<int>& parsedInput) :
      data_(parsedInput) { }
    int solve();

  private:
    int TrailScore(size_t x, size_t y); // wrapper function for both parts, specialized uniquely per part
    // note: visited Grid must be of type int because of shenanigans with std::vector<bool> causing issues with references
    // treat it as if it were Grid<bool>
    int TrailScore(size_t x, size_t y, int height, Grid<int>& visited); // Part 1 only
    int TrailScore(size_t x, size_t y, int height); // Part 2 only
    const Grid<int>& data_;

};

// the solve function gets to be generic this time!
// the TrailScore function and its overloads are specialized per part
template<Parts p>
int Solver<p>::solve() {

    int score = 0;

    for(size_t y = 0; y < data_.MaxY(); y++) {
        for(size_t x = 0; x < data_.MaxX(); x++) {
            score += TrailScore(x, y);
        }
    }

    return score;

}

#endif