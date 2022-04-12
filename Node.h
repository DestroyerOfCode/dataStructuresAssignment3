//
// Created by prepelicamangalica on 10/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_3_NODE_H
#define DATASTRUCTURES_ZADANIE_3_NODE_H


#include "Article.h"

template<typename T>
class Node {

private:
    T* data;
    Node<T> *next;
public:
    Node(T *data);

    T *getData() const;

    void setData(T *data);

    Node<T> *getNext() const;

    void setNext(Node<T> *next);
};

#endif //DATASTRUCTURES_ZADANIE_3_NODE_H
