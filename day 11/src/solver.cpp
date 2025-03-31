#include "solver.hh"

#include <iostream>

#include "types.hh"

template<>
int Solver<Parts::PART1>::Solve() {

    // We just need 25 blinks.
    for(int i = 0; i < 25; i++) {
        data_.Blink();

        Rock::Prune(&data_);

        // data_.Print();
        // std::cout << "\n";

    }

    return data_.Count();

}

template<>
int Solver<Parts::PART2>::Solve() {

    return 0;

}