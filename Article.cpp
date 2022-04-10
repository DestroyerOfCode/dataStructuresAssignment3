//
// Created by prepelicamangalica on 10/04/2022.
//

#include "Article.h"

Article::Article(int id, std::string transactionType, int quantity, double price) : id(id), transactionType(transactionType),
                                                                             quantity(quantity), price(price) {}

Article::Article() {}

int Article::getId() const {
    return id;
}

void Article::setId(int id) {
    Article::id = id;
}

std::string Article::getTransactionType() const {
    return transactionType;
}

void Article::setTransactionType(std::string transactionType) {
    Article::transactionType = transactionType;
}

int Article::getQuantity() const {
    return quantity;
}

void Article::setQuantity(int quantity) {
    Article::quantity = quantity;
}

double Article::getPrice() const {
    return price;
}

void Article::setPrice(double price) {
    Article::price = price;
}
