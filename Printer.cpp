#include "Printer.h"
#include "TooManyPrintersDeleted.h"
#include "PrinterNotInitialized.h"
#include "InvalidIndexException.h"
#include <iostream>
#include <string>
#include <fstream>

template<template <class> class Iterable, class T>
Printer<Iterable, T>* Printer<Iterable, T>::printer = 0;

template<template <class> class Iterable, class T>
int Printer<Iterable, T>::numberOfRequests = 0;

template<template <class> class Iterable, class T>
Printer<Iterable, T>::Printer() {
}

template<template <class> class Iterable, class T>
Printer<Iterable, T>& Printer<Iterable, T>::requestPrinter() {
    if (printer == 0) {
        printer = new Printer<Iterable, T>();
    }
    numberOfRequests++;
    return *printer;
}

template<template <class> class Iterable, class T>
void Printer<Iterable, T>::returnPrinter() {
    numberOfRequests--;
    if (numberOfRequests < 0) {
        throw TooManyPrintersDeleted();
    }
    if (numberOfRequests == 0) {
        delete printer;
        printer = 0;
    }
}

template<template <class> class Iterable, class T>
void Printer<Iterable, T>::insertDocument(T &data) {
    if (printer == 0) {
        throw PrinterNotInitialized();
    }
    printerQueue += data;
}

template<template <class> class Iterable, class T>
void Printer<Iterable, T>::printToStream(std::ostream &out) {
    printerQueue.setStart();
    while (!printerQueue.isAtEnd()) {
        try {
            out << (T&)printerQueue << std::endl;
        } catch (const InvalidIndexException&) {
            out << "0" << std::endl;
        }
        printerQueue++;
    }
}

template<template <class> class Iterable, class T>
void Printer<Iterable, T>::printToFile(std::fstream &f) {
    printerQueue.setStart();
    while (!printerQueue.isAtEnd()) {
        f << (T&)printerQueue << std::endl;
        printerQueue++;
    }
}

template<template <class> class Iterable, class T>
int Printer<Iterable, T>::numberOfDocuments() {
    int count = 0;
    printerQueue.setStart();
    while (!printerQueue.isAtEnd()) {
        count++;
        printerQueue++;
    }
    return count;
}

template<template <class> class Iterable, class T>
bool Printer<Iterable, T>::isInQueue(T &data) {
    printerQueue.setStart();
    while (!printerQueue.isAtEnd()) {
        if ((T&)printerQueue == data) {
            return true;
        }
        printerQueue++;
    }
    return false;
}