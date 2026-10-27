#pragma once
// This code reflects my own understanding.
// I can explain every function, data structure, and design decision.

#include <vector>

#include "BagInterface.h"

using namespace std;

/**
 * @file ArrayBag.h
 * Array-based implementation of the Bag ADT.
 */

template<typename T>
class ArrayBag : public BagInterface<T> {
private:
    // Default capacity set to 50 as per requirements
    static const int DEFAULT_CAPACITY = 50;
    T theBag[DEFAULT_CAPACITY];
    int itemCount;

public:
    /**
     * Default constructor
     * Initializes an empty bag with itemCount set to 0.
     */
    ArrayBag();

    /**
     * Adds an item to the bag
     *
     * @param item - the item to add to the bag
     * @return bool - true if item was added successfully, false if bag is full
     */
    bool add(const T& item) override;

    /**
     * Returns the number of items currently in the bag
     *
     * @return int - the current size of the bag
     */
    int getCurrentSize() const override;

    /**
     * Checks if the bag is empty
     *
     * @return bool - true if bag contains no items, false otherwise
     */
    bool isEmpty() const override;

    /**
     * Removes all items from the bag
     * Resets itemCount to 0.
     */
    void clear() override;

    /**
     * Counts the number of occurrences of a specific item in the bag
     *
     * @param item - the item to search for
     * @return int - the frequency of the item in the bag
     */
    int getFrequencyOf(const T& item) const override;

    /**
     * Checks if an item exists in the bag
     *
     * @param item - the item to search for
     * @return bool - true if item is found in bag, false otherwise
     */
    bool contains(const T& item) const override;

    /**
     * Displays all elements in the bag
     * Not an interface method; prints each element with its index.
     */
    void display() const;

    /**
     * Removes the last item from the bag
     *
     * @return bool - true if removal was successful, false if bag is empty
     */
    bool removeLast() override;

    /**
     * Returns the first item in the bag
     *
     * @return T - the first element in the bag
     * @throws runtime_error - if the bag is empty
     */
    T getFirst() const override;

    /**
     * Returns the last item in the bag
     *
     * @return T - the last element in the bag
     * @throws runtime_error - if the bag is empty
     */
    T getLast() const override;

    /**
     * Replaces the item at a specified index with new data
     *
     * @param newData - the new item to place at the index
     * @param index - the position in the bag to modify
     */
    void editAtIndex(T newData, int index) override;

    /**
     * Converts the bag contents to a vector
     *
     * @return vector<T> - a vector containing all items from the bag
     */
    vector <T> toVector() const override;

    /**
     * Checks if this bag is equal to another bag
     * Two bags are equal if they have the same size and contain the same frequencies of items.
     *
     * @param other - the ArrayBag to compare against
     * @return bool - true if bags are equal, false otherwise
     */
    bool equals(const ArrayBag<T>& other) const;
};

/* ===== Implementation ===== */

/**
 * ArrayBag()
 * Default constructor that initializes an empty bag.
 */
template<typename T>
ArrayBag<T>::ArrayBag() {
    itemCount = 0;
}

/**
 * add()
 * Adds a new item to the end of the bag if there is available capacity.
 *
 * @param item - the item to add
 * @return bool - true if item was added, false if bag is at capacity
 */
template<typename T>
bool ArrayBag<T>::add(const T& item) {
    bool addSuccess = false;

    if (itemCount < DEFAULT_CAPACITY) {
        theBag[itemCount] = item;
        itemCount++;
        addSuccess = true;
    }

    return addSuccess;
}

/**
 * getCurrentSize()
 * Returns the number of items currently stored in the bag.
 *
 * @return int - the current item count
 */
template<typename T>
int ArrayBag<T>::getCurrentSize() const {
    return itemCount;
}

/**
 * isEmpty()
 * Determines if the bag contains any items.
 *
 * @return bool - true if itemCount is 0, false otherwise
 */
template<typename T>
bool ArrayBag<T>::isEmpty() const {
    return itemCount == 0;
}

/**
 * clear()
 * Removes all items from the bag by resetting itemCount to 0.
 */
