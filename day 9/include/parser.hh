#ifndef _PARSER_HH_
#define _PARSER_HH_

#include <array>
#include <fstream>
#include <string>
#include <vector>

#include "disk_map.hh"
#include "types.hh"

class Parser {

  public:
    Parser(std::fstream&);
    void Print() const;
    const DiskMap& GetData() const;

  private:
    DiskMap data_;

};

#endif