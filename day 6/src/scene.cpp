#include "scene.hh"

#include <string>
#include <vector>

#include "coordinate.hh"
#include "guard.hh"
#include "types.hh"

Scene::Scene(const std::vector<std::vector<GridItem>>& grid_input) :
  MAX_X_(grid_input[0].size()),
  MAX_Y_(grid_input.size()) {

    for(unsigned long y = 0; y < MAX_Y_; y++) {
        for(unsigned long x = 0; x < MAX_X_; x++) {
            switch(grid_input[y][x]) {
            case GridItem::OBSTACLE:
                obstacles_.push_back({x, y});
                break;
            case GridItem::GUARD:
                guard_ = std::make_unique<Guard>(Guard(obstacles_, {x, y}));
                break;
            }
        }
    }
}

Scene::Scene(const Scene& other) :
  MAX_X_(other.MAX_X_),
  MAX_Y_(other.MAX_Y_),
  obstacles_(other.obstacles_) {
    guard_ = std::make_unique<Guard>(Guard(obstacles_, other.ReportGuardPosition()));
}

Scene::Scene(const unsigned long max_x, const unsigned long max_y, const std::vector<Coordinate>& obstacles, const GuardState& initial_guard_state) :
  MAX_X_(max_x),
  MAX_Y_(max_y),
  obstacles_(obstacles) {
    guard_ = std::make_unique<Guard>(Guard(obstacles_, initial_guard_state.position));
}

void Scene::Update() {

    guard_->Update();

}

bool Scene::EndConditionReached() const {

    const Coordinate& guard_position = guard_->GetPosition();

    return (guard_position.x_ < 0) ||
      (guard_position.x_ > MAX_X_-1) ||
      (guard_position.y_ < 0) ||
      (guard_position.y_ > MAX_Y_-1);

}

const Coordinate& Scene::ReportGuardPosition() const {
    return guard_->GetPosition();
}

GuardState Scene::ReportGuardState() const {
    return {
        guard_->GetPosition(),
        guard_->GetHeading()
    };
}

const std::vector<Coordinate>& Scene::GetObstacles() const {
    return obstacles_;
}

std::vector<std::string> Scene::ToString() const {

    // Fill scene string with '.'
    std::vector<std::string> scene_string;
    for(unsigned long y = 0; y < MAX_Y_; y++) {
        std::string row = "";
        row.resize(MAX_X_);
        for(unsigned long x = 0; x < MAX_X_; x++) {
            row[x] = '.';
        }
        scene_string.push_back(row);
    }

    // Fill in obstacles with '#'
    for(size_t i = 0; i < obstacles_.size(); i++) {
        const Coordinate& current_coordinate = obstacles_[i];
        scene_string[current_coordinate.y_][current_coordinate.x_] = '#';
    }

    // must do a bounds check to ensure the guard is still within bounds
    if(!EndConditionReached()) {
        // Fill the guard's location with the current heading
        const Coordinate& guards_position = guard_->GetPosition();
        std::string guard_string = guard_->ToString();
        scene_string[guards_position.y_][guards_position.x_] = guard_string[0];
    }

    return scene_string;

}
