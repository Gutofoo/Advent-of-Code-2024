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
        const RulesAndUpdates& getParsedInput() const;

    private:
        RulesAndUpdates data_;

};

#endif