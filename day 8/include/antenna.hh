#ifndef _ANTENNA_HH_
#define _ANTENNA_HH_

#include "coordinate.hh"

class Antenna {

  public:

    Antenna(char frequency, Coordinate position);
    ~Antenna() = default;
    const Coordinate& GetPosition() const { return position_; }
    char GetFrequency() const { return frequency_; }

  private:

    char frequency_;
    Coordinate position_;

};

#endif