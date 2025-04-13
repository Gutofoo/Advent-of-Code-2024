#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "grid.hh"
#include "region.hh"
#include "types.hh"

template<Parts p>
class Solver {

  public:
    Solver(const Grid<Plant>& parsedInput);
    unsigned int Solve();

  private:
    const Grid<Plant>& data_;
    std::vector<Region> regions_;

};

template<Parts p>
Solver<p>::Solver(const Grid<Plant>& parsedInput) :
  data_(parsedInput) {

    for(int x = 0; x < data_.MaxX(); x++) {
        for(int y = 0; y < data_.MaxY(); y++) {
            const Coordinate current_point = {x, y};

            // check that this point is not part of a region already
            bool visited = false;
            for(const Region& region: regions_) {
                visited = visited || region.PointIsInRegion(current_point);
            }

            // skip the following if this point is already accounted for
            if(visited) continue;

            Region region = Region(data_(current_point), data_, current_point);
            regions_.push_back(std::move(region));

        }
    }

}

#endif