#include "solver.hh"

#include <cstddef>
#include <vector>

#include "disk_map.hh"
#include "types.hh"

template<>
long Solver<Parts::PART1>::solve() {

    // find the leftmost free space, and the rightmost file, and swap them
    size_t left_position = 0;
    size_t right_position = data_.Size();

    while(left_position < right_position) {

        Block* left = data_[left_position];
        Block* right = data_[right_position];

        // on the right side, decrement until a non-null Block
        while(right == nullptr) {
            right_position--;
            right = data_[right_position];
        }

        // if the left side is blank, swap it with the right side
        if(left == nullptr) {
            data_.Swap(left_position, right_position);
        }

        // increment the left position
        left_position++;

        // debug
        // data_.Print();

    }

    // debug
    // data_.Print();

    return Checksum();

}

template<>
long Solver<Parts::PART2>::solve() {

    return 0;

}