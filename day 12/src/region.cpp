#include "region.hh"

#include <algorithm>
#include <vector>

#include "coordinate.hh"
#include "grid.hh"
#include "types.hh"

Region::Region(Plant id, const Grid<Plant>& field, const Coordinate& starting_point) : 
  id_(id),
  field_(field) {
    // Construct the field by searching neighboring plots on the field and add ones matching the Plant id
    std::vector<Coordinate> visited_plots;
    ConstructRegion(visited_plots, starting_point);

    CalculateArea();
    CalculatePerimeter();
    CalculateSides();
}

void Region::ConstructRegion(std::vector<Coordinate>& visited_points, const Coordinate& point) {

    // base case: current plot doesn't match the field being constructed, simply return
    if(id_ != field_(point)) {
        return;
    }

    // also, check that this plot has not already been visited
    if(std::any_of(visited_points.begin(), visited_points.end(), [point](const Coordinate& element){ return element == point; })) {
        return;
    }

    // since the plant matches the id of the region under construction, add this point to the plot list
    plots_.emplace_back(point);

    // also, add this point to the list of plots already visited
    visited_points.emplace_back(point);

    // now visit the adjacent points, if possible
    if(point.x_ - 1 >= 0) {
        const Coordinate next_point = {
            point.x_-1, point.y_
        };
        ConstructRegion(visited_points, next_point);
    }
    if(point.x_ + 1 < field_.MaxX()) {
        const Coordinate next_point = {
           point.x_+1, point.y_
        };
        ConstructRegion(visited_points, next_point);
    }
    if(point.y_ - 1 >= 0) {
      const Coordinate next_point = {
         point.x_, point.y_-1
      };
      ConstructRegion(visited_points, next_point);
    }
    if(point.y_ + 1 < field_.MaxY()) {
      const Coordinate next_point = {
         point.x_, point.y_+1
      };
      ConstructRegion(visited_points, next_point);
    }
}

// public helper to evaluate if the input point is already in this region
bool Region::PointIsInRegion(const Coordinate& point) const {
    return std::any_of(plots_.begin(), plots_.end(), [point](const Coordinate& element){ return element == point; });
}

// calculating the area is trivially easy, it's just the number of plots in this region
void Region::CalculateArea() {
    area_ = plots_.size();
}

void Region::CalculatePerimeter() {
    for(const Coordinate& plot : plots_) {
        // at each point, see how many adjacent neighbors are in the region
        const Coordinate left = {plot.x_-1, plot.y_};
        const Coordinate right = {plot.x_+1, plot.y_};
        const Coordinate up = {plot.x_, plot.y_-1};
        const Coordinate down = {plot.x_, plot.y_+1};

        // if the neighboring point is not in the region, then that side of the current point contributes to the perimeter
        if(std::none_of(plots_.begin(), plots_.end(), [left](const Coordinate& element){ return element == left; })) perimeter_++;
        if(std::none_of(plots_.begin(), plots_.end(), [right](const Coordinate& element){ return element == right; })) perimeter_++;
        if(std::none_of(plots_.begin(), plots_.end(), [up](const Coordinate& element){ return element == up; })) perimeter_++;
        if(std::none_of(plots_.begin(), plots_.end(), [down](const Coordinate& element){ return element == down; })) perimeter_++;
    }
}

// for calculating sides, realize number of sides == number of corners
void Region::CalculateSides() {
    for(const Coordinate& plot : plots_) {

        const Coordinate left = {plot.x_-1, plot.y_};
        const Coordinate right = {plot.x_+1, plot.y_};
        const Coordinate up = {plot.x_, plot.y_-1};
        const Coordinate down = {plot.x_, plot.y_+1};
        
        const Coordinate topleft = {plot.x_-1, plot.y_-1};
        const Coordinate bottomleft = {plot.x_-1, plot.y_+1};
        const Coordinate topright = {plot.x_+1, plot.y_-1};
        const Coordinate bottomright = {plot.x_+1, plot.y_+1};
        
        // top left
        if(std::none_of(plots_.begin(), plots_.end(), [left](const Coordinate& element){ return element == left; })
          && std::none_of(plots_.begin(), plots_.end(), [up](const Coordinate& element){ return element == up; })) {
            // convex corner
            sides_++;
        } else if(std::any_of(plots_.begin(), plots_.end(), [left](const Coordinate& element){ return element == left; })
          && std::any_of(plots_.begin(), plots_.end(), [up](const Coordinate& element){ return element == up; })) {
            // concave corner
            if(std::none_of(plots_.begin(), plots_.end(), [topleft](const Coordinate& element){ return element == topleft; })) sides_++;
        }

        // bottom left
        if(std::none_of(plots_.begin(), plots_.end(), [left](const Coordinate& element){ return element == left; })
          && std::none_of(plots_.begin(), plots_.end(), [down](const Coordinate& element){ return element == down; })) {
            // convex corner
            sides_++;
        } else if(std::any_of(plots_.begin(), plots_.end(), [left](const Coordinate& element){ return element == left; })
          && std::any_of(plots_.begin(), plots_.end(), [down](const Coordinate& element){ return element == down; })) {
            // concave corner
            if(std::none_of(plots_.begin(), plots_.end(), [bottomleft](const Coordinate& element){ return element == bottomleft; })) sides_++;
        }

        // top right
        if(std::none_of(plots_.begin(), plots_.end(), [right](const Coordinate& element){ return element == right; })
          && std::none_of(plots_.begin(), plots_.end(), [up](const Coordinate& element){ return element == up; })) {
            // convex corner
            sides_++;
        } else if(std::any_of(plots_.begin(), plots_.end(), [right](const Coordinate& element){ return element == right; })
          && std::any_of(plots_.begin(), plots_.end(), [up](const Coordinate& element){ return element == up; })) {
            // concave corner
            if(std::none_of(plots_.begin(), plots_.end(), [topright](const Coordinate& element){ return element == topright; })) sides_++;
        }

        // bottom right
        if(std::none_of(plots_.begin(), plots_.end(), [right](const Coordinate& element){ return element == right; })
          && std::none_of(plots_.begin(), plots_.end(), [down](const Coordinate& element){ return element == down; })) {
            // convex corner
            sides_++;
        } else if(std::any_of(plots_.begin(), plots_.end(), [right](const Coordinate& element){ return element == right; })
          && std::any_of(plots_.begin(), plots_.end(), [down](const Coordinate& element){ return element == down; })) {
            // concave corner
            if(std::none_of(plots_.begin(), plots_.end(), [bottomright](const Coordinate& element){ return element == bottomright; })) sides_++;
        }

    }
}

unsigned int Region::GetArea() const {
    return area_;
}

unsigned int Region::GetPerimeter() const {
    return perimeter_;
}

unsigned int Region::GetSides() const {
    return sides_;
}