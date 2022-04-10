//
// Created by prepelicamangalica on 10/04/2022.
//

#include "Queue.h"

Queue::Queue() {
    head=NULL;
    tail=NULL;
    size=0;
}

Node *Queue::getHead() const {
    return head;
}

void Queue::setHead(Node *head) {
    Queue::head = head;
}

Node *Queue::getTail() const {
    return tail;
}

void Queue::setTail(Node *tail) {
    Queue::tail = tail;
}

int Queue::getSize() const {
    return size;
}

void Queue::setSize(int size) {
    Queue::size = size;
}
