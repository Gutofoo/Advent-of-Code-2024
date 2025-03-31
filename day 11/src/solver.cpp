#include "solver.hh"

#include <iostream>

#include "types.hh"

template<>
unsigned long Solver<Parts::PART1>::Solve() {

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
unsigned long Solver<Parts::PART2>::Solve() {

    // Part 2: try 75 blinks
    for(int i = 0; i < 75; i++) {
        data_.Blink();

        Rock::Prune(&data_);

        // data_.Print();
        // std::cout << "\n";

    }

    return data_.Count();

}