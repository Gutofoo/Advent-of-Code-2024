#ifndef _BLOCK_HH_
#define _BLOCK_HH_

class Block {

  public:
    Block(long id);
    Block(const Block& other);
    long GetId() const;

  private:
    long id_;

};

#endif