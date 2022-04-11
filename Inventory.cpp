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

    std::ofstream outFile(OUTPUT_PATH, std::ios::out);
    std::ifstream inFile(INVENTORY_PATH, std::ifstream::in);

    if (!inFile) {
        throw std::runtime_error("Could not open file");
    }

    Inventory::printMenu();
    while (true) {
        std::string word;
        std::string row;

        Article *boughtArticle = NULL;
        std::string id;
        std::string quantity;
        std::string price;
        scanf("%c", &command);
        switch (command) {
            case 'i':
                break;
            case 'k':
                std::cout << "Zadaj polozku, pocet ks, cenu" << std::endl;
                std::cin >> id >> quantity >> price;
                boughtArticle = new Article(std::stoi(id),
                                                     "K",
                                                     std::stoi(quantity),
                                                     std::stod(price));
                switch (boughtArticle->getId()) {
                    case 1:
                        if (boughtArticle->getTransactionType() == "K") {
                            inventoryOne->push(*boughtArticle);
                        }
                        break;
                    case 2:
                        if (boughtArticle->getTransactionType() == "K") {
                            inventoryTwo->push(*boughtArticle);
                        }
                        break;
                    case 3:
                        if (boughtArticle->getTransactionType() == "K") {
                            inventoryThree->push(*boughtArticle);
                        }
                        break;
                }
                break;
            case 'p':
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
