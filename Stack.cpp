#include "Stack.h"
#include <iostream>
#include <string>

template<class T>
Stack<T>::Stack() : top(0) {
}

template<class T>
Stack<T>::~Stack() {
    StackNode<T>* current = top;
    while (current != 0) {
        StackNode<T>* next = current->next;
        delete current;
        current = next;
    }
}

template<class T>
Stack<T>& Stack<T>::operator+=(T& data) {
    StackNode<T>* newNode = new StackNode<T>();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    return *this;
}

template<class T>
Stack<T>& Stack<T>::operator-=(T& data) {
    if (top == 0) {
        return *this;
    }
    
    data = top->data;
    StackNode<T>* temp = top;
    top = top->next;
    delete temp;
    return *this;
}

template<class T>
const T& Stack<T>::operator[](int index) const {
    if (index < 0) {
        throw InvalidIndexException(index);
    }
    
    StackNode<T>* current = top;
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
T& Stack<T>::operator[](int index) {
    if (index < 0) {
        throw InvalidIndexException(index);
    }
    
    StackNode<T>* current = top;
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
Stack<T>* Stack<T>::clone() {
    Stack<T>* newStack = new Stack<T>();
    StackNode<T>* current = top;
    Stack<T> tempStack;
    
    while (current != 0) {
        T data = current->data;
        tempStack += data;
        current = current->next;
    }
    
    current = tempStack.top;
    while (current != 0) {
        T data = current->data;
        *newStack += data;
        current = current->next;
    }
    
    return newStack;
}

template<class T>
Stack<T>::operator int() const {
    int count = 0;
    StackNode<T>* current = top;
    while (current != 0) {
        count++;
        current = current->next;
    }
    return count;
}

template<class T>
std::ostream& Stack<T>::print(std::ostream& out) const {
    if (top == 0) {
        out << "EMPTY";
        return out;
    }
    
    StackNode<T>* current = top;
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