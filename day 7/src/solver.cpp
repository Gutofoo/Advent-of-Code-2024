#include "solver.hh"

#include <string>
#include <vector>

#include "types.hh"

template<>
bool Solver<Parts::PART1>::ProcessEquation(const CalibrationEquation& equation) {

    std::vector<long> remaining_args = equation.operands;
    remaining_args.pop_back();
    const std::vector<Operators> operations = {
        Operators::ADD,
        Operators::MULTIPLY
    };

    return ProcessEquation(equation.result, equation.operands.back(), Operators::ADD, operations, remaining_args)
      || ProcessEquation(equation.result, equation.operands.back(), Operators::MULTIPLY, operations, remaining_args);

}

template<>
bool Solver<Parts::PART2>::ProcessEquation(const CalibrationEquation& equation) {

    std::vector<long> remaining_args = equation.operands;
    remaining_args.pop_back();
    const std::vector<Operators> operations = {
        Operators::ADD,
        Operators::MULTIPLY,
        Operators::CONCAT
    };

    return ProcessEquation(equation.result, equation.operands.back(), Operators::ADD, operations, remaining_args)
      || ProcessEquation(equation.result, equation.operands.back(), Operators::MULTIPLY, operations, remaining_args)
      || ProcessEquation(equation.result, equation.operands.back(), Operators::CONCAT, operations, remaining_args);

}
