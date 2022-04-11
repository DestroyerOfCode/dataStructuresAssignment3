//
// Created by prepelicamangalica on 10/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_3_INVENTORY_H
#define DATASTRUCTURES_ZADANIE_3_INVENTORY_H
#include <vector>
#include "Queue.h"

class Inventory {

public:
    int start();
    void printMenu();
    int exit();

private:
    std::string loadLine(std::string row, std::ifstream &inFile);
    std::vector<std::string> split(std::string text);
    void load(Queue<Article> &inventoryOne, Queue<Article> &inventoryTwo, Queue<Article> &inventoryThree, std::string &row);

    void buy(Queue<Article> *inventoryOne, Queue<Article> *inventoryTwo, Queue<Article> *inventoryThree,
             const Article *boughtArticle) const;

    void makePurchase(Queue<Article> *inventory, const Article *boughtArticle) const;

    void sell(Queue<Article> *queueOne, Queue<Article> *queueTwo, Queue<Article> *queueThree, Article *article);

    void makeSale(Queue<Article> *queue, Article *article);
};


#endif //DATASTRUCTURES_ZADANIE_3_INVENTORY_H
