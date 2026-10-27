
// Note: A lot of the names for variables and operations were inspired by zyBooks
#pragma once
#include "Node.h"
#include "BSTInterface.h"
#include "Visitor.h"

template <typename T>
class BinarySearchTree : public BSTInterface<T> {
    

    private:
    Node<T>* removeHelper(Node<T>* node, const T& value) {
        if (node == nullptr) return nullptr;

        if (value < node->getData()) {
            node->setLeft(removeHelper(node->getLeft(), value));
        } else if (node->getData() < value) {
            node->setRight(removeHelper(node->getRight(), value));
        } else {
            if (node->getLeft() == nullptr) {
                Node<T>* temp = node->getRight();
                delete node;
                return temp;
            } else if (node->getRight() == nullptr) {
                Node<T>* temp = node->getLeft();
                delete node;
                return temp;
            }
            Node<T>* successor = node->getRight();
            while (successor->getLeft() != nullptr) {
                successor = successor->getLeft();
            }
            node->setData(successor->getData());
            node->setRight(removeHelper(node->getRight(), successor->getData()));
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        clearHelper(root);
    }

    // Insert a value into the BST using date comparison via operator<
    void insert(const T& value) override {
        Node<T>* newNode = new Node<T>(value);
        if (root == nullptr) {
            root = newNode;
        } else {
            Node<T>* currentNode = root;
            while (true) {
                if (value < currentNode->getData()) {
                    if (currentNode->getLeft() == nullptr) {
                        currentNode->setLeft(newNode);
                        break;
                    } else {
                        currentNode = currentNode->getLeft();
                    }
                } else {
                    if (currentNode->getRight() == nullptr) {
                        currentNode->setRight(newNode);
                        break;
                    } else {
                        currentNode = currentNode->getRight();
                    }
                }
            }
        }
    }

    // Search for a value in the BST
    bool search(const T& value) const override {
        Node<T>* currentNode = root;
        while (currentNode != nullptr) {
            if (value == currentNode->getData()) {
                return true;
            } else if (value < currentNode->getData()) {
                currentNode = currentNode->getLeft();
            } else {
                currentNode = currentNode->getRight();
            }
        }
        return false;
    }

    // Traversals - all accept a Visitor
    void inorder(Visitor<T>& visitor) const override {
        inorderHelper(root, visitor);
    }

    void preorder(Visitor<T>& visitor) const override {
        preorderHelper(root, visitor);
    }

    void postorder(Visitor<T>& visitor) const override {
        postorderHelper(root, visitor);
    }

    // Clears all nodes from the tree
    void clearTree() override {
        clearHelper(root);
        root = nullptr;
    }
    void remove(const T& value) {
        root = removeHelper(root, value);
    }
};
