#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>

class Exception {
public:
    virtual ~Exception()=0;
    friend std::ostream& operator<<(std::ostream& out, const Exception& e);
    virtual std::string getMessage()const = 0;
};

#endif