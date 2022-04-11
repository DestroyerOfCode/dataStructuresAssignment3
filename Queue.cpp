//
// Created by prepelicamangalica on 10/04/2022.
//

#include "Queue.h"

template<typename T>
void Queue<T>::push(T data) {
    auto newNode = new Node<T>(data);
    if (this->getTail() == nullptr) {
        this->setHead(newNode);
        this->setTail(newNode);
    } else {
        this->getTail()->setNext(newNode);
        this->setTail(this->getTail()->getNext());
    }
    this->setSize(this->getSize() + 1);
}

template<typename T>
Node<T> *Queue<T>::getHead() const {
    return head;
}

template<typename T>
void Queue<T>::setHead(Node<T> *head) {
    Queue::head = head;
}

template<typename T>
Node<T> *Queue<T>::getTail() const {
    return tail;
}

template<typename T>
void Queue<T>::setTail(Node<T> *tail) {
    Queue::tail = tail;
}

template<typename T>
int Queue<T>::getSize() const {
    return size;
}

template<typename T>
void Queue<T>::setSize(int size) {
    Queue::size = size;
}

template<typename T>
Queue<T>::Queue() {
    head = nullptr;
    tail = nullptr;
    size = 0;
    totalBought = 0;
}

template<typename T>
int Queue<T>::getTotalBought() const {
    return totalBought;
}

template<typename T>
void Queue<T>::setTotalBought(int totalBought) {
    Queue::totalBought = totalBought;
};

template class Queue<Article>;