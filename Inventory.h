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

    void load(Queue<Article> *inventoryOne, Queue<Article> *inventoryTwo, Queue<Article> *inventoryThree,
              std::string &row);

    void buy(Queue<Article> *inventoryOne, Queue<Article> *inventoryTwo, Queue<Article> *inventoryThree) const;

    void makePurchase(Queue<Article> *inventory, const Article *boughtArticle) const;

    void sell(Queue<Article> *queueOne, Queue<Article> *queueTwo, Queue<Article> *queueThree);

    Queue<Article>* makeSale(Queue<Article> *queue, Article *article);

    Queue<Article> *getQueue(const Queue<Article> queueOne, const Queue<Article> queueTwo,
                             const Queue<Article> queueThree) const;

    void printInventory(Queue<Article> *queue) const;

    void sell(Queue<Article> *queue, std::string id, std::string quantity, std::string price);

    void sell(Queue<Article> *queue, Article *article);

    void summary(Queue<Article> *pQueue, Queue<Article> *pQueue1, Queue<Article> *pQueue2);
};


#endif //DATASTRUCTURES_ZADANIE_3_INVENTORY_H
