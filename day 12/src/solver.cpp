#include <algorithm>
#include <vector>

#include "region.hh"
#include "solver.hh"
#include "types.hh"

template<>
unsigned int Solver<Parts::PART1>::Solve() {

    unsigned int price = 0;

    for(const Region region : regions_) {
        price += (region.GetArea() * region.GetPerimeter());
    }

    return price;

}

template<>
unsigned int Solver<Parts::PART2>::Solve() {

    unsigned int price = 0;

    for(const Region region : regions_) {
        price += (region.GetArea() * region.GetSides());
    }

    return price;


}