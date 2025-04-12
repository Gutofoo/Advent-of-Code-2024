#ifndef _PARSER_HH_
#define _PARSER_HH_

#include <fstream>
#include <string>

#include "grid.hh"
#include "types.hh"

class Parser {

  public:
    Parser(std::fstream&);
    void Print() const;
    const Grid<Plant>& GetData() const;

  private:
    Grid<Plant> data_;

};

#endif