#include "coordinate.hh"

Coordinate::Coordinate(unsigned long x, unsigned long y) :
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

bool Coordinate::operator==(const Coordinate& other) const {
    return (x_ == other.x_) && (y_ == other.y_);
}