#include "Queue.h"
#include <iostream>
#include <string>

template<class T>
Queue<T>::Queue() : front(0), rear(0) {
}

template<class T>
Queue<T>::~Queue() {
    QueueNode<T>* current = front;
    while (current != 0) {
        QueueNode<T>* next = current->next;
        delete current;
        current = next;
    }
}

template<class T>
Queue<T>& Queue<T>::operator+=(T& data) {
    QueueNode<T>* newNode = new QueueNode<T>();
    newNode->data = data;
    newNode->next = 0;
    
    if (rear == 0) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    
    return *this;
}

template<class T>
Queue<T>& Queue<T>::operator-=(T& data) {
    if (front == 0) {
        return *this;
    }
    
    data = front->data;
    QueueNode<T>* temp = front;
    front = front->next;
    
    if (front == 0) {
        rear = 0;
    }
    
    delete temp;
    return *this;
}

template<class T>
const T& Queue<T>::operator[](int index) const {
    if (index < 0) {
        throw InvalidIndexException(index);
    }
    
    QueueNode<T>* current = front;
    int count = 0;
    while (current != 0) {
        if (count == index) {
            return current->data;
        }
        current = current->next;
        count++;
    }
    throw InvalidIndexException(index);
}

template<class T>
T& Queue<T>::operator[](int index) {
    if (index < 0) {
        throw InvalidIndexException(index);
    }
    
    QueueNode<T>* current = front;
    int count = 0;
    while (current != 0) {
        if (count == index) {
            return current->data;
        }
        current = current->next;
        count++;
    }
    throw InvalidIndexException(index);
}

template<class T>
Queue<T>* Queue<T>::clone() {
    Queue<T>* newQueue = new Queue<T>();
    QueueNode<T>* current = front;
    while (current != 0) {
        T data = current->data;
        *newQueue += data;
        current = current->next;
    }
    return newQueue;
}

template<class T>
Queue<T>::operator int() const {
    int count = 0;
    QueueNode<T>* current = front;
    while (current != 0) {
        count++;
        current = current->next;
    }
    return count;
}

template<class T>
std::ostream& Queue<T>::print(std::ostream& out) const {
    if (front == 0) {
        out << "EMPTY";
        return out;
    }
    
    QueueNode<T>* current = front;
    bool first = true;
    while (current != 0) {
        if (!first) {
            out << ",";
        }
        out << current->data;
        first = false;
        current = current->next;
    }
    return out;
}