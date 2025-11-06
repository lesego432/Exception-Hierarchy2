#include "Iterator.h"
#include "OutOfBoundsException.h"
#include <iostream>
#include <string>

template<template <class> class Iterable, class T>
Iterator<Iterable, T>::Iterator() : currentPosition(0) {
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator++(int i) {
    if (currentPosition >= (int)iterable) {
        throw OutOfBoundsException();
    }
    currentPosition++;
    return *this;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator++() {
    if (currentPosition >= (int)iterable) {
        throw OutOfBoundsException();
    }
    currentPosition++;
    return *this;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator--(int i) {
    if (currentPosition <= 0) {
        throw OutOfBoundsException();
    }
    currentPosition--;
    return *this;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator--() {
    if (currentPosition <= 0) {
        throw OutOfBoundsException();
    }
    currentPosition--;
    return *this;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>::operator T&() {
    return iterable[currentPosition];
}

template<template <class> class Iterable, class T>
void Iterator<Iterable, T>::setStart() {
    currentPosition = 0;
}

template<template <class> class Iterable, class T>
void Iterator<Iterable, T>::setEnd() {
    currentPosition = (int)iterable;
}

template<template <class> class Iterable, class T>
bool Iterator<Iterable, T>::isAtStart() const {
    return currentPosition == 0;
}

template<template <class> class Iterable, class T>
bool Iterator<Iterable, T>::isAtEnd() const {
    return currentPosition == (int)iterable;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator+=(T &data) {
    iterable += data;
    return *this;
}

template<template <class> class Iterable, class T>
Iterator<Iterable, T>& Iterator<Iterable, T>::operator-=(T &data) {
    iterable -= data;
    return *this;
}