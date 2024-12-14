#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include <map>

#include "types.hh"
#include "wordsearch.hh"

template<parts p>
class Solver {

    public:
        Solver(const WordSearch& parsedInput) :
            data(parsedInput) { }
        int solve() { return 0; };

    private:
        const WordSearch& data;

        struct point {
            size_t x{0};
            size_t y{0};
        };

        static point transform(const directions d, const point&);

        const std::map<XMAS, XMAS> NEXT_XMAS_MAP = {
            {XMAS::X, XMAS::M},
            {XMAS::M, XMAS::A},
            {XMAS::A, XMAS::S},
            {XMAS::S, XMAS::BLANK}
        };

        bool findXmas(const point& coordinate, directions d, const XMAS&) { return false; }
        void drawXmas(WordSearch&, const point& coordinate, directions d, const XMAS&);

        bool findCrossMas(const point& coordinate) { return false; }
        void drawCrossMas(WordSearch&, const point& coordinate);

};

template<parts p>
typename Solver<p>::point Solver<p>::transform(const directions d, const point& input) {

    point ret = input;

    switch(d) {
        case N:
            ret.y--;
            break;
        case NE:
            ret.x++;
            ret.y--;
            break;
        case E:
            ret.x++;
            break;
        case SE:
            ret.x++;
            ret.y++;
            break;
        case S:
            ret.y++;
            break;
        case SW:
            ret.x--;
            ret.y++;
            break;
        case W:
            ret.x--;
            break;
        case NW:
            ret.x--;
            ret.y--;
            break;
    }

    return ret;

}

// note: this function assumes a XMAS was already found at the first input coordinate
// this does not do bounds checking and may break if findXmas returned false!
template<parts p>
void Solver<p>::drawXmas(WordSearch& xmasGrid, const point& coordinate, directions d, const XMAS& query) {

    // base case: no next query, the end has been reached
    if(query == XMAS::BLANK) {
        return;
    }

    xmasGrid(coordinate.x, coordinate.y) = query;

    // recursive case: go to the next coordinate, and the next XMAS letter
    const point nextCoordinate = Solver::transform(d, coordinate);
    const XMAS nextXmas = NEXT_XMAS_MAP.at(query);

    drawXmas(xmasGrid, nextCoordinate, d, nextXmas);

}

// note: this function assumes that a valid X-MAS was already found at the point!
// there is no bounds checking in this function
template<parts p>
void Solver<p>::drawCrossMas(WordSearch& grid, const point& coordinate) {

    const point northwest = transform(NW, coordinate);
    const point northeast = transform(NE, coordinate);
    const point southeast = transform(SE, coordinate);
    const point southwest = transform(SW, coordinate);

    grid(coordinate.x, coordinate.y) = XMAS::A;

    grid(northwest.x, northwest.y) = data(northwest.x, northwest.y);
    grid(northeast.x, northeast.y) = data(northeast.x, northeast.y);
    grid(southeast.x, southeast.y) = data(southeast.x, southeast.y);
    grid(southwest.x, southwest.y) = data(southwest.x, southwest.y);

}

template<>
bool Solver<parts::PART1>::findXmas(const point& coordinate, directions d, const XMAS&);

template<>
bool Solver<parts::PART2>::findCrossMas(const point& coordinate);

#endif