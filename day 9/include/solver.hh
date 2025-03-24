#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include "disk_map.hh"
#include "types.hh"

template<Parts p>
class Solver {

  public:
      Solver(const DiskMap& input) :
          data_(input) { }
    long solve();

  private:
    DiskMap data_;
    long Checksum() const;

};

template<Parts p>
long Solver<p>::Checksum() const {

    long sum = 0;
    for(long i = 0; i < data_.Size(); i++) {
        if(data_[i] != nullptr)
            sum += i * data_[i]->GetId();
    }

    return sum;

}

#endif