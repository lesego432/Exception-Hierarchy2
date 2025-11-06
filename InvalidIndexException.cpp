#include "InvalidIndexException.h"
#include <string>
#include <sstream>  

InvalidIndexException::InvalidIndexException(int index, bool isNull) : index(index),isNull(isNull){}

std::string InvalidIndexException::getMessage() const {
    std::stringstream ss;
    
    if (isNull) {
        ss << "Attempted access at invalid index of " << index << " and index was null.";
    } else {
        ss << "Attempted access at invalid index of " << index << ".";
    }
    
    return ss.str();
}