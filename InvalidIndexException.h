#ifndef INVALIDINDEXEXCEPTION_H
#define INVALIDINDEXEXCEPTION_H

#include "Exception.h"

class InvalidIndexException : public Exception {
private:
    int index;
    bool isNull;

public:
    InvalidIndexException(int index, bool isNull = false);
    virtual std::string getMessage() const;
};

#endif