//==============DoublyLinkedList.h======================

/**
 * @file DoublyLinkedList.h
 * @brief Template implementation of a doubly linked list.
 *
 * This class implements the DoublyLinkedListInterface and provides
 * a fully functional doubly linked list with head and tail pointers.
 * Supports insertion, deletion, access, traversal, and display in
 * both directions. All Part 3 concrete methods are included here as well.
 *
 * @author Kushal
 * @version 1.0
 */

#pragma once

#include "Node.h"
#include "DoublyLinkedListInterface.h"
#include <iostream>

using namespace std;


template <typename T>
class DoublyLinkedList : public DoublyLinkedListInterface<T> {
private:
    Node<T>* head;  ///< Pointer to the first node in the list
    Node<T>* tail;  ///< Pointer to the last node in the list

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    //interface methods - MUST look like the interface
    void add(const T& data);
    void display() const;

    void insertAtHead(const T& data);
    void insertAtTail(const T& data);
    void displayFromHead() const;
    void displayFromTail() const;
    
    
    //PART 3
    T getMax() const;   //returns the "largest" value in the list, for strings this means that "banana" is greater than "apple" alphabetically which is what we are going for here
    T getMin() const;  //returns the "smallest" value in the list, for strings the value which occurs closest to the beginning of the alphabet
    void displayFromNToEnd(int n) const;  //display from the nth value in the list to the end of the lisy
    void displayFromFrontToN(int n) const;  //display from head to the nth value in the list
    void displayNFromTail(int n) const;  //display n items from tail toward head
    void displayFromNToM(int n, int m) const;  //displays from the nth index to the mth index, you will need to check if n < m or if n > m since this will determine your traversals
    
    // Insertion
    void insertAt(int index, const T& val);

    // Removal
    void deleteFront();
    void deleteTail();
    void deleteAt(int index);
    
    //NOTE: I HAD TO CHANGE THE NAME FROM "delete" as it is a C++ RESERVED WORD
    void deleteValue(const T& val);

    // Access
    T getFront() const;     //NOTE- this is not Node<T>* getFront();
    T getLast() const;      //NOTE - this is not Node<T>* getLast();
    T at(int index) const;  //NOTE - this is not Node<T>* at(int index)


    // Utility
    int size() const;
    bool isEmpty() const;
    bool contains(const T& val) const;
    void clear();
};


/**
 * @brief Default constructor. Initializes head and tail to nullptr.
 *
 * Sets up an empty list with no nodes. Both head and tail are set
 * to nullptr to represent an empty state.
 */
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    //how to initialize the pointers?
    head = tail = nullptr;
}

/**
 * @brief Destructor. Frees all dynamically allocated nodes.
 *
 * Traverses the list from head to tail, deleting each node.
 * Uses a temporary pointer to preserve the next node before deletion
 * so that the traversal is not broken.
 */
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    //delete all of the nodes

    Node<T>* current = head;
    while (current != nullptr) {
        // be careful!  head can be deleted
        Node<T>* next = current->getNext();  //option so that head is not deleted
        //head = head->getNext();
        delete current;
        //current = head;
        current = next;
    }
}

/**
 * @brief Inserts a new node at the head of the list.
 *
 * Creates a new node and places it before the current head.
 * If the list is empty, the new node becomes both head and tail.
 *
 * @param data The value to insert at the head.
 */
template <typename T>
void DoublyLinkedList<T>::insertAtHead(const T& data) {
    Node<T>* newNode = new Node<T>(data);

    if (head == nullptr)
        head = tail = newNode;
    else {
        newNode->setNext(head);
        head->setPrev(newNode);
        head = newNode;
    }
}

/**
 * @brief Inserts a new node at the tail of the list.
 *
 * Creates a new node and appends it after the current tail.
 * If the list is empty, the new node becomes both head and tail.
 *
 * @param data The value to insert at the tail.
 */
template <typename T>
void DoublyLinkedList<T>::insertAtTail(const T& data) {
    Node<T>* newNode = new Node<T>(data);

    if (tail == nullptr)
        head = tail = newNode;
    else {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;

    }

}

