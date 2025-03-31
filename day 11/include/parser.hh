#ifndef _PARSER_HH_
#define _PARSER_HH_

#include <fstream>
#include <string>

#include "rock.hh"
#include "types.hh"

class Parser {

  public:
    Parser(std::fstream&);
    Rock& GetData() const;
    void Print() const;

  private:
    Rock* data_ = nullptr;

};

#endif