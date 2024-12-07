#include <string>

#include "mul.hh"

mul::mul(const std::string& in) {

    std::string leftnumberstring = in.substr(in.find("(")+1, in.find(",")-(in.find("(")+1));
    std::string rightnumberstring = in.substr(in.find(",")+1, in.find(")")-(in.find(",")+1));

    left = std::stoi(leftnumberstring);
    right = std::stoi(rightnumberstring);

    product = left*right;

}

int mul::getProduct() {
    return product;
}