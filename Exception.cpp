#include "Exception.h"
#include <iostream>
#include <string>

Exception::~Exception() {

}

std::ostream& operator<<(std::ostream& out, const Exception& e) {
    out << e.getMessage() << std::endl;  
    return out;
}