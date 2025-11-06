#ifndef INVALIDSIZEEXCEPTION_H
#define INVALIDSIZEEXCEPTION_H

#include "Exception.h"

class InvalidSizeException : public Exception {
private:
    int size;
public:
    InvalidSizeException(int size);
    virtual std::string getMessage() const;
};

#endif