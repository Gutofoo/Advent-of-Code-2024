#ifndef _GRID_HH_
#define _GRID_HH_

#include <cstddef>
#include <vector>

#include "antenna.hh"

class Grid {

  public:

    Grid();
    Grid(const std::vector<Antenna>& antennae, const size_t max_x, const size_t max_y);
    ~Grid() = default;
    const size_t GetMaxX() const { return max_x_; }
    const size_t GetMaxY() const { return max_y_; }
    const std::vector<Antenna>& GetAntennae() const {return antennae_; }

  private:

    std::vector<Antenna> antennae_;
    size_t max_x_ = 0;
    size_t max_y_ = 0;

};

#endif