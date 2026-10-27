//==========Node.h================

/**
 * @file Node.h
 * @brief Template node class for use in a doubly linked list.
 *
 * Each Node holds a data value of type T and two pointers:
 * one to the next node and one to the previous node in the list.
 * This bidirectional linking is what makes the doubly linked list
 * traversable in both directions.
 *
 * @author Kushal
 * @version 1.0
 */

#pragma once


template <typename T>
class Node {
private:
    T data;           ///< The value stored in this node
    Node<T>* next;    ///< Pointer to the next node in the list
    Node<T>* prev;    ///< Pointer to the previous node in the list
public:
    //constructors
    Node();
    Node(const T& data);

    //getters
    T getData() const;
    Node<T>* getNext() const;
    Node<T>* getPrev() const;

    //setters
    void setData(const T& newData);
    void setNext(Node<T>* newNext);
    void setPrev(Node<T>* newPrev);
};

/**
 * @brief Default constructor. Initializes next and prev to nullptr.
 *
 * Creates a node with no data and no connections.
 * Data is left as the default value of type T.
 */
template <typename T>
Node<T>::Node() {
    next = nullptr;
    prev = nullptr;
}

/**
 * @brief Parameterized constructor. Sets data and initializes pointers to nullptr.
 *
 * Creates a node with the given data value and no connections.
 * Both next and prev start as nullptr until the node is linked into a list.
 *
 * @param data The value to store in this node.
 */
template <typename T>
Node<T>::Node(const T& data) {
    this->data = data;
    prev = next = nullptr;
}

/**
 * @brief Returns the data value stored in this node.
 *
 * @return The data of type T held by this node.
 */
template <typename T>
T Node<T>::getData() const {
    return data;

}

/**
 * @brief Returns a pointer to the next node in the list.
 *
 * @return Pointer to the next Node, or nullptr if this is the tail.
 */
template<typename T>
Node<T>* Node<T>::getNext() const {
    return next;

}

/**
 * @brief Returns a pointer to the previous node in the list.
 *
 * @return Pointer to the previous Node, or nullptr if this is the head.
 */
template<typename T>
Node<T>* Node<T>::getPrev() const {
    return prev;

}

/**
 * @brief Sets the data value stored in this node.
 *
 * @param newData The new value to store.
 */
template<typename T>
void Node<T>::setData(const T& newData) {
    data = newData;
}

/**
 * @brief Sets the next pointer to point to another node.
 *
 * @param newNext Pointer to the node that should follow this one.
 */
template<typename T>
void Node<T>::setNext(Node<T>* newNext) {
    next = newNext;
}

/**
 * @brief Sets the prev pointer to point to another node.
 *
 * @param newPrev Pointer to the node that should precede this one.
 */
template<typename T>
void Node<T>::setPrev(Node<T>* newPrev) {
    prev = newPrev;
}
