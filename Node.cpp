//
// Created by prepelicamangalica on 10/04/2022.
//

#include "Node.h"

const Article &Node::getArticle() const {
    return article;
}

void Node::setArticle(const Article &article) {
    Node::article = article;
}

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}

Node::Node(const Article &article, Node *next) : article(article), next(next) {
    this->article = article;
    this->next = next;

}

Node::Node() {}
