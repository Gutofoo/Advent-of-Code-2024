#ifndef _TYPES_HH_
#define _TYPES_HH_

#include <map>

enum class parts { PART1, PART2 };

enum class XMAS {
    BLANK, X, M, A, S
};

const std::map<XMAS, char> XMAS_TO_CHAR_MAP = {
    {XMAS::BLANK, '.'},
    {XMAS::X, 'X'},
    {XMAS::M, 'M'},
    {XMAS::A, 'A'},
    {XMAS::S, 'S'}
};

const std::map<char, XMAS> CHAR_TO_XMAS_MAP = {
    {'.', XMAS::BLANK},
    {'X', XMAS::X},
    {'M', XMAS::M},
    {'A', XMAS::A},
    {'S', XMAS::S}
};

enum directions {
    N = 0,
    NE,
    E,
    SE,
    S,
    SW,
    W,
    NW,
    MAX_DIRECTIONS
};

#endif