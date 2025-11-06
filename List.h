#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "Exception.h"
#include "InvalidIndexException.h"

using namespace std;

template <class T>
class List;

template <class T>
std::ostream& operator<<(std::ostream& out, const List<T>& list);

template<class T>
class List {
public:
    virtual ~List();

    virtual List<T> &operator+=(T &data) = 0;

    virtual List &operator-=(T &data) = 0;

    virtual const T &operator[](int index) const = 0;

    virtual T &operator[](int index) = 0;

    virtual List<T> *clone() = 0;

    virtual operator int() const =0;

    template<class U>
    friend std::ostream &operator<<(std::ostream &out, const List<U> &list);

    template<class U>
    bool operator==(const U &rhs) const;

protected:
    virtual std::ostream &print(std::ostream &out) const =0;
};

#include "List.cpp"

#endif /*LIST_H*/