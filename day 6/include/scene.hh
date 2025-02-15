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
    void Update();
    std::vector<std::string> ToString() const;
    const Coordinate& ReportGuardPosition() const;
    GuardState ReportGuardState() const;
    bool EndConditionReached() const;
    inline const unsigned long& GetMaxX() const;
    inline const unsigned long& GetMaxY() const;

  private:

    const unsigned long MAX_X_;
    const unsigned long MAX_Y_;

    std::vector<Coordinate> obstacles_;
    std::unique_ptr<Guard> guard_;


};


#endif