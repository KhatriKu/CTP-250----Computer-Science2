/**
 * @file DoublyLInkedListInterface.h
 * @brief Abstract interface for a doubly linked list.
 *
 * Defines the contract that any doubly linked list implementation must follow.
 * All methods are pure virtual, meaning DoublyLinkedList must override every
 * one of them to be a concrete (instantiable) class.
 *
 * Note: "delete" was renamed to "deleteValue" throughout this interface
 * because "delete" is a reserved keyword in C++.
 *
 * @author Kushal
 * @version 1.0
 */

#pragma once

template <typename T>
class DoublyLinkedListInterface {
public:

    // ── Insertion ─────────────────────────────────────────────────────────────

    /**
     * @brief Inserts a value at the head of the list.
     * @param val The value to insert.
     */
    virtual void insertAtHead(const T& val) = 0;

    /**
     * @brief Inserts a value at the tail of the list.
     * @param val The value to insert.
     */
    virtual void insertAtTail(const T& val) = 0;

    /**
     * @brief Inserts a value at a specific index in the list.
     * @param index The 0-based position to insert at.
     * @param val   The value to insert.
     */
    virtual void insertAt(int index, const T& val) = 0;

    // ── Removal ───────────────────────────────────────────────────────────────

    /**
     * @brief Removes the node at the front of the list.
     */
    virtual void deleteFront() = 0;

    /**
     * @brief Removes the node at the tail of the list.
     */
    virtual void deleteTail() = 0;

    /**
     * @brief Removes the node at a specific index.
     * @param index The 0-based index of the node to remove.
     */
    virtual void deleteAt(int index) = 0;

    /**
     * @brief Removes the first node whose data matches the given value.
     *
     * NOTE: renamed from "delete" because delete is a C++ reserved word.
     *
     * @param val The value to search for and remove.
     */
    virtual void deleteValue(const T& val) = 0;

    // ── Access ────────────────────────────────────────────────────────────────

    /**
     * @brief Returns the data stored at the front of the list.
     *
     * NOTE: returns data value T, not a Node pointer.
     *
     * @return The value at the head.
     */
    virtual T getFront() const = 0;

    /**
     * @brief Returns the data stored at the tail of the list.
     *
     * NOTE: returns data value T, not a Node pointer.
     *
     * @return The value at the tail.
     */
    virtual T getLast() const = 0;

    /**
     * @brief Returns the data at a specific index.
     *
     * NOTE: returns data value T, not a Node pointer.
     *
     * @param index The 0-based position to access.
     * @return The value at the given index.
     */
    virtual T at(int index) const = 0;

    // ── Utility ───────────────────────────────────────────────────────────────

    /**
     * @brief Returns the number of nodes in the list.
     * @return The total element count.
     */
    virtual int size() const = 0;

    /**
     * @brief Returns true if the list has no nodes.
     * @return true if empty, false otherwise.
     */
    virtual bool isEmpty() const = 0;

    /**
     * @brief Returns true if the given value exists anywhere in the list.
     * @param val The value to search for.
     * @return true if found, false otherwise.
     */
    virtual bool contains(const T& val) const = 0;

    /**
     * @brief Removes all nodes and resets the list to an empty state.
     */
    virtual void clear() = 0;

    // ── Output ────────────────────────────────────────────────────────────────

    /**
     * @brief Displays all elements from head to tail.
     */
    virtual void displayFromHead() const = 0;

    /**
     * @brief Displays all elements from tail to head.
     */
    virtual void displayFromTail() const = 0;

};
