/**
 This code reflects my own understanding. I can explain every function, data structure, and design decision.
 */
#pragma once


#include "Node.h"
#include <stdexcept>
#include "QueueInterface.h"

/*
why queue?
 - print job scheduling
 - operating system task scheduling
 - network packet handling 
 - breadth-first search (graphs)
 - call centers, ticket counters, hospital triage
*/

using namespace std;

template <typename T>
class LinkedQueue : public QueueInterface<T>{

private:
    Node<T>* head;
    Node<T>* tail;

public:

    LinkedQueue();

    void enqueue(const T& value);   // add to rear

    void dequeue();          // remove front node

    T peek() const;                // view front value

    bool isEmpty() const;
};


//implementation

template <typename T>
LinkedQueue<T>::LinkedQueue() {
    head = nullptr;
    tail = nullptr;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& value) {

    Node<T>* newNode = new Node<T>(value);

    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

template <typename T>
T LinkedQueue<T>::peek() const {

    if (head == nullptr) {
        throw runtime_error("Queue is empty");
    }

    return head->getData();
}

template <typename T>
void LinkedQueue<T>::dequeue() {

    if (head == nullptr) {
        throw runtime_error("Queue is empty");
    }

    Node<T>* temp = head;

    head = head->getNext();

    // check if the queue becomes empty
    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
}
