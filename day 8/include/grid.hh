#ifndef _GRID_HH_
#define _GRID_HH_

#include <vector>

#include "antenna.hh"

class Grid {

  public:

    Grid();
    Grid(const std::vector<Antenna>& antennae, const int max_x, const int max_y);
    ~Grid() = default;
    const int GetMaxX() const { return max_x_; }
    const int GetMaxY() const { return max_y_; }
    const std::vector<Antenna>& GetAntennae() const {return antennae_; }

  private:

    std::vector<Antenna> antennae_;
    int max_x_ = 0;
    int max_y_ = 0;

};

#endif