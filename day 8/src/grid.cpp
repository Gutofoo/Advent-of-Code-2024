#include "grid.hh"

#include <vector>

#include "antenna.hh"
#include "types.hh"


Grid::Grid() {
}

Grid::Grid(const std::vector<Antenna>& antennae, const int max_x, const int max_y) :
  antennae_(antennae),
  max_x_(max_x),
  max_y_(max_y) {
}

