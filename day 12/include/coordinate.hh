#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {

  public:

    Coordinate(int x, int y);
    Coordinate(const Coordinate& other);
    Coordinate& operator=(const Coordinate& other);
    Coordinate operator-(const Coordinate& other) const;
    bool operator==(const Coordinate& other) const;

    int x_ = 0;
    int y_ = 0;

};

#endif