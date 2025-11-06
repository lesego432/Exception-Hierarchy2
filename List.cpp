#include "List.h"
#include <iostream>
#include <string>

template<class T>
List<T>::~List() {
}

template<class T>
template<class U>
bool List<T>::operator==(const U& rhs) const {
    try {
        int mySize = (int)*this;
        int rhsSize = (int)rhs;
        if (mySize != rhsSize) {
            return false;
        }
        for (int i = 0; i < mySize; i++) {
            if (!((*this)[i] == rhs[i])) {
                return false;
            }
        }
        return true;
    } catch (const Exception&) {
        return false;
    }
}

template<class T>
std::ostream& operator<<(std::ostream& out, const List<T>& list) {
    return list.print(out);
}

template<class T>
std::ostream& List<T>::print(std::ostream& out) const {
    int size = (int)*this;
    if (size == 0) {
        out << "EMPTY";
        return out;
    }
    
    bool first = true;
    for (int i = 0; i < size; i++) {
        if (!first) {
            out << ",";
        }
        out << (*this)[i];
        first = false;
    }
    return out;
}