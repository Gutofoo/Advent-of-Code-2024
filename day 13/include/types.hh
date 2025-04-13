#ifndef _TYPES_HH_
#define _TYPES_HH_

enum class Parts { PART1, PART2 };

struct Vector2D {
    long x = 0;
    long y = 0;
};

using Position = Vector2D;
using Slope = Vector2D;

const long A_TOKEN_COST = 3;
const long B_TOKEN_COST = 1;

#endif