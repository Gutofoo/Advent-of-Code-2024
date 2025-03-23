#include "grid.hh"

#include <cstddef>
#include <vector>

#include "antenna.hh"
#include "types.hh"


Grid::Grid() {
}

Grid::Grid(const std::vector<Antenna>& antennae, const size_t max_x, const size_t max_y) :
  antennae_(antennae),
  max_x_(max_x),
  max_y_(max_y) {
}

