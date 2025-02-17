#include "solver.hh"

#include <vector>

#include "types.hh"

template<>
bool Solver<Parts::PART1>::ProcessEquation(long result, long argument, Operators operation, std::vector<long> remaining_args) {

    // base case: no more arguments remaining
    if(remaining_args.empty()) {
        return result == argument;
    }

    long new_result = result;

    // do an operation based on the Operator
    switch(operation) {
    case Operators::ADD:
        if(result - argument < 0) return false;
        new_result -= argument;
        break;
    case Operators::MULTIPLY:
        if(result % argument != 0) return false;
        new_result /= argument;
    }

    long next_argument = remaining_args.back();
    std::vector<long> next_args = remaining_args;
    next_args.pop_back();

    return ProcessEquation(new_result, next_argument, Operators::ADD, next_args)
      || ProcessEquation(new_result, next_argument, Operators::MULTIPLY, next_args);

}

template<>
int Solver<Parts::PART1>::solve() {

    int sum = 0;

    for(const CalibrationEquation& current_equation : data_) {

        // process this equation
        std::vector<long> remaining_args = current_equation.operands;
        remaining_args.pop_back();

        const bool equation_is_valid = ProcessEquation(current_equation.result, current_equation.operands.back(), Operators::ADD, remaining_args)
          || ProcessEquation(current_equation.result, current_equation.operands.back(), Operators::MULTIPLY, remaining_args);

        if(equation_is_valid) {
            sum += current_equation.result;
        }

    }

    // 1580289603 is too low!

    return sum;

}

template<>
int Solver<Parts::PART2>::solve() {

    return 0;

}