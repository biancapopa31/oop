//
// Created by bianca on 04.05.2023.
//

#include "../headers/BoardClassic.h"
#include "../headers/Erori.h"
#include <random>

void BoardClassic::genNewElement() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> index(0,3);
    std::uniform_int_distribution<> valoare(1,100);

    int X = index(gen);
    int Y = index(gen);
    int val =  valoare(gen);
    while (!elemBoard[X][Y]->isEmpty()){
        X = index(gen);
        Y = index(gen);
    }
    if (val%10 == 0)
    elemBoard[X][Y]->setBlock(X, Y, 4);
    else
    elemBoard[X][Y]->setBlock(X, Y, 2);
}


std::shared_ptr<Board> BoardClassic::clone() const {
    return std::make_shared<BoardClassic>(*this);
}

bool BoardClassic::canBeAdded(std::shared_ptr<Block> el1, std::shared_ptr<Block> el2) {
    return el1->getValBlock() == el2->getValBlock();
}

void BoardClassic::canMakeMove() {
    if(!this->isFull())
        return;

    throw EroareBoard("Nu se mai pot face mutari!");
}

