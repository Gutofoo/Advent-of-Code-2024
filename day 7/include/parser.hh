#ifndef _PARSER_HH_
#define _PARSER_HH_

#include <array>
#include <fstream>
#include <string>
#include <vector>

#include "types.hh"

class Parser {

  public:
    Parser(std::fstream&);
    void Print() const;
    const std::vector<CalibrationEquation>& GetParsedInput() const;

  private:
    std::vector<CalibrationEquation> data_;


};

#endif