#include "TooManyPrintersDeleted.h"
#include <string>

std::string TooManyPrintersDeleted::getMessage() const {
    return "More printer references were returned than were requested.";
}
