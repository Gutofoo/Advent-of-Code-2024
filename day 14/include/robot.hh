#ifndef _ROBOT_HH_
#define _ROBOT_HH_

#include "types.hh"

class Robot {

  public:
    Robot();
    Robot(const Position& position, const Velocity& velocity);
    Robot(const Robot& other);
    Robot& operator=(const Robot& other);

    void Update();
    const Position& GetPosition() const;

    void Print() const;

  private:

    Position position_ = {0, 0};
    Velocity velocity_ = {0, 0};

};

#endif