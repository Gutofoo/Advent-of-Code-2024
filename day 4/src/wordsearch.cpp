#include <iostream>

#include "wordsearch.hh"

// default constructor: nothing
WordSearch::WordSearch() {
}

// copy constructor
WordSearch::WordSearch(const WordSearch& other) {
    this->grid = other.grid;
    this->width = other.width;
    this->height = other.height;
}

// constructor based on pre-populated grid
WordSearch::WordSearch(const std::vector<std::vector<XMAS>>& grid) {
    this->grid = grid;
    this->height = grid.size();
    this->width = grid[0].size();
}

WordSearch::WordSearch(const XMAS xmas, size_t width, size_t height) :
    width(width),
    height(height) {
    grid.resize(height);
    for(size_t y = 0; y < this->height; y++) {
        grid[y].resize(width);
        for(size_t x = 0; x < this->width; x++) {
            grid[y][x] = xmas;
        }
    }
}

 // operator =
WordSearch& WordSearch::operator=(const WordSearch& other) {
    this->grid = other.grid;
    this->width = other.width;
    this->height = other.height;
    return *this;
}

// prints the grid, from top left to bottom right
void WordSearch::print() const {

    for(size_t y = 0; y < height; y++) {
        for(size_t x = 0; x < width; x++) {
            std::cout << XMAS_TO_CHAR_MAP.at(this->operator()(x, y));
        }
        std::cout << "\n";
    }

}

// (0, 0) represents the top left corner
// reference return: allows modification of the grid externally
XMAS& WordSearch::operator()(int X, int Y) {
    return grid[Y][X];
}

// (0, 0) represents the top left corner
// value return: does not allow modification of the grid
XMAS WordSearch::operator()(int X, int Y) const {
    return grid[Y][X];
}