//
// Created by bianca on 13.05.2023.
//

#include "../headers/BoardFibonacci.h"
#include <random>


void BoardFibonacci::genNewElement() {
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
        elemBoard[X][Y]->setBlock(X, Y, 2);
    else
        elemBoard[X][Y]->setBlock(X, Y, 1);
}

std::shared_ptr<Board> BoardFibonacci::clone() const {
    return std::make_shared<BoardFibonacci>(*this);
}

bool BoardFibonacci::canBeAdded(std::shared_ptr<Block<int>> el1, std::shared_ptr<Block<int>> el2) {
    if(el1->getValBlock() == 1 && el2->getValBlock() == 1)
        return true;
    if(std::min(el1->getValBlock(), el2->getValBlock()) == 1 && std::max(el1->getValBlock(), el2->getValBlock())== 2)
        return true;
    else if(std::abs(el1->getValBlock()-el2->getValBlock()) <= std::min(el1->getValBlock(), el2->getValBlock()) && el1->getValBlock() != el2->getValBlock())
        return true;

    return false;
}

