#include "block.hh"

Block::Block(long id) :
  id_(id) {
}

Block::Block(const Block& other) :
  id_(other.id_) {
}

long Block::GetId() const {
    return id_;
}