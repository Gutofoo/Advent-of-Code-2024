#ifndef _WORDSEARCH_HH_
#define _WORDSEARCH_HH_

#include <map>
#include <string>
#include <vector>

#include "types.hh"

class WordSearch {

    public:
        WordSearch();
        WordSearch(const WordSearch&);
        WordSearch(const std::vector<std::vector<XMAS>>&);
        WordSearch(const XMAS, size_t width, size_t height);
        WordSearch& operator=(const WordSearch&);
        void print() const;
        XMAS& operator()(int X, int Y);
        XMAS operator()(int X, int Y) const;
        inline size_t getHeight() const {return width;}
        inline size_t getWidth() const {return height;}

    private:
        size_t width{0};
        size_t height{0};
        std::vector<std::vector<XMAS>> grid;

};


#endif