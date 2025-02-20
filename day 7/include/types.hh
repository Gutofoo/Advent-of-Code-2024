#ifndef _TYPES_HH_
#define _TYPES_HH_

#include <vector>

enum class Parts { PART1, PART2 };

enum class Operators {
    ADD,
    MULTIPLY,
    CONCAT
};

struct CalibrationEquation {
    long result;
    std::vector<long> operands;
    int number_of_operations;
};

#endif