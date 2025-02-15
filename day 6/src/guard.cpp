#include "guard.hh"

#include <algorithm>
#include <string>
#include <vector>

#include "coordinate.hh"
#include "types.hh"

Guard::Guard(const std::vector<Coordinate>& obstacles, const Coordinate& start_position) :
  obstacles_(obstacles),
  position_(start_position) {
}

const Coordinate& Guard::GetPosition() const {
    return position_;
}

const Heading& Guard::GetHeading() const {
    return heading_;
}

std::string Guard::ToString() const {

    switch(heading_) {
    case Heading::UP:
        return "^";
    case Heading::RIGHT:
        return ">";
    case Heading::DOWN:
        return "v";
    case Heading::LEFT:
        return "<";
    }

    return "^";

}

void Guard::Update() {

    // if there is an obstacle ahead, turn 90 degrees
    const Coordinate next_position = NextPosition();

    // an obstacle is in the way: update the heading
    if(std::any_of(obstacles_.begin(), obstacles_.end(), [next_position](const Coordinate input) { return input == next_position; })) {
        heading_ = NextHeading();
    } else { // otherwise, take a step
        position_ = next_position;
    }

}

Coordinate Guard::NextPosition() const {

    Coordinate next_position = position_;

    switch(heading_) {
    case Heading::UP:
        next_position.y_--;
        break;
    case Heading::RIGHT:
        next_position.x_++;
        break;
    case Heading::LEFT:
        next_position.x_--;
        break;
    case Heading::DOWN:
        next_position.y_++;
        break;
    }

    return next_position;

}

Heading Guard::NextHeading() const {

    switch(heading_) {
    case Heading::UP:
        return Heading::RIGHT;
    case Heading::RIGHT:
        return Heading::DOWN;
    case Heading::LEFT:
        return Heading::UP;
    case Heading::DOWN:
        return Heading::LEFT;
    }

    return Heading::UP;

}