#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <iostream>
#include "List.h"
#include "InvalidIndexException.h"

template <class T>
struct QueueNode{
    T data;
    QueueNode<T>* next;
};

template <class T>
class Queue : public List<T>{
    private:
        QueueNode<T>* front;
        QueueNode<T>* rear;

    protected:
    std::ostream& print(std::ostream& out) const;
    public:
        Queue();
        virtual ~Queue();
        virtual Queue<T>& operator+=(T& data);
        virtual Queue<T>& operator-=(T& data);
        virtual const T& operator[](int index)const;
        virtual T& operator[](int index);
        virtual Queue<T>* clone();
        virtual operator int()const;

};
#include "Queue.cpp"

#endif