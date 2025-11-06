#include "Array.h"
#include <iostream>
#include <string>

template<class T>
Array<T>::Array(int size) : size(size) {
    if (size <= 0) {
        throw InvalidSizeException(size);
    }
    data = new T*[size];
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

template<class T>
Array<T>::~Array() {
    for (int i = 0; i < size; i++) {
        delete data[i];
    }
    delete[] data;
}

template<class T>
int Array<T>::numElements() const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] != 0) {
            count++;
        }
    }
    return count;
}

template<class T>
Array<T>::operator int() const {
    return size;
}

template<class T>
Array<T>& Array<T>::operator+=(T& d) {
    for (int i = 0; i < size; i++) {
        if (data[i] == 0) {
            data[i] = new T(d);
            return *this;
        }
    }
    
    int newSize = size * 2;
    T** newData = new T*[newSize];
    
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    
    for (int i = size; i < newSize; i++) {
        newData[i] = 0;
    }
    
    newData[size] = new T(d);
    
    delete[] data;
    data = newData;
    size = newSize;
    
    return *this;
}

template<class T>
Array<T>& Array<T>::operator-=(T& d) {
    bool found = false;
    int elementIndex = -1;
    
    for (int i = 0; i < size; i++) {
        if (data[i] != 0 && *(data[i]) == d) {
            found = true;
            elementIndex = i;
            break;
        }
    }
    
    if (!found) {
        throw ElementNotInListException();
    }
    
    delete data[elementIndex];
    data[elementIndex] = 0;
    
    int nonNullCount = numElements();
    if (nonNullCount < size / 2) {
        int newSize = size / 2;
        if (newSize < 1) newSize = 1;
        
        T** newData = new T*[newSize];
        
        int newIndex = 0;
        for (int i = 0; i < size; i++) {
            if (data[i] != 0) {
                newData[newIndex] = data[i];
                newIndex++;
            }
        }
        
        for (int i = newIndex; i < newSize; i++) {
            newData[i] = 0;
        }
        
        delete[] data;
        data = newData;
        size = newSize;
    }
    
    return *this;
}

template<class T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= size || data[index] == 0) {
        throw InvalidIndexException(index, data[index] == 0);
    }
    return *(data[index]);
}

template<class T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= size || data[index] == 0) {
        throw InvalidIndexException(index, data[index] == 0);
    }
    return *(data[index]);
}

template<class T>
Array<T>* Array<T>::clone() {
    Array<T>* newArray = new Array<T>(size);
    
    for (int i = 0; i < size; i++) {
        delete newArray->data[i];
        if (data[i] != 0) {
            newArray->data[i] = new T(*(data[i]));
        } else {
            newArray->data[i] = 0;
        }
    }
    
    return newArray;
}

template<class T>
template<class U>
bool Array<T>::operator==(const U& rhs) const {
    try {
        if (size != (int)rhs) {
            return false;
        }
        
        for (int i = 0; i < size; i++) {
            if (data[i] == 0) {
                if (!(rhs[i] == 0)) {
                    return false;
                }
            } else {
                if (!(*(data[i]) == rhs[i])) {
                    return false;
                }
            }
        }
        return true;
    } catch (const Exception&) {
        return false;
    }
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array) {
    bool first = true;
    for (int i = 0; i < array.size; i++) {
        if (!first) {
            out << ",";
        }
        if (array.data[i] == 0) {
            out << "0";
        } else {
            out << *(array.data[i]);
        }
        first = false;
    }
    return out;
}