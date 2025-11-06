#include "OutOfBoundsException.h"
#include <string>

std::string OutOfBoundsException::getMessage() const {
    return "The iterator is outside of bounds!!!";
}