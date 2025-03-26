#include "solver.hh"

#include <vector>

#include "grid.hh"
#include "types.hh"

template<>
int Solver<Parts::PART1>::TrailScore(size_t x, size_t y, int height, Grid<int>& visited) {

    // if this spot's height is not next in line, end the recursion
    if(data_(x, y) != height) {
        return 0;
    }

    // if this spot has already been visited, get out
    if(visited(x, y)) {
        return 0;
    }

    // otherwise, mark this spot visited
    visited(x, y) = true;

    // base case: we have reached a 9
    if(data_(x, y) == 9) {
        return 1;
    }

    // otherwise: recurse on orthogonal grid spaces, mind the limits
    int score = 0;
    if(x + 1 < data_.MaxX()) {
        score += TrailScore(x+1, y, height+1, visited);
    }
    if(x >= 1) {
        score += TrailScore(x-1, y, height+1, visited);
    }
    if(y + 1 < data_.MaxY()) {
        score += TrailScore(x, y+1, height+1, visited);
    }
    if(y >= 1) {
        score += TrailScore(x, y-1, height+1, visited);
    }

    return score;

}


template<>
int Solver<Parts::PART1>::TrailScore(size_t x, size_t y) {

    // zeroth, if this isn't a valid trailhead, return 0 and leave
    if(data_(x, y) != 0) {
        return 0;
    }

    // first, set up a grid of visited spaces before entering the recursive step
    // note: these should be bools but the compiler is dumb
    // so treat these ints as bools
    std::vector<std::vector<int>> visited;
    visited.resize(data_.MaxY());
    for(size_t y = 0; y < data_.MaxY(); y++) {
        visited[y].resize(data_.MaxX());
        for(size_t x = 0; x < data_.MaxX(); x++) {
            visited[y][x] = false;
        }
    }

    Grid<int> visited_map = Grid<int>(visited);

    // now, enter the recursive step
    return TrailScore(x, y, 0, visited_map);

}

template<>
int Solver<Parts::PART2>::TrailScore(size_t x, size_t y, int height) {

    // if this spot's height is not next in line, end the recursion
    if(data_(x, y) != height) {
        return 0;
    }

    // base case: we have reached a 9
    if(data_(x, y) == 9) {
        return 1;
    }

    // otherwise: recurse on orthogonal grid spaces, mind the limits
    int score = 0;
    if(x + 1 < data_.MaxX()) {
        score += TrailScore(x+1, y, height+1);
    }
    if(x >= 1) {
        score += TrailScore(x-1, y, height+1);
    }
    if(y + 1 < data_.MaxY()) {
        score += TrailScore(x, y+1, height+1);
    }
    if(y >= 1) {
        score += TrailScore(x, y-1, height+1);
    }

    return score;
}

template<>
int Solver<Parts::PART2>::TrailScore(size_t x, size_t y) {

    // zeroth, if this isn't a valid trailhead, return 0 and leave
    if(data_(x, y) != 0) {
        return 0;
    }

    // now, enter the recursive step
    return TrailScore(x, y, 0);

}