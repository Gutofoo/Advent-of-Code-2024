#ifndef _PARSER_HH_
#define _PARSER_HH_

#include <fstream>
#include <string>

#include "types.hh"

class Parser {

  public:
    Parser(std::fstream&);
    void Print() const;

  private:

};

#endif