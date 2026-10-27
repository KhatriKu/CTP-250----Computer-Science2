//------------StackInterface.h------------------
/**
 This code reflects my own understanding. I can explain every function, data structure, and design decision.
 */
#pragma once


template <typename T>
class StackInterface {

public:

    virtual bool isEmpty() const = 0;

    virtual void push(const T& value) = 0;

    virtual void pop() = 0;

    virtual T peek() const = 0;

    virtual ~StackInterface() {}
};




