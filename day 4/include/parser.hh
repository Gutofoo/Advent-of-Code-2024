#ifndef _PARSER_HH_
#define _PARSER_HH_

#include <array>
#include <fstream>
#include <string>
#include <vector>

#include "types.hh"
#include "wordsearch.hh"

class Parser {

    public:
        Parser(std::fstream&);
        void print() const;
        std::vector<std::vector<XMAS>> getParsedInput();


    private:
        std::vector<std::vector<XMAS>> grid;

};

#endif