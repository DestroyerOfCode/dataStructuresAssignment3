//
// Created by prepelicamangalica on 10/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_3_QUEUE_H
#define DATASTRUCTURES_ZADANIE_3_QUEUE_H


#include "Node.h"

template<typename T>
class Queue {
private:
    Node<T> *head;
    Node<T> *tail;
    int size;
    int totalBought;
public:
    Queue();

    int getTotalBought() const;

    void setTotalBought(int totalBought);

    int getSize() const;

    void setSize(int size);

    void push(T* data);

    T *pop();

    Node<T> *getHead() const;

    void setHead(Node<T> *head);

    Node<T> *getTail() const;

    void setTail(Node<T> *tail);

    Queue(Queue<Article> *pQueue);
};


#endif //DATASTRUCTURES_ZADANIE_3_QUEUE_H
