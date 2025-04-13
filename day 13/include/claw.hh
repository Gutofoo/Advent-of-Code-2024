#ifndef _CLAW_HH_
#define _CLAW_HH_

#include "types.hh"

class Claw {

  public:

    Claw(const Slope& a, const Slope& b, const Position& prize);
    void Print() const;

    Slope a_ = {0, 0};
    Slope b_ = {0, 0};
    Position prize_ = {0, 0};

};


#endif