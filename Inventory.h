//
// Created by prepelicamangalica on 10/04/2022.
//

#ifndef DATASTRUCTURES_ZADANIE_3_INVENTORY_H
#define DATASTRUCTURES_ZADANIE_3_INVENTORY_H

#include <map>
#include <vector>
#include "Queue.h"

#include <cmath>
#include <iomanip>
class Inventory {

public:
    int start();

    void printMenu();

    int exit(std::ofstream &ofstream, std::ifstream &ifstream);

private:
    std::string loadLine(std::string row, std::ifstream &inFile);


    void load(Queue<Article> *inventoryOne, Queue<Article> *inventoryTwo, Queue<Article> *inventoryThree,
              std::string &row);

    std::vector<std::string> split(const std::string &, const char &);

    void buy(Queue<Article> *inventoryOne, Queue<Article> *inventoryTwo, Queue<Article> *inventoryThree) const;

    void makePurchase(Queue<Article> *inventory, Article *boughtArticle) const;

    void sell(Queue<Article> *queueOne, Queue<Article> *queueTwo, Queue<Article> *queueThree);

    void makeSale(Queue<Article> *queue, Article *article);

    Queue<Article> *getQueue(const Queue<Article> queueOne, const Queue<Article> queueTwo,
                             const Queue<Article> queueThree) const;

    void printInventory(Queue<Article> *queue) const;

    void summary(Queue<Article> *pQueue, Queue<Article> *pQueue1, Queue<Article> *pQueue2);

    void printInventoryAndSum(Queue<Article> *pQueue);

    std::map<double, int> getMapOfPricesAndUnits(Queue<Article> *pQueue) const;

    void writeToFile(Queue<Article> *pQueue, std::ofstream &ofstream);
};


#endif //DATASTRUCTURES_ZADANIE_3_INVENTORY_H
