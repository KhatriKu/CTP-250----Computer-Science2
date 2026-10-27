//----------------QueueInterface.h---------------------
/**
 This code reflects my own understanding. I can explain every function, data structure, and design decision.
 */

#pragma once


template <typename T>
class QueueInterface {

public:

    virtual bool isEmpty() const = 0;

    virtual void enqueue(const T& value) = 0;

    virtual void dequeue() = 0;

    virtual T peek() const = 0;

    virtual ~QueueInterface() {}

};

