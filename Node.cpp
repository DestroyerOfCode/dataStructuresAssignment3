//
// Created by prepelicamangalica on 10/04/2022.
//

#include "Node.h"

template<typename T>
T Node<T>::getData() const {
    return data;
}

template<typename T>
void Node<T>::setData(T data) {
    Node::data = data;
}

template<typename T>
Node<T> *Node<T>::getNext() const {
    return next;
}

template<typename T>
void Node<T>::setNext(Node<T> *next) {
    Node::next = next;
}

template<typename T>
Node<T>::Node(T data):data(data) {
    this->data = data;
    next = nullptr;
}

template
class Node<Article>;