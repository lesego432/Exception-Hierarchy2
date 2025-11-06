#ifndef PRINTER_H
#define PRINTER_H

#include "Iterator.h"
#include "TooManyPrintersDeleted.h"
#include "PrinterNotInitialized.h"
#include "InvalidIndexException.h"
#include <fstream>

template<template <class> class Iterable, class T>
class Printer {
private:
    static Printer<Iterable, T>* printer;
    static int numberOfRequests;
    Iterator<Iterable, T> printerQueue;
    Printer();

public:
    static Printer<Iterable, T>& requestPrinter();
    static void returnPrinter();
    void insertDocument(T &data);
    void printToStream(std::ostream &out);
    void printToFile(std::fstream &f);
    int numberOfDocuments();
    bool isInQueue(T &data);
};

#include "Printer.cpp"

#endif