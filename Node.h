//
// Created by prepelicamangalica on 10/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_3_NODE_H
#define DATASTRUCTURES_ZADANIE_3_NODE_H


#include "Article.h"

class Node {
public:
    Node(const Article &article, Node *next);

    Node();

private:
    Article article;
    Node* next;
public:
    const Article &getArticle() const;

    void setArticle(const Article &article);

    Node *getNext() const;

    void setNext(Node *next);
};


#endif //DATASTRUCTURES_ZADANIE_3_NODE_H
