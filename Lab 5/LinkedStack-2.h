/**
 This code reflects my own understanding. I can explain every function, data structure, and design decision.
 */
//----------------LinkedStack.h-------------
#pragma once

#include "Node.h"
#include <stdexcept>
#include "StackInterface.h"

/*
why stack?
 - call stack
 - undo, redo
 - checking balanced symbols
 - postfix notation
*/

using namespace std;

template <typename T>
class LinkedStack : public StackInterface<T> {
private:

    Node<T>* top;

public:
    LinkedStack();
    void push(const T& value);
    T peek() const;
    void pop();
    bool isEmpty() const;
};


//implementation

template<typename T>
LinkedStack<T>::LinkedStack() {
    top = nullptr;
}



template<typename T>
void LinkedStack<T>::push(const T& value) {

    //complete this method

    Node<T>* newNode = new Node<T>(value);

    newNode->setNext(top);

    top = newNode;

}


template<typename T>
T LinkedStack<T>::peek() const {

    //complete this method
    if (isEmpty())
        throw runtime_error("stack is empty, can't peek");

    return top->getData();
}


template<typename T>
void LinkedStack<T>::pop() {

    if (isEmpty())
        throw runtime_error("can't pop from an empty stack");
    
    Node<T>* temp = top;
    top = top->getNext();
    delete temp;


}


template<typename T>
bool LinkedStack<T>::isEmpty() const {
    //complete this method
    return top == nullptr;
}

