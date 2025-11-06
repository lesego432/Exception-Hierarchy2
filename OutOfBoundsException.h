#ifndef OUTOFBOUNDSEXCEPTION_H
#define OUTOFBOUNDSEXCEPTION_H

#include "Exception.h"

class OutOfBoundsException : public Exception {
public:
    virtual std::string getMessage() const;
};

#endif