#include "ElementNotInListException.h"
#include <string>

std::string ElementNotInListException::getMessage() const {
    return "The element was not in the list!!";
}