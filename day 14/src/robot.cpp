#include "robot.hh"

#include <iostream>

#include "types.hh"

Robot::Robot() {}

Robot::Robot(const Position& position, const Velocity& velocity) :
  position_(position),
  velocity_(velocity) {
}

Robot::Robot(const Robot& other) :
  position_(other.position_),
  velocity_(other.velocity_) {
}

Robot& Robot::operator=(const Robot& other) {
    this->position_ = other.position_;
    this->velocity_ = other.velocity_;
    return *this;
}

const Position& Robot::GetPosition() const {
    return position_;
}

void Robot::Update() {

    // propagate the position of the robot
    position_ = position_ + velocity_;

    // bounds checking: do some wraparound
    if(position_.x < 0) {
        position_.x = MAX_WIDTH + position_.x;
    } else if(position_.x >= MAX_WIDTH) {
        position_.x -= MAX_WIDTH;
    }

    if(position_.y < 0) {
        position_.y = MAX_HEIGHT + position_.y;
    } else if(position_.y >= MAX_HEIGHT) {
        position_.y -= MAX_HEIGHT;
    }

}

void Robot::Print() const {
    std::cout << "p=" << position_.x << "," << position_.y << " ";
    std::cout << "v=" << velocity_.x << "," << velocity_.y << "\n";
}