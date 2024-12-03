#ifndef _TYPES_HH_
#define _TYPES_HH_

#include <array>
#include <vector>

enum class parts { PART1, PART2 };

enum {
    LEFT = 0,
    RIGHT = 1
};

using parsed_t = std::array<std::vector<int>, 2>;

#endif