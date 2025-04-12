#ifndef _REGION_HH_
#define _REGION_HH_

#include <vector>

#include "coordinate.hh"
#include "grid.hh"
#include "types.hh"

class Region {

  public:

    Region(Plant id, const Grid<Plant>& field, const Coordinate& starting_point);
    bool PointIsInRegion(const Coordinate& point) const;
    unsigned int GetArea() const;
    unsigned int GetPerimeter() const;
    unsigned int GetSides() const;

  private:

    void ConstructRegion(std::vector<Coordinate>& visited_points, const Coordinate& point);
    void CalculateArea();
    void CalculatePerimeter();
    void CalculateSides();

    Plant id_; // this is the Plant of this region of the field
    std::vector<Coordinate> plots_; // coordinates included in this field
    const Grid<Plant>& field_; // const reference to the base field this region is in

    unsigned int area_ = 0U;
    unsigned int perimeter_ = 0U;
    unsigned int sides_ = 0U;

};


#endif