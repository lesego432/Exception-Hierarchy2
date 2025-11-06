#include "PrinterNotInitialized.h"
#include <string>

std::string PrinterNotInitialized::getMessage() const {
    return "No requested printer!!!";
}