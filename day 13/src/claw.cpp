#include "claw.hh"

#include <iostream>

#include "types.hh"

Claw::Claw(const Slope& a, const Slope& b, const Position& prize) :
  a_(a), b_(b), prize_(prize) {
}

void Claw::Print() const {
    std::cout << "Button A: X+" << a_.x << ", Y+" << a_.y << "\n";
    std::cout << "Button B: X+" << b_.x << ", Y+" << b_.y << "\n";
    std::cout << "Prize: X=" << prize_.x << ", Y=" << prize_.y << "\n";
}