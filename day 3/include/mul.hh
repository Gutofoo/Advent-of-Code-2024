#ifndef _MUL_HH_
#define _MUL_HH_

#include <string>

class mul {

    public:
        mul(const std::string& in);
        int getProduct();

    private:
        int left;
        int right;
        int product;

};



#endif