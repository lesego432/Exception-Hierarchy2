#ifndef ITERATOR_H
#define ITERATOR_H

#include "OutOfBoundsException.h"

template<template <class> class Iterable, class T>
class Iterator {
private:
    Iterable<T> iterable;
    int currentPosition;

public:
    Iterator();
    Iterator<Iterable, T>& operator++(int i);
    Iterator<Iterable, T>& operator++();
    Iterator<Iterable, T>& operator--(int i);
    Iterator<Iterable, T>& operator--();
    operator T&();
    void setStart();
    void setEnd();
    bool isAtStart() const;
    bool isAtEnd() const;
    Iterator<Iterable, T>& operator+=(T &data);
    Iterator<Iterable, T>& operator-=(T &data);
};

#include "Iterator.cpp"

#endif