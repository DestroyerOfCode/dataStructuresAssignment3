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

        Article *executionArticle = NULL;
        std::string id;
        std::string quantity;
        std::string price;
        Article *a;
        scanf("%c", &command);
        switch (command) {
            case 'i':
                std::cout << "Zadaj svoju volbu" << std::endl;
                std::cin >> id;
                tempInventory = new Queue<Article>(inventoryOne);
                switch (std::stoi(id)) {
                    case 1:
                        tempInventory = new Queue<Article>(inventoryOne);
                        break;
                    case 2:
                        tempInventory = new Queue<Article>(inventoryTwo);
                        break;
                    case 3:
                        tempInventory = new Queue<Article>(inventoryThree);
                        break;
                }
                while (tempInventory->getHead() != nullptr) {
                    std::cout << tempInventory->getHead()->getData().getQuantity() << " units - " <<
                              tempInventory->getHead()->getData().getPrice() << " EUR" << std::endl;

                    tempInventory->setHead(tempInventory->getHead()->getNext());
                }
                break;
            case 'k':
                std::cout << "Zadaj polozku, pocet ks, cenu" << std::endl;
                std::cin >> id >> quantity >> price;
                executionArticle = new Article(std::stoi(id),
                                               "K",
                                               std::stoi(quantity),
                                               std::stod(price));
                buy(inventoryOne, inventoryTwo, inventoryThree, executionArticle);
                break;
            case 'p':
                std::cout << "Zadaj polozku, pocet ks" << std::endl;
                std::cin >> id >> quantity;
                executionArticle = new Article(std::stoi(id),
                                               "P",
                                               std::stoi(quantity),
                                               0);

                sell(inventoryOne,
                     inventoryTwo,
                     inventoryThree,
                     executionArticle);
                break;
            case 'n':
                while (!(row = loadLine(row, inFile)).empty()) {
                    load(*inventoryOne, *inventoryTwo, *inventoryThree, row);
                }
                break;
            case 's':
                break;
            case 'w':
                break;
            case 'x':
                return exit();
        }
    }
}

void Inventory::buy(Queue<Article> *inventoryOne, Queue<Article> *inventoryTwo, Queue<Article> *inventoryThree,
                    const Article *boughtArticle) const {
    switch (boughtArticle->getId()) {
        case 1:
            makePurchase(inventoryOne, boughtArticle);
            break;
        case 2:
            makePurchase(inventoryTwo, boughtArticle);
            break;
        case 3:
            makePurchase(inventoryThree, boughtArticle);
            break;
    }
}

void Inventory::makePurchase(Queue<Article> *inventory, const Article *boughtArticle) const {
    if (inventory->getTotalBought() <= boughtArticle->getQuantity() &&
        boughtArticle->getTransactionType() == "K") {

        inventory->push(*boughtArticle);
        inventory->setTotalBought(inventory->getTotalBought() + boughtArticle->getQuantity());
    }
}

void Inventory::load(Queue<Article> &inventoryOne, Queue<Article> &inventoryTwo, Queue<Article> &inventoryThree,
                     std::string &row) {
    std::vector<std::string> rowWords = split(row);
    Article article = Article(std::stoi(rowWords[0]),
                              rowWords[1],
                              std::stoi(rowWords[2]),
                              std::stod(rowWords[3]));
    switch (article.getId()) {
        case 1:
            if (article.getTransactionType() == "K") {
                inventoryOne.push(article);
            }
            break;
        case 2:
            if (article.getTransactionType() == "K") {
                inventoryTwo.push(article);
            }
            break;
        case 3:
            if (article.getTransactionType() == "K") {
                inventoryThree.push(article);
            }
            break;
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

int Inventory::exit() {
    return 0;
}

std::string Inventory::loadLine(std::string row, std::ifstream &inFile) {
    std::getline(inFile, row);
    return row;
}

std::vector<std::string> Inventory::split(std::string text) {
    std::stringstream sstream(text);
    std::string word;
    std::vector<std::string> words{};

    while (std::getline(sstream, word, ' ')) {
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }

    for (const auto &str: words) {
        std::cout << str << std::endl;
    }

    return words;
}

void Inventory::sell(Queue<Article> *queueOne, Queue<Article> *queueTwo, Queue<Article> *queueThree, Article *article) {
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
}

void Inventory::makeSale(Queue<Article> *queue, Article *article) {

    try {
        if (queue->getTotalBought() < article->getQuantity()) {
            throw std::invalid_argument("Number of sold articles is higher than in Stock");
        }

        while (queue->getHead() != nullptr ||
               article->getQuantity() != 0) {

            if (article->getQuantity() >= queue->getHead()->getData().getQuantity()) {
                Article *removedArticle = queue->pop();
                int numberOfRemovedArticledFromNode = removedArticle->getQuantity();

                queue->setTotalBought(queue->getTotalBought() - numberOfRemovedArticledFromNode);
                article->setQuantity(article->getQuantity() - numberOfRemovedArticledFromNode);
            } else {
                queue->setTotalBought(queue->getTotalBought() - article->getQuantity());
                queue->getHead()->getData().setQuantity(
                        queue->getHead()->getData().getQuantity() - article->getQuantity());
                article->setQuantity(0);
            }

        }
    } catch (std::invalid_argument &e) {
        std::cerr << e.what();
    }
}
