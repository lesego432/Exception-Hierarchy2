#ifndef TOOMANYPRINTERSDELETED_H
#define TOOMANYPRINTERSDELETED_H

#include "Exception.h"

class TooManyPrintersDeleted : public Exception {
public:
    virtual std::string getMessage() const;
};

#endif