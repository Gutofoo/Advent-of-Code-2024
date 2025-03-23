#include "coordinate.hh"

#include <cstddef>

Coordinate::Coordinate(int x, int y) :
    x_(x),
    y_(y) {
}

Coordinate::Coordinate(const Coordinate& other) :
    x_(other.x_),
    y_(other.y_) {
}

Coordinate& Coordinate::operator=(const Coordinate& other) {
    x_ = other.x_;
    y_ = other.y_;
    return *this;
}

Coordinate Coordinate::operator-(const Coordinate& other) const {
    return {
        this->x_ - other.x_,
        this->y_ - other.y_
    };
}

bool Coordinate::operator==(const Coordinate& other) const {
    return (x_ == other.x_) && (y_ == other.y_);
}