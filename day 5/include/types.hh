#ifndef _TYPES_HH_
#define _TYPES_HH_

#include <array>
#include <map>
#include <utility>
#include <vector>

enum class parts { PART1, PART2 };

using page = int;
using rule = std::pair<page, page>;
using update = std::vector<page>;

struct RulesAndUpdates {
    std::vector<rule> rules;
    std::vector<update> updates;
};

#endif