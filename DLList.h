#ifndef DLLIST_H
#define DLLIST_H

#include <string>
#include <iostream>
#include "List.h"
#include "ElementNotInListException.h"
#include "InvalidIndexException.h"

class list;

template <class T>
struct DLLNode{
    T data;
    DLLNode<T>* next;
    DLLNode<T>* prev;
};

template <class T>
class DLList : public List<T>{
    private:
        DLLNode<T>* head;
        
    protected:
       std::ostream& print(std::ostream &out) const;
    public:
        DLList();
        virtual ~DLList();
        virtual DLList<T>& operator+=(T& data);
        virtual DLList<T>& operator-=(T& data);
        virtual const T& operator[](int index) const;
        virtual T& operator[](int index);
        virtual DLList<T>* clone();
        virtual operator int() const;
}; 

#include "DLList.cpp"

#endif