/**
 * @brief Default add method. Delegates to insertAtHead.
 *
 * Provides a generic insertion point. Currently inserts at head,
 * but can be swapped to insertAtTail by changing the call below.
 *
 * @param data The value to add to the list.
 */
template <typename T>
void DoublyLinkedList<T>::add(const T& data) {
    //insertAtTail(data);
     //OR
     insertAtHead(data);
}

/**
 * @brief Default display method. Delegates to displayFromTail.
 *
 * Provides a generic display point. Currently displays from tail,
 * but can be swapped to displayFromHead by changing the call below.
 */
template <typename T>
void DoublyLinkedList<T>::display() const {
    //we get to choose forward or backward
    //displayFromHead();
    //or
    displayFromTail();
}

/**
 * @brief Displays all elements from head to tail.
 *
 * Traverses the list starting at head, printing each node's data
 * using getNext() to move forward through the list.
 */
template <typename T>
void DoublyLinkedList<T>::displayFromHead() const {
    //display the list from head

    Node<T>* current = head;

    while (current != nullptr) {
        cout << current->getData();
        current = current->getNext();
    }
}

/**
 * @brief Displays all elements from tail to head.
 *
 * Traverses the list starting at tail, printing each node's data
 * using getPrev() to move backward through the list.
 */
template <typename T>
void DoublyLinkedList<T>::displayFromTail() const {
    Node<T>* current = tail;

    while (current != nullptr) {
        cout << current->getData();
        current = current->getPrev();
    }
}

/**
 * @brief Returns the largest value in the list.
 *
 * Traverses the entire list from head to tail, tracking the largest
 * value seen. For strings, comparison is alphabetical (e.g. "banana" > "apple").
 *
 * @return The maximum value found in the list.
 */
template <typename T>
T DoublyLinkedList<T>::getMax()const{
    Node<T>* current = head;
    T max = current->getData();
    while(current != nullptr){
        
        if(current->getData() > max){
            max = current->getData();
        }
        current = current->getNext();
    }
    
    return max;
    
}

/**
 * @brief Returns the smallest value in the list.
 *
 * Traverses the entire list from head to tail, tracking the smallest
 * value seen. For strings, comparison is alphabetical (e.g. "apple" < "banana").
 *
 * @return The minimum value found in the list.
 */
template <typename T>
T DoublyLinkedList<T>::getMin()const{
    Node<T>* current = head;
    T min = current->getData();
    while(current != nullptr){
        
        if(current->getData() < min){
            min = current->getData();
        }
        current = current->getNext();
    }
    
    return min;
    
}

/**
 * @brief Displays all elements from index n to the end of the list.
 *
 * Advances n steps from head, then prints every remaining node
 * to the end. If n is 0, the entire list is displayed.
 *
 * @param n The starting index (0-based) to display from.
 */
template <typename T>
void DoublyLinkedList<T>::displayFromNToEnd(int n) const{
    Node<T>* current = head;
    for(int i = 0; i < n && current != nullptr; i++){
        
        current = current->getNext();
        
    }
    while(current != nullptr){
        
        cout << current->getData() << "  |  ";
        current = current->getNext();
        
    }
    cout << endl;
}

/**
 * @brief Displays the first n elements from the head of the list.
 *
 * Starts at head and prints n nodes, advancing forward with getNext().
 * Does not guard against n exceeding list size — caller should validate.
 *
 * @param n The number of elements to display from the front.
 */
template <typename T>
void DoublyLinkedList<T>::displayFromFrontToN(int n) const{
    
    Node<T>* current = head;
    for(int i = 0; i< n; i++){
        cout << current->getData() << "  |  ";
        current = current->getNext();
    }
    cout << endl;
}

/**
 * @brief Displays n elements starting from the tail, moving toward head.
 *
 * Starts at tail and walks backward using getPrev(), printing n values.
 * Does not guard against n exceeding list size — caller should validate.
 *
 * @param n The number of elements to display from the tail.
 */
template <typename T>
void DoublyLinkedList<T>::displayNFromTail(int n) const{
    Node<T>* current = tail;
    for(int i = 0; i < n; i++){
        cout << current->getData() << "  |  ";
        current = current->getPrev();
    }
    cout << endl;
}

