#ifndef COORDINATE_H
#define COORDINATE_H

#include <cstddef>

class Coordinate {

  public:

    Coordinate(size_t x, size_t y);
    Coordinate(const Coordinate& other);
    Coordinate& operator=(const Coordinate& other);
    Coordinate operator-(const Coordinate& other) const;
    bool operator==(const Coordinate& other) const;

    size_t x_ = 0;
    size_t y_ = 0;

};

#endif