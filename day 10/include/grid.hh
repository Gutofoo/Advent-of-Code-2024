#ifndef _GRID_HH_
#define _GRID_HH_

#include<cstddef>
#include<iostream>
#include<vector>

template<typename T>
class Grid {

  public:
    Grid() = default;
    Grid(const std::vector<std::vector<T>>& input);
    ~Grid() = default;
    void Set(const std::vector<std::vector<T>>& data);
    void Set(size_t x, size_t y, const T& value);
    T& operator()(size_t x, size_t y);
    const T& operator()(size_t x, size_t y) const;
    size_t MaxX() const;
    size_t MaxY() const;
    void Print() const;

  private:
    std::vector<std::vector<T>> data_;

};

template<typename T>
Grid<T>::Grid(const std::vector<std::vector<T>>& input) :
  data_(input) {
}

template<typename T>
T& Grid<T>::operator()(size_t x, size_t y) {
    return data_[y][x];
}

template<typename T>
void Grid<T>::Set(const std::vector<std::vector<T>>& data) {
    data_ = data;
}

template<typename T>
void Grid<T>::Set(size_t x, size_t y, const T& value) {
    data_[y][x] = value;
}

template<typename T>
const T& Grid<T>::operator()(size_t x, size_t y) const {
    return data_[y][x];
}

template<typename T>
size_t Grid<T>::MaxX() const {
    if(!data_.empty()) {
        return data_[0].size();
    }
    return 0;
}

template<typename T>
size_t Grid<T>::MaxY() const {
    return data_.size();
}

template<typename T>
void Grid<T>::Print() const {
    for(size_t y = 0; y < data_.size(); y++) {
        for(size_t x = 0; x < data_[0].size(); x++) {
            std::cout << data_[y][x];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

#endif