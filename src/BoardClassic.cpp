//
// Created by bianca on 04.05.2023.
//

#include "../headers/BoardClassic.h"

void BoardClassic::genNewElement() {
    int X = rand() %3;
    int Y = rand() %3;
    int val = 1 + rand() %100;
    while (!elemBoard[X][Y]->isEmpty()){
        X = rand() %3;
        Y = rand() %3;
    }
    if (val%20 == 0)
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

