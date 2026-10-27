//=============Node.h===================
#pragma once

template<typename T>
class Node {
private:
    T data;
    Node* left;
    Node* right;

public:
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
    Node() : data(), left(nullptr), right(nullptr) {}

    T getData() const;
    Node* getLeft() const;
    Node* getRight() const;

    void setLeft(Node* left);
    void setRight(Node* right);
    

    void setData(T value);

};

template<typename T>
T Node<T>::getData() const {
    return data;
}

template<typename T>
Node<T>* Node<T>::getLeft() const {
    return left;
}

template<typename T>
Node<T>* Node<T>::getRight() const {
    return right;
}

template<typename T>
void Node<T>::setLeft(Node* l) {
    this->left = l;
}

template<typename T>
void Node<T>::setRight(Node* r) {
    this->right = r;
}

template<typename T>
void Node<T>::setData(T value) {
    data = value;
}