/**
 * @brief Displays elements between index n and index m (inclusive).
 *
 * Determines the lower and upper bounds from n and m (handles either order).
 * Advances to the lower index, then prints up to but not including the upper.
 * Works correctly whether n < m or n > m.
 *
 * @param n One endpoint of the display range (index).
 * @param m The other endpoint of the display range (index).
 */
template <typename T>
void DoublyLinkedList<T>::displayFromNToM(int n, int m) const{
    Node<T>* current = head;
    int max = 0;
    int min = 0;
    if(n > m){
        max = n;
        min = m;
    }
    else{
        max = m;
        min = n;
    }
    for(int i = 0; i < min;i++){
        current = current->getNext();
    }
    for(int i = 0;i < (max-min); i++){
        cout << current->getData() << "  |  ";
        current = current->getNext();
    }
    cout << endl;
}


/**
 * @brief Inserts a value at a specific index in the list.
 *
 * If the index is <= 0, inserts at head. If >= size, inserts at tail.
 * Otherwise, traverses to index-1 and splices the new node in between
 * the current node and its next, updating all prev/next pointers.
 *
 * @param index The position at which to insert (0-based).
 * @param val   The value to insert.
 */
template <typename T>
void DoublyLinkedList<T>::insertAt(int index, const T& val){
    
    if (index <= 0) {
            insertAtHead(val);
            return;
        }
        if (index >= this->size()) {
            insertAtTail(val);
            return;
        }

        Node<T>* newNode = new Node<T>(val);
        Node<T>* current = head;

        for (int i = 0; i < index - 1 && current != nullptr; i++) {
            current = current->getNext();
        }

       
        Node<T>* nextNode = current->getNext();

        current->setNext(newNode);
        newNode->setPrev(current);
        newNode->setNext(nextNode);
        if (nextNode != nullptr) {
            nextNode->setPrev(newNode);
        } else {
            tail = newNode;
        }
}

/**
 * @brief Removes the node at the front of the list.
 *
 * Saves the head pointer, advances head to the next node, and
 * clears the new head's prev pointer. If the list becomes empty,
 * tail is also set to nullptr. The old head node is deleted.
 */
template <typename T>
void DoublyLinkedList<T>::deleteFront(){
    if (head == nullptr) {
        return;
    }

        Node<T>* current = head;
        head = head->getNext();

        if (head != nullptr) {
            head->setPrev(nullptr);
        } else {
            tail = nullptr;
        }
        delete current;
}

/**
 * @brief Removes the node at the tail of the list.
 *
 * Saves the tail pointer, moves tail back to the previous node, and
 * clears the new tail's next pointer. If the list becomes empty,
 * head is also set to nullptr. The old tail node is deleted.
 */
template <typename T>
void DoublyLinkedList<T>::deleteTail(){
    if (tail == nullptr) {
        return;
    }

    Node<T>* current = tail;
        tail = tail->getPrev();

    if (tail != nullptr) {
            tail->setNext(nullptr);
    } else {
        head = nullptr;
    }
    delete current;
}

/**
 * @brief Removes the node at a specific index.
 *
 * Delegates to deleteFront() or deleteTail() for edge indices.
 * Otherwise, traverses to the target index, unlinks the node by
 * reconnecting its neighbors' prev/next pointers, then deletes it.
 *
 * @param index The 0-based index of the node to remove.
 */
template <typename T>
void DoublyLinkedList<T>::deleteAt(int index){
    if (head == nullptr) {
        return;
    }
    if (index <= 0) {
            deleteFront();
            return;
        }
    if (index >= this->size() - 1) {
            deleteTail(); return;
        }

    Node<T>* current = head;
    for (int i = 0; i < index && current != nullptr; i++) {
            current = current->getNext();
        }
    if (current == nullptr) {
        return;
    }
        Node<T>* prevNode = current->getPrev();
        Node<T>* nextNode = current->getNext();

    if (prevNode != nullptr) {
        prevNode->setNext(nextNode);
    }
    if (nextNode != nullptr) {
        nextNode->setPrev(prevNode);
    }
        delete current;
}

/**
 * @brief Removes the first node whose data matches the given value.
 *
 * Traverses from head, comparing each node's data to val.
 * When found, unlinks the node by updating its neighbors' pointers,
 * updates head or tail if needed, and deletes the node.
 * NOTE: renamed from "delete" because delete is a C++ reserved word.
 *
 * @param val The value to search for and remove.
 */
template <typename T>
void DoublyLinkedList<T>::deleteValue(const T& val){
    Node<T>* current = head;
        while (current != nullptr) {
            if (current->getData() == val) {
                Node<T>* prevNode = current->getPrev();
                Node<T>* nextNode = current->getNext();
                if (prevNode != nullptr)
                {
                    prevNode->setNext(nextNode);
                }
                else {
                    head = nextNode;
                }
                if (nextNode != nullptr) {
                    nextNode->setPrev(prevNode);
                }
                else{
                    tail = prevNode;
                    
                }
                delete current;
                return;
            }
            current = current->getNext();
        }
}

/**
 * @brief Returns the data stored in the front (head) node.
 *
 * NOTE: This returns the data value T, not a Node pointer.
 *
 * @return The value stored at the head of the list.
 */
template <typename T>//NOTE- this is not Node<T>* getFront();
T DoublyLinkedList<T>::getFront() const{
    return head->getData();
}

/**
 * @brief Returns the data stored in the last (tail) node.
 *
 * NOTE: This returns the data value T, not a Node pointer.
 *
 * @return The value stored at the tail of the list.
 */
template <typename T>//NOTE - this is not Node<T>* getLast();
T DoublyLinkedList<T>::getLast() const{
    return tail->getData();
}

/**
 * @brief Returns the data at a specific index in the list.
 *
 * Traverses from head, advancing index times using getNext().
 * NOTE: This returns the data value T, not a Node pointer.
 *
 * @param index The 0-based position to retrieve.
 * @return The value stored at the given index.
 */
template <typename T>//NOTE - this is not Node<T>* at(int index)
T DoublyLinkedList<T>::at(int index) const{
    Node<T>*current = head;
        for(int i = 0; i< index && current != nullptr; i++){
            current = current->getNext();
        }
        return current->getData();
}

/**
 * @brief Returns the number of nodes in the list.
 *
 * Traverses from head to nullptr, incrementing a counter for each node.
 * Counts all nodes including the tail.
 *
 * @return The total number of elements in the list.
 */
template <typename T>
int DoublyLinkedList<T>::size() const{
    Node<T>*current = head;
    int size = 0;
    while(current !=nullptr){
        current = current->getNext();
        size++;
    }
    return size;
}

/**
 * @brief Checks whether the list contains any nodes.
 *
 * Returns true only when both head and tail are nullptr,
 * meaning no nodes have been inserted or all have been removed.
 *
 * @return true if the list is empty, false otherwise.
 */
template <typename T>
bool DoublyLinkedList<T>::isEmpty() const{
    
    if(head == nullptr && tail == nullptr){
        return true;
    }
    else{
        return false;
    }
    
}

/**
 * @brief Checks whether a given value exists anywhere in the list.
 *
 * Traverses from head to nullptr, comparing each node's data to val.
 * Returns true as soon as a match is found, false if the full list
 * is traversed without finding a match.
 *
 * @param val The value to search for.
 * @return true if the value is found, false otherwise.
 */
template <typename T>
bool DoublyLinkedList<T>::contains(const T& val) const{
    Node<T>*current = head;
    while(current !=nullptr){
        if(current->getData() == val){
            return true;
        }
        current = current->getNext();
    }
    return false;
    
}

/**
 * @brief Deletes all nodes and resets the list to an empty state.
 *
 * Traverses from head to nullptr, saving each next pointer before
 * deleting the current node, then sets both head and tail to nullptr.
 */
template <typename T>
void DoublyLinkedList<T>::clear(){
    Node<T>*current = head;
    while(current != nullptr){
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
    head = tail = nullptr;
    
}
