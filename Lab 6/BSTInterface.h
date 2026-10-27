//==============BSTInterface.h===================
// Got it from canvas but edited it to be templated and accept vistor parameters
#pragma once
#include "Visitor.h"

template <typename T>
class BSTInterface {
public:
    virtual ~BSTInterface() {}

    // Core tree operations
    virtual void insert(const T& value) = 0;
    virtual bool search(const T& value) const = 0;

    // Traversal operations - all accept a Visitor
    virtual void inorder(Visitor<T>& visitor) const = 0;
    virtual void preorder(Visitor<T>& visitor) const = 0;
    virtual void postorder(Visitor<T>& visitor) const = 0;

    // Clear the tree
    virtual void clearTree() = 0;
};
