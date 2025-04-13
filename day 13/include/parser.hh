#ifndef _PARSER_HH_
#define _PARSER_HH_

#include <fstream>
#include <string>
#include <vector>

#include "claw.hh"
#include "types.hh"

class Parser {

  public:
    Parser(std::fstream&);
    void Print() const;
    const std::vector<Claw>& GetData() const;

  private:
    std::vector<Claw> data_;

};

#endif