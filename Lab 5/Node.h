//--------------Node.h-------------
/**
 This code reflects my own understanding. I can explain every function, data structure, and design decision.
 */
#pragma once

template <typename T>
class Node {
private:
    T data;
    Node<T>* next;

public:
    // constructor
    Node();

    // mutators
    void setNext(Node<T>* n);
    void setData(T value);

    // accessors
    Node<T>* getNext();
    T getData();
};




//implementation

template <typename T>
Node<T>::Node() {
    
    next = nullptr;
}

template <typename T>
void Node<T>::setNext(Node<T>* n) {
    next = n;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <typename T>
T Node<T>::getData() {
    return data;
}

template <typename T>
void Node<T>::setData(T value) {
    data = value;
}
