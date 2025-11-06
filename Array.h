#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include "Exception.h"
#include "ElementNotInListException.h"
#include "InvalidIndexException.h"
#include "InvalidSizeException.h"

template <class T>
class Array;

template <class T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array);

template<class T>
class Array {
public:
    Array(int size = 1);

    virtual ~Array();

    int numElements() const;

    operator int() const;

    virtual Array<T> &operator+=(T &d);

    virtual Array<T> &operator-=(T &d);

    virtual const T &operator[](int index) const;

    virtual T &operator[](int index);

    virtual Array<T> *clone();

    // This is a slightly different way of declaring the operator<< compared to the slides.
    // Note: In EOs, you should follow the format shown in the lecture slides
    template<class U>
    friend std::ostream &operator<<(std::ostream &out, const Array<U> &array);

    template<class U>
    bool operator==(const U &rhs) const;

private:
    T **data;
    int size;
};


#include "Array.cpp"

#endif /*ARRAY_H*/