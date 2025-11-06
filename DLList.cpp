#ifndef DLLIST_CPP
#define DLLIST_CPP

#include "DLList.h"
#include "InvalidIndexException.h"
#include "ElementNotInListException.h"


template <class T>
DLList<T>::DLList() : head(NULL) {
}

template <class T>
DLList<T>::~DLList() {
    if (head == NULL) {
        return;
    }
    DLLNode<T>* current = head;
    while (current != NULL) {
        DLLNode<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <class T>
DLList<T>& DLList<T>::operator+=(T& data) {
    DLLNode<T>* newNode = new DLLNode<T>();
    if (newNode == NULL) {
        return *this;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
        return *this;
    }
    if (data < head->data) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return *this;
    }
    DLLNode<T>* current = head;
    if (current == NULL) {
        return *this;
    }
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    if (current != NULL) {
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }

        current->next = newNode;
    }
    return *this;
}

template <class T>
DLList<T>& DLList<T>::operator-=(T& data) {
    if (head == NULL) {
        throw ElementNotInListException();
    }
    DLLNode<T>* current = head;
    DLLNode<T>* temp = NULL;
    while (current != NULL) {
        if (current->data == data) {
            temp = current;
            break;
        }
        current = current->next;
    }
    if (temp == NULL) {
        throw ElementNotInListException();
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
    return *this;
}

template <class T>
const T& DLList<T>::operator[](int index) const {
    if (index < 0) {
        throw InvalidIndexException(index, false);
    }
    if (head == NULL) {
        throw InvalidIndexException(index, false);
    }
    DLLNode<T>* current = head;
    int position = 0;

    while (current != NULL && position < index) {
        current = current->next;
        position++;
    }
    if (current == NULL) {
        throw InvalidIndexException(index, false);
    }
    return current->data;
}


template <class T>
T& DLList<T>::operator[](int index) {
    if (index < 0) {
        throw InvalidIndexException(index, false);
    }
    if (head == NULL) {
        throw InvalidIndexException(index, false);
    }
    DLLNode<T>* current = head;
    int position = 0;

    while (current != NULL && position < index) {
        current = current->next;
        position++;
    }
    if (current == NULL) {
        throw InvalidIndexException(index, false);
    }

    return current->data;
}

template <class T>
DLList<T>* DLList<T>::clone() {
    DLList<T>* newList = new DLList<T>();
    if (newList == NULL) {
        return NULL;
    }
    if (head == NULL) {
        return newList;
    }
    DLLNode<T>* current = head;
    while (current != NULL) {
        *newList += current->data;
        current = current->next;
    }
    return newList;
}

template <class T>
DLList<T>::operator int() const {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    DLLNode<T>* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

template <class T>
std::ostream& DLList<T>::print(std::ostream& out) const {
    if (head == NULL) {
        return out;
    }
    DLLNode<T>* current = head;
    bool isFirst = true;
    while (current != NULL) {
        if (!isFirst) {
            out << ",";
        }
        out << current->data;
        isFirst = false;
        current = current->next;
    }
    return out;
}

#endif
