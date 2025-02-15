#ifndef _SCENE_HH_
#define _SCENE_HH_

#include "coordinate.hh"
#include "guard.hh"
#include "types.hh"

#include <map>
#include <memory>
#include <vector>

class Scene {

  public:

    Scene(const std::vector<std::vector<GridItem>>& grid_input);
    Scene(const Scene& other);
    Scene(const unsigned long max_x, const unsigned long max_y, const std::vector<Coordinate>& obstacles, const GuardState& initial_guard_state);
    void Update();
    std::vector<std::string> ToString() const;
    const Coordinate& ReportGuardPosition() const;
    const std::vector<Coordinate>& GetObstacles() const;
    GuardState ReportGuardState() const;
    bool EndConditionReached() const;
    inline const unsigned long& GetMaxX() { return MAX_X_; }
    inline const unsigned long& GetMaxY() { return MAX_Y_; }

  private:

    const unsigned long MAX_X_;
    const unsigned long MAX_Y_;

    std::vector<Coordinate> obstacles_;
    std::unique_ptr<Guard> guard_;


};


#endif