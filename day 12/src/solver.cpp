#include <algorithm>
#include <vector>

#include "region.hh"
#include "solver.hh"
#include "types.hh"

template<>
unsigned int Solver<Parts::PART1>::Solve() {

    std::vector<Region> regions;

    for(int x = 0; x < data_.MaxX(); x++) {
        for(int y = 0; y < data_.MaxY(); y++) {
            const Coordinate current_point = {x, y};

            // check that this point is not part of a region already
            bool visited = false;
            for(const Region& region: regions) {
                visited = visited || region.PointIsInRegion(current_point);
            }

            // skip the following if this point is already accounted for
            if(visited) continue;

            Region region = Region(data_(current_point), data_, current_point);
            regions.push_back(std::move(region));

        }
    }

    unsigned int price = 0;

    for(const Region region : regions) {
        price += (region.GetArea() * region.GetPerimeter());
    }

    return price;

}

template<>
unsigned int Solver<Parts::PART2>::Solve() {

    return 0;

}