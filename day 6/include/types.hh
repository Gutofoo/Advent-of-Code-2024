#ifndef _TYPES_HH_
#define _TYPES_HH_

#include <array>
#include <map>
#include <vector>

#include "coordinate.hh"

enum class parts { PART1, PART2 };

enum class GridItem {
    BLANK,
    OBSTACLE,
    GUARD,
    VISITED
};

enum class Heading {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

struct GuardState {
    Coordinate position;
    Heading heading;
};

const std::map<char, GridItem> CHAR_TO_GRID_MAP = {
    {'.', GridItem::BLANK},
    {'#', GridItem::OBSTACLE},
    {'^', GridItem::GUARD}
};

const std::map<GridItem, char> GRID_TO_CHAR_MAP = {
    {GridItem::BLANK, '.'},
    {GridItem::OBSTACLE, '#'},
    {GridItem::GUARD, '^'}
};

#endif