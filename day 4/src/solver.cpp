#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#include "solver.hh"
#include "types.hh"
#include "wordsearch.hh"

template<>
int Solver<parts::PART1>::solve() {

    // double loop through the grid
    // stop at each 'X'
    // search in each direction
    std::array<WordSearch, MAX_DIRECTIONS> searches;
    for(int i = 0; i < MAX_DIRECTIONS; i++) {
        searches[i] = WordSearch(XMAS::BLANK, data.getWidth(), data.getHeight());
    }
    std::array<int, MAX_DIRECTIONS> xmasHits{0};

    for(size_t y = 0; y < data.getHeight(); y++) {
        for(size_t x = 0; x < data.getWidth(); x++) {

            point coordinate = {x, y};
            for(int d = 0; d < MAX_DIRECTIONS; d++) {
                if(findXmas(coordinate, static_cast<directions>(d), XMAS::X)) {
                    xmasHits[d]++;
                    drawXmas(searches[d], coordinate, static_cast<directions>(d), XMAS::X);
                }
            }

        }
    }

    // tally up the hits!
    int sum = 0;
    for(int d = 0; d < MAX_DIRECTIONS; d++) {
        sum += xmasHits[d];
    }

    // debug: draw the individual search grids
    // for(int d = 0; d < MAX_DIRECTIONS; d++) {
    //     searches[d].print();
    //     std::cout << "\n";
    // }

    return sum;

}

template<>
int Solver<parts::PART2>::solve() {


    int crossMasHits = 0;
    WordSearch crossMas = WordSearch(XMAS::BLANK, data.getWidth(), data.getHeight());

    // loop bounds are adjusted because a X-MAS can't appear with the A on the edge
    for(size_t y = 1; y < data.getHeight()-1; y++) {
        for(size_t x = 1; x < data.getWidth()-1; x++) {

            point coordinate = {x, y};
            if(findCrossMas(coordinate)) {
                crossMasHits++;
                drawCrossMas(crossMas, coordinate);
            }

        }
    }

    // debug: print the found grid
    // crossMas.print();

    return crossMasHits;

}


template<>
bool Solver<parts::PART1>::findXmas(const point& coordinate, directions d, const XMAS& query) {

    // base case: no next query, the end has been reached
    if(query == XMAS::BLANK) {
        return true;
    }

    // bounds check: if the coordinate is out of bounds, return false
    if(coordinate.x < 0 || coordinate.x >= data.getWidth() || coordinate.y < 0 || coordinate.y >= data.getHeight()) {
        return false;
    }

    // regular exist case: the current point does not match the queried XMAS letter
    if(data(coordinate.x, coordinate.y) != query) {
        return false;
    }

    // recursive case: go to the next coordinate, and the next XMAS letter
    const point nextCoordinate = Solver::transform(d, coordinate);
    const XMAS nextXmas = NEXT_XMAS_MAP.at(query);

    return findXmas(nextCoordinate, d, nextXmas);

}

template<>
bool Solver<parts::PART2>::findCrossMas(const point& coordinate) {

    // first: the current location must be an A
    if(data(coordinate.x, coordinate.y) != XMAS::A) {
        return false;
    }

    // step one: query the corners
    const point northwest = transform(NW, coordinate);
    const point northeast = transform(NE, coordinate);
    const point southeast = transform(SE, coordinate);
    const point southwest = transform(SW, coordinate);

    const XMAS nwXmas = data(northwest.x, northwest.y);
    const XMAS neXmas = data(northeast.x, northeast.y);
    const XMAS seXmas = data(southeast.x, southeast.y);
    const XMAS swXmas = data(southwest.x, southwest.y);

    // corner values must be either XMAS::M or XMAS::A
    if(nwXmas != XMAS::M && nwXmas != XMAS::S) return false;
    if(neXmas != XMAS::M && neXmas != XMAS::S) return false;
    if(seXmas != XMAS::M && seXmas != XMAS::S) return false;
    if(swXmas != XMAS::M && swXmas != XMAS::S) return false;

    // opposite corners must not be equivalent
    return (nwXmas != seXmas) && (neXmas != swXmas);

}