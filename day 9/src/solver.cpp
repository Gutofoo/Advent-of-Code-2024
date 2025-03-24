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

    size_t left_position = 0;
    size_t right_position = data_.Size();

    // on the left, find the first free space
    while(data_[left_position] != nullptr) {
        left_position++;
    }

    // start on the right, find the next file to swap
    while(left_position < right_position) {

        // on the right side, decrement until a non-null Block
        while(data_[right_position] == nullptr) {
            right_position--;
        }

        // with a non-null right block, find out how big this file is
        size_t file_size = 0;
        size_t file_position = right_position;
        while(true) {
            // file_position--;
            // if(data_[file_position] == nullptr) {
            //     break;
            // } else if(data_[file_position]->GetId() == data_[right_position]->GetId()) {
            //     file_size++;
            // } else {
            //     break;
            // }
            if(data_[file_position] == nullptr || file_position > data_.Size()) {
                break;
            }

            if(data_[file_position]->GetId() == data_[right_position]->GetId()) {
                file_size++;
            } else {
                break;
            }
            file_position--;
        }

        bool empty_space_found = false;

        // now, find the leftmost block that fits this file
        while(left_position < data_.Size()) {

            // found an empty spot, now loop to see how big it is
            if(data_[left_position] == nullptr) {
                
                // let's find how big this empty space is
                size_t empty_size = 0;
                size_t empty_position = left_position;
                while(data_[empty_position] == nullptr && empty_position < data_.Size()) {
                    empty_size++;
                    empty_position++;
                }
                // the first instance of a set of empty blocks of the right size lets us exit and start the swapping
                if(empty_size >= file_size) {
                    empty_space_found = true;
                    break;
                }
            }
            // regardless, increment the left_position
            left_position++;
        }

        // now: swap!
        if(empty_space_found && left_position < right_position) {

            // left_position is the leftmost 
            for(size_t i = 0; i < file_size; i++) {
                data_.Swap(left_position+i, right_position-i);
            }

        }

        // to iterate: move the right_position marker leftwards by the size of the file, or by 1 if there was no file
        right_position -= (file_size > 0) ? file_size : 1;

        // and reset the left_position marker to the leftmost empty space
        left_position = 0;
        while(data_[left_position] != nullptr) {
            left_position++;
        }

        // debug
        // data_.Print();

    }

    return Checksum();

}