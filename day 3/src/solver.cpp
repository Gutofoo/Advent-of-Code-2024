#include <algorithm>
#include <array>
#include <regex>
#include <vector>

#include <iostream>

#include "mul.hh"
#include "solver.hh"
#include "types.hh"

template<>
int Solver<parts::PART1>::solve() {

    int sum = 0;

    const std::regex mulregex("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
    std::smatch match;

    for(size_t i = 0; i < data.size(); i++) {

        std::string corruptedLine = data[i];
        while(std::regex_search(corruptedLine, match, mulregex)) {

            sum += mul(match[0].str()).getProduct();

            corruptedLine = match.suffix();
        }

    }

    return sum;

}

template<>
int Solver<parts::PART2>::solve() {

    enum class ExecutionState {
        ENABLED,
        DISABLED
    };

    ExecutionState executionState = ExecutionState::ENABLED;

    int sum = 0;

    const std::string dostring = "do()";
    const std::string dontstring = "don't()";
    const std::regex mulregex("(mul\\([0-9]{1,3},[0-9]{1,3}\\))|(do\\(\\))|(don't\\(\\))");
    std::smatch match;

    for(size_t i = 0; i < data.size(); i++) {

        std::string corruptedLine = data[i];
        while(std::regex_search(corruptedLine, match, mulregex)) {

            std::string matchstr = corruptedLine;
            

            if(!match.prefix().str().empty())
                matchstr.erase(0, match.prefix().str().length());
            if(!match.suffix().str().empty())
                matchstr.erase(matchstr.find(match.suffix().str()));

            corruptedLine = match.suffix();

            if(matchstr.compare(dostring) == 0) {
                executionState = ExecutionState::ENABLED;
            } else if(matchstr.compare(dontstring) == 0) {
                executionState = ExecutionState::DISABLED;
            } else if(!matchstr.empty()) { // match is a mul() command
                if(executionState == ExecutionState::ENABLED) {
                    sum += mul(matchstr).getProduct();
                }
            }
            

        }

    }

    return sum;

}