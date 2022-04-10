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
    Queue inventoryOne = Queue();
    Queue inventoryTwo = Queue();
    Queue inventoryThree = Queue();

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
                break;
            case 'k':
                break;
            case 'p':
                break;
            case 'n':
                while (!(row = loadLine(row, inFile)).empty()) {
                    std::vector<std::string> rowWords = split(row);
                    Article article = Article(std::stoi(rowWords[0]),
                                              rowWords[1],
                                              std::stoi(rowWords[2]),
                                              std::stod(rowWords[3])
                                              );
//                    switch(article.getId()) {
//                        case 1:
//                            if (inventoryOne.getNext() != NULL) {
//                                inventoryOne.
//                            }
//                            inventoryOne.setArticle(article);
//                            inventoryOne.setNext(new Node());
//                            break;
//                        case 2:
//                            if (inventoryTwo.getNext() != NULL) {
//                                inventoryTwo.
//                            }
//                            inventoryTwo.setArticle(article);
//                            inventoryTwo.setNext(new Node());
//                            break;
//                        case 3:
//                            if (inventoryThree.getNext() != NULL) {
//                                inventoryThree.
//                            }
//                            inventoryThree.setArticle(article);
//                            inventoryThree.setNext(new Node());
//                            break;
//                    }
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

    while (std::getline(sstream, word, ' ')){
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        words.push_back(word);
    }

    for (const auto &str : words) {
        std::cout << str << std::endl;
    }

    return words;
}
