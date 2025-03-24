#ifndef _DISK_MAP_HH_
#define _DISK_MAP_HH_

#include <cstddef>
#include <vector>

#include "block.hh"

class DiskMap {

  public:
    DiskMap();
    DiskMap(const DiskMap& other);
    const Block* operator[](size_t i) const;
    Block* operator[](size_t i);
    void Push_Back(Block* block);
    size_t Size() const;
    void Swap(size_t left, size_t right);
    void Print() const;

  private:
    std::vector<Block*> data_;
    

};

#endif