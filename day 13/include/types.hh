#ifndef _TYPES_HH_
#define _TYPES_HH_

enum class Parts { PART1, PART2 };

struct Vector2D {
    int x = 0;
    int y = 0;
};

using Position = Vector2D;
using Slope = Vector2D;

const int A_TOKEN_COST = 3;
const int B_TOKEN_COST = 1;

#endif