#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include <string>

#include "types.hh"

template<Parts p>
class Solver {

  public:
    Solver(const std::vector<CalibrationEquation>& parsed_input) :
      data_(parsed_input) { }
    long solve();

  private:
    const std::vector<CalibrationEquation>& data_;
    bool ProcessEquation(const CalibrationEquation& equation);
    bool ProcessEquation(long result, long argument, Operators operation, const std::vector<Operators>& operators_list, std::vector<long> remaining_args);

};

template<Parts p>
bool Solver<p>::ProcessEquation(long result, long argument, const Operators operation, const std::vector<Operators>& operators_list, std::vector<long> remaining_args) {

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
        break;
    case Operators::CONCAT:
        {
            std::string result_string = std::to_string(result);
            std::string arg_string = std::to_string(argument);
            if(result_string.size() <= arg_string.size()) return false; // can't be concatenated if the working result has fewer digits
            for(size_t i = 0; i < arg_string.length(); i++) {
                size_t j = result_string.length() - arg_string.length() + i;
                if(result_string[j] != arg_string[i]) return false; // now check that the result is concatted from the argument
            }
            result_string = result_string.substr(0, result_string.length()-arg_string.length());
            new_result = std::stol(result_string);
        }
    }

    long next_argument = remaining_args.back();
    std::vector<long> next_args = remaining_args;
    next_args.pop_back();

    bool return_value = false;
    for(size_t i = 0; i < operators_list.size(); i++) {
        return_value = return_value || ProcessEquation(new_result, next_argument, operators_list[i], operators_list, next_args);
    }
    // for(const Operators operator : operators_list) {
    //     return_value = return_value || ProcessEquation(new_result, next_argument, operator, operators_list, next_args);
    // }

    return return_value;
}

#endif