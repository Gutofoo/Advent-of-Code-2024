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
        void print() const;
        report_t getParsedInput() const;

    private:
        report_t data;

};

#endif