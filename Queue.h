//
// Created by prepelicamangalica on 10/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_3_QUEUE_H
#define DATASTRUCTURES_ZADANIE_3_QUEUE_H


#include "Node.h"

class Queue {
private:
    Node *head;
    Node *tail;
    int size;
public:
    Node *getHead() const;

    void setHead(Node *head);

    Node *getTail() const;

    void setTail(Node *tail);

    int getSize() const;

    void setSize(int size);

    Queue();
};


#endif //DATASTRUCTURES_ZADANIE_3_QUEUE_H
