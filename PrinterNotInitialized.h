#ifndef PRINTERNOTINITIALIZED_H
#define PRINTERNOTINITIALIZED_H

#include "Exception.h"

class PrinterNotInitialized : public Exception {
public:
    virtual std::string getMessage() const;
};

#endif