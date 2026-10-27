#pragma once
#include <vector>
// This code reflects my own understanding.
// I can explain every function, data structure, and design decision.
/**
 * @file BagInterface.h
 * Abstract template interface for a Bag ADT.
 * @tparam T type of items stored in the bag
 *
 * A Bag is an unordered collection that may contain duplicates.
 * This interface defines common operations: add, getCurrentSize, isEmpty and clear.
 */
template<typename T>
class BagInterface {
public:
    virtual ~BagInterface() = default;

    virtual bool add(const T& item) = 0;

    virtual int getCurrentSize() const = 0;

    virtual bool isEmpty() const = 0;

    virtual void clear() = 0;

    virtual int getFrequencyOf(const T& item) const = 0;

    virtual bool contains(const T& item) const = 0;

    //added methods

    virtual bool removeLast() = 0;

    virtual T getFirst() const = 0;

    virtual T getLast() const = 0;

    virtual void editAtIndex(T newData, int index) = 0;

    virtual std::vector <T> toVector() const = 0;

};