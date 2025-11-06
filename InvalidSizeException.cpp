#include "InvalidSizeException.h"
#include <string>
#include <sstream>  

InvalidSizeException::InvalidSizeException(int size) : size(size) {}

std::string InvalidSizeException::getMessage() const {
    std::stringstream ss;
    ss << "Invalid size of " << size << " was passed in!!";
    return ss.str();
}