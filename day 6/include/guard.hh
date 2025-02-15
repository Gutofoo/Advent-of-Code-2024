#ifndef _GUARD_HH_
#define _GUARD_HH_

#include <string>
#include <vector>

#include "coordinate.hh"
#include "types.hh"

class Guard {

  public:

    Guard(const std::vector<Coordinate>& obstacles, const Coordinate& start_position);
    void Update();
    const Coordinate& GetPosition() const;
    const Heading& GetHeading() const;
    std::string ToString() const;

  private:

    Coordinate NextPosition() const;
    Heading NextHeading() const;

    const std::vector<Coordinate>& obstacles_;
    Coordinate position_;
    Heading heading_ = Heading::UP;

};

#endif