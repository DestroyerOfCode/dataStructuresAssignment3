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
};


#endif //DATASTRUCTURES_ZADANIE_3_INVENTORY_H
