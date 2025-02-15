#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {

  public:

    Coordinate(unsigned long x, unsigned long y);
    Coordinate(const Coordinate& other);
    Coordinate& operator=(const Coordinate& other);
    bool operator==(const Coordinate& other) const;

    unsigned long x_ = 0;
    unsigned long y_ = 0;

};

#endif