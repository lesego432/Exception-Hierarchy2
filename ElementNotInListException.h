#ifndef ELEMENTNOTINLISTEXCEPTION_H
#define ELEMENTNOTINLISTEXCEPTION_H

#include "Exception.h"

class ElementNotInListException : public Exception{
public:
    virtual std::string getMessage() const;
};

#endif