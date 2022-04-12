//
// Created by prepelicamangalica on 10/04/2022.
//
#define OUTPUT_PATH "./out.txt"
#define INVENTORY_PATH "./inventory.txt"

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Inventory.h"
#include "Node.h"
#include "Queue.h"

int Inventory::start() {
    char command;
    auto inventoryOne = new Queue<Article>();
    auto inventoryTwo = new Queue<Article>();
    auto inventoryThree = new Queue<Article>();
    Queue<Article> *tempInventory = nullptr;

    std::ofstream outFile(OUTPUT_PATH, std::ios::out);
    std::ifstream inFile(INVENTORY_PATH, std::ifstream::in);

    if (!inFile) {
        throw std::runtime_error("Could not open file");
    }

    Inventory::printMenu();
    while (true) {
        std::string word;
        std::string row;

        scanf("%c", &command);
        switch (command) {
            case 'i':
                tempInventory = getQueue(inventoryOne, inventoryTwo, inventoryThree);
                printInventory(tempInventory);
                break;
            case 'k':
                buy(inventoryOne, inventoryTwo, inventoryThree);
                break;
            case 'p':
                sell(inventoryOne,
                     inventoryTwo,
                     inventoryThree);
                break;
            case 'n':
                while (!(row = loadLine(row, inFile)).empty()) {
                    load(inventoryOne, inventoryTwo, inventoryThree, row);
                }
                break;
            case 's':
                summary(inventoryOne, inventoryTwo, inventoryThree);
                break;
            case 'w':
                writeToFile(inventoryOne, outFile);
                writeToFile(inventoryTwo, outFile);
                writeToFile(inventoryThree, outFile);
                break;
            case 'x':
                return exit(outFile, inFile);
        }
    }
}

void Inventory::printInventory(Queue<Article> *queue) const {
    while (queue->getHead() != nullptr) {
        std::cout << queue->getHead()->getData()->getQuantity() << " units - " <<
                  queue->getHead()->getData()->getPrice() << " EUR" << std::endl;

        queue->setHead(queue->getHead()->getNext());
    }
}

Queue<Article> *Inventory::getQueue(const Queue<Article> queueOne, const Queue<Article> queueTwo,
                                    const Queue<Article> queueThree) const {
    Queue<Article> *tempQueue;
    std::string id;
    std::cout << "Zadaj svoju volbu" << std::endl;
    std::cin >> id;
    try {
        switch (std::stoi(id)) {
            case 1:
                tempQueue = new Queue<Article>(queueOne);
                break;
            case 2:
                tempQueue = new Queue<Article>(queueTwo);
                break;
            case 3:
                tempQueue = new Queue<Article>(queueThree);
                break;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << "\nProblem pri zvoleni parametrov" << std::endl;

    }
    return tempQueue;
}

void Inventory::buy(Queue<Article> *inventoryOne, Queue<Article> *inventoryTwo, Queue<Article> *inventoryThree) const {

    Article *article = NULL;
    std::string id;
    std::string quantity;
    std::string price;
    try {
        std::cout << "Zadaj polozku, pocet ks, cenu" << std::endl;
        std::cin >> id >> quantity >> price;

        article = new Article(std::stoi(id),
                              "K",
                              std::stoi(quantity),
                              std::stod(price));

        switch (article->getId()) {
            case 1:
                makePurchase(inventoryOne, article);
                break;
            case 2:
                makePurchase(inventoryTwo, article);
                break;
            case 3:
                makePurchase(inventoryThree, article);
                break;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << "\nProblem pri zvoleni parametrov" << std::endl;
    }
}

void Inventory::makePurchase(Queue<Article> *inventory, Article *boughtArticle) const {
    inventory->push(boughtArticle);
    inventory->setTotalBought(inventory->getTotalBought() + boughtArticle->getQuantity());
}

void Inventory::load(Queue<Article> *inventoryOne, Queue<Article> *inventoryTwo, Queue<Article> *inventoryThree,
                     std::string &row) {
    std::vector<std::string> rowWords = split(row, ' ');
    try {
        auto *article = new Article(std::stoi(rowWords[0]),
                                    rowWords[1],
                                    std::stoi(rowWords[2]),
                                    std::stod(rowWords[3]));
        switch (article->getId()) {
            case 1:
                article->getTransactionType() == "K" ? makePurchase(inventoryOne, article)
                                                     : makeSale(inventoryOne, article);
                inventoryOne->setTotalBought(inventoryOne->getTotalBought() + article->getQuantity());
                break;
            case 2:
                article->getTransactionType() == "K" ? makePurchase(inventoryTwo, article)
                                                     : makeSale(inventoryTwo, article);
                inventoryTwo->setTotalBought(inventoryTwo->getTotalBought() + article->getQuantity());
                break;
            case 3:
                article->getTransactionType() == "K" ? makePurchase(inventoryThree, article)
                                                     : makeSale(inventoryThree, article);
                inventoryThree->setTotalBought(inventoryThree->getTotalBought() + article->getQuantity());
                break;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << "\nProblem pri zvoleni parametrov" << std::endl;
    }
}

void Inventory::printMenu() {

    std::cout << "<i>nventar ..... vypíš inventár pre číslo položky\n"
                 "<k>up .......... nákup X kusov pre číslo položky\n"
                 "<p>redaj ....... predaj X kusov pre číslo položky\n"
                 "<n>acitaj ...... načítaj inventár zo súboru\n"
                 "<s>tatistika ... vypíš štatistiku zbožia\n"
                 "<w>rite ........ zapíš inventár do súboru\n"
                 "<e>exit ........ ukončiť program\n";
    std::cout.flush();
}

int Inventory::exit(std::ofstream &ofstream, std::ifstream &ifstream) {
    ifstream.close();
    ofstream.close();
    if (ofstream.bad() || ifstream.bad()) {
        throw std::runtime_error("Could not close file");
    }
    return 0;
}

std::string Inventory::loadLine(std::string row, std::ifstream &inFile) {
    std::getline(inFile, row);
    return row;
}

std::vector<std::string> Inventory::split(const std::string &str, const char &ch) {
    std::string next;
    std::vector<std::string> result;

    // For each character in the string
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
        result.push_back(next);
    return result;
}

void Inventory::sell(Queue<Article> *queueOne, Queue<Article> *queueTwo, Queue<Article> *queueThree) {
    std::string id;
    std::string quantity;
    std::string price;
    std::cout << "Zadaj polozku, pocet ks" << std::endl;
    try {
        std::cin >> id >> quantity;
        auto *article = new Article(std::stoi(id),
                                    "P",
                                    std::stoi(quantity),
                                    0);

        switch (article->getId()) {
            case 1:
                makeSale(queueOne, article);
                break;
            case 2:
                makeSale(queueTwo, article);
                break;
            case 3:
                makeSale(queueThree, article);
                break;
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << "\nProblem pri zvoleni parametrov" << std::endl;
    }
}

void Inventory::makeSale(Queue<Article> *queue, Article *article) {

    try {
        if (queue->getTotalBought() < article->getQuantity()) {
            throw std::invalid_argument("Number of sold articles is higher than in Stock");
        }

        while (queue->getHead() != nullptr &&
               article->getQuantity() != 0) {

            if (article->getQuantity() >= queue->getHead()->getData()->getQuantity()) {
                Article *removedArticle = queue->pop();
                int numberOfRemovedArticledFromNode = removedArticle->getQuantity();

                queue->setTotalBought(queue->getTotalBought() - numberOfRemovedArticledFromNode);
                article->setQuantity(article->getQuantity() - numberOfRemovedArticledFromNode);
            } else {
                queue->setTotalBought(queue->getTotalBought() - article->getQuantity());
                queue->getHead()->getData()->setQuantity(
                        queue->getHead()->getData()->getQuantity() - article->getQuantity());
                article->setQuantity(0);
            }
        }
    } catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Inventory::summary(Queue<Article> *pQueue, Queue<Article> *pQueue1, Queue<Article> *pQueue2) {
    std::cout << "Item 1: " << std::endl;
    printInventoryAndSum(new Queue<Article>(pQueue));
    std::cout << "Item 2: " << std::endl;
    printInventoryAndSum(new Queue<Article>(pQueue1));
    std::cout << "Item 3: " << std::endl;
    printInventoryAndSum(new Queue<Article>(pQueue2));

}

void Inventory::printInventoryAndSum(Queue<Article> *pQueue) {
    std::map<double, int> pricesAndUnits = getMapOfPricesAndUnits(pQueue);
    int total = 0;
    for (const auto&[key, value]: pricesAndUnits) {
        std::cout << value << " units " << key << " EUR" << std::endl;
        total += key * value;
    }

    std::cout << "Summary: " << total << " EUR" << std::endl;

}

std::map<double, int>
Inventory::getMapOfPricesAndUnits(Queue<Article> *pQueue) const {
    std::map<double, int> pricesAndUnits = {};
    while (pQueue->getHead() != nullptr) {

        if (!pricesAndUnits.contains(pQueue->getHead()->getData()->getPrice())) {
            pricesAndUnits.insert(
                    {pQueue->getHead()->getData()->getPrice(), pQueue->getHead()->getData()->getQuantity()});
            pQueue->setHead(pQueue->getHead()->getNext());
            continue;
        }

        pricesAndUnits[pQueue->getHead()->getData()->getPrice()] += pQueue->getHead()->getData()->getQuantity();

        pQueue->setHead(pQueue->getHead()->getNext());

    }

    return pricesAndUnits;
}

void Inventory::writeToFile(Queue<Article> *pQueue, std::ofstream &ofstream) {

    while (pQueue->getHead() != nullptr) {

        Article *article = pQueue->getHead()->getData();
        std::string lineToFile = std::to_string(article->getId()) + " " +
                                 article->getTransactionType() + " " +
                                 std::to_string(article->getQuantity()) + " " +
                                 std::to_string(article->getPrice());

        ofstream << lineToFile;
        pQueue->setHead(pQueue->getHead()->getNext());

    }

}
