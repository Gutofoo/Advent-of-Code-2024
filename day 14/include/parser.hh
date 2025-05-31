#ifndef _PARSER_HH_
#define _PARSER_HH_

#include <fstream>
#include <string>
#include <vector>

#include "robot.hh"
#include "types.hh"

class Parser {

  public:
    Parser(std::fstream&);
    void Print() const;
    const std::vector<Robot>& GetData() const;

  private:
    std::vector<Robot> data_;

};

#endif