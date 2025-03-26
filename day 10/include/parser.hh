#ifndef _PARSER_HH_
#define _PARSER_HH_

#include <array>
#include <fstream>
#include <string>
#include <vector>

#include "grid.hh"
#include "types.hh"

class Parser {

  public:
    Parser(std::fstream&);
    void Print() const;
    const Grid<int>& GetData() const;

  private:
    Grid<int> data_;

};

#endif