//
// Created by prepelicamangalica on 10/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_3_ARTICLE_H
#define DATASTRUCTURES_ZADANIE_3_ARTICLE_H


#include <string>

class Article {

public:
    int id;
    std::string transactionType;
    int quantity;
    double price;
public:
    Article(int id, std::string transactionType, int quantity, double price);

    int getId() const;

    void setId(int id);

    const std::string &getTransactionType() const;

    void setTransactionType(const std::string &transactionType);

    int getQuantity() const;

    void setQuantity(int quantity);

    double getPrice() const;

    void setPrice(double price);

    Article();
};


#endif //DATASTRUCTURES_ZADANIE_3_ARTICLE_H
