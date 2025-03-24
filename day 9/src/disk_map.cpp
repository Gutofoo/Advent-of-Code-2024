#include "disk_map.hh"

#include <cstddef>
#include <iostream>

DiskMap::DiskMap() {}

// copy constructor: must deep copy the contents
DiskMap::DiskMap(const DiskMap& other) {
    data_.resize(other.data_.size());
    for(size_t i = 0; i < other.data_.size(); i++) {
        if(other.data_[i] != nullptr) {
            data_[i] = new Block(*other.data_[i]);
        }
    }
}

const Block* DiskMap::operator[](size_t i) const {
    return data_[i];
}

Block* DiskMap::operator[](size_t i) {
    return data_[i];
}

void DiskMap::Push_Back(Block* block) {
    data_.push_back(block);
}

void DiskMap::Swap(size_t left, size_t right) {

    Block* temp = data_[left];
    data_[left] = data_[right];
    data_[right] = temp;

}

size_t DiskMap::Size() const {
    return data_.size();
}

void DiskMap::Print() const {
    std::cout << "|";
    for(size_t i = 0; i < data_.size(); i++) {

        if(data_[i] == nullptr) {
            std::cout << ".";
        } else {
            std::cout << data_[i]->GetId();
        }

        std::cout << "|";

    }

    std::cout << "\n";
}