template<typename T>
void ArrayBag<T>::clear() {
    itemCount = 0;
}

/**
 * getFrequencyOf()
 * Counts how many times a specific item appears in the bag.
 *
 * @param item - the item to search for
 * @return int - the number of occurrences of the item
 */
template<typename T>
int ArrayBag<T>::getFrequencyOf(const T& item) const {
    int count = 0;
    for (int i = 0; i < itemCount; i++) {
        if (theBag[i] == item)
            count++;
    }

    return count;
}

/**
 * contains()
 * Searches the bag for a specific item using linear search.
 *
 * @param item - the item to search for
 * @return bool - true if item is found, false otherwise
 */
template<typename T>
bool ArrayBag<T>::contains(const T& item) const {
    bool found = false;
    int i = 0;

    while (!found && i < itemCount) {
        if (theBag[i] == item) {
            found = true;
        }
        i++;
    }

    return found;
}

/**
 * display()
 * Outputs all items in the bag to console with their array indices.
 */
template<typename T>
void ArrayBag<T>::display() const {
    cout << "elements of the array:\n";
    for (int i = 0; i < itemCount; i++)
        cout << "[" << i << "]: " << theBag[i] << endl;
}

/**
 * removeLast()
 * Removes the last item from the bag by decrementing itemCount.
 * This makes the last element inaccessible without physically clearing the memory.
 *
 * @return bool - true if removal was successful, false if bag is empty
 */
template<typename T>
bool ArrayBag<T>::removeLast() {
    if (isEmpty()) {
        return false;
    }
    else {
        // Decrement itemCount to make the last item inaccessible
        itemCount--;
        return true;
    }
}

/**
 * getFirst()
 * Returns the first item in the bag.
 *
 * @return T - the item at index 0
 * @throws runtime_error - if the bag is empty
 */
template<typename T>
T ArrayBag<T>::getFirst() const {
    if (!isEmpty()) {
        return theBag[0];
    }
    else {
        // Throw exception to handle empty bag case
        throw runtime_error("Empty bag");
    }
}

/**
 * getLast()
 * Returns the last item in the bag.
 *
 * @return T - the item at index itemCount - 1
 * @throws runtime_error - if the bag is empty
 */
template<typename T>
T ArrayBag<T>::getLast() const {
    if (!isEmpty()) {
        return theBag[itemCount - 1];
    }
    else {
        // Throw exception to handle empty bag case
        throw runtime_error("Empty bag");
    }
}

/**
 * editAtIndex()
 * Replaces the item at a given index with new data.
 *
 * @param newData - the new item to store
 * @param index - the position to modify
 */
template<typename T>
void ArrayBag<T>::editAtIndex(T newData, int index) {
    theBag[index] = newData;
}

/**
 * toVector()
 * Converts all items in the bag to a vector.
 *
 * @return vector<T> - a vector containing all bag items in order
 */
template<typename T>
vector<T> ArrayBag<T>::toVector() const {
    vector<T> returnVector;

    for (int i = 0; i < itemCount; i++) {
        returnVector.push_back(theBag[i]);
    }
    return returnVector;
}

/**
 * equals()
 * Compares this bag with another bag for equality.
 * Two bags are equal if they have the same size and each item in one bag
 * appears the same number of times in the other bag.
 *
 * @param other - the ArrayBag to compare with
 * @return bool - true if bags contain identical items with identical frequencies, false otherwise
 */
template<typename T>
bool ArrayBag<T>::equals(const ArrayBag<T>& other) const {
    bool equal = false;
    int equalsCounter = 0;

    // Bags of different sizes cannot be equal
    if (itemCount != other.getCurrentSize()) {
        return false;
    }
    else {
        // Check that each item in this bag has the same frequency in the other bag
        for (int i = 0; i < itemCount; i++) {
            if (other.getFrequencyOf(theBag[i]) == getFrequencyOf(theBag[i])) {
                equalsCounter++;
            }
        }

        // If all items matched in frequency, bags are equal
        if (equalsCounter == itemCount) {
            return true;
        }
        else {
            return false;
        }
    }
}