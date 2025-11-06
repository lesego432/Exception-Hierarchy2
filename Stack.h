#ifndef STACK_H
#define STACK_H
#include <string>
#include <iostream>
#include "List.h"
#include "InvalidIndexException.h"

template <class T>
struct StackNode{
    T data;
    StackNode<T>* next;
};

template <class T>
class Stack : public List<T>{
    private:
        StackNode<T>* top;
    protected:
        std::ostream& print(std::ostream& out) const;

    public:
        Stack();
        virtual ~Stack();
        virtual Stack<T>& operator+=(T& data);
        virtual Stack<T>& operator-=(T& data);
        virtual const T& operator[](int index) const;
        virtual T& operator[](int index);
        virtual Stack<T>* clone();
        virtual operator int() const;
};
#include "Stack.cpp"

#endif