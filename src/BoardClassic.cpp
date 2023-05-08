//
// Created by bianca on 04.05.2023.
//

#include "../headers/BoardClassic.h"

void BoardClassic::genNewElement() {
    int X = rand() %3;
    int Y = rand() %3;
    int val = 1 + rand() %100;
    while (!elemBoard[X][Y]->isEmpty())
    {
    X = rand() %3;
    Y = rand() %3;
    }
    if (val%10 == 0)
    elemBoard[X][Y]->setBlock(X, Y, 4);
    else
    elemBoard[X][Y]->setBlock(X, Y, 2);
}

int BoardClassic::addLeft() {
    int add = 0;
    for(int i = 0; i < hBoard; i++){
        for(int j = 0; j < wBoard-1; j++){
            if(elemBoard[i][j]->getValBlock() == elemBoard[i][j+1]->getValBlock()){
                add += elemBoard[i][j]->getValBlock()*2;
                elemBoard[i][j]->setBlock(i, j, elemBoard[i][j]->getValBlock()*2);
                elemBoard[i][j+1]->setBlock(i, j+1, 0);
            }

        }
    }
    moveLeft();
    return add;
}

int BoardClassic::addRight() {
    int add = 0;
    for(int i = 0; i < hBoard; i++){
        for(int j = wBoard-1; j > 0; j--){
            if(elemBoard[i][j]->getValBlock() == elemBoard[i][j-1]->getValBlock()){
                add += elemBoard[i][j]->getValBlock()*2;
                elemBoard[i][j]->setBlock(i, j, elemBoard[i][j]->getValBlock()*2);
                elemBoard[i][j-1]->setBlock(i, j-1, 0);
            }
        }
    }
    moveRight();
    return add;
}

int BoardClassic::addUp() {
    int add  = 0;
    for(int j = 0; j < wBoard; j++){
        for(int i = 0; i < hBoard-1; i++){
            if(elemBoard[i][j]->getValBlock() == elemBoard[i+1][j]->getValBlock()){
                add += elemBoard[i][j]->getValBlock()*2;
                elemBoard[i][j]->setBlock(i, j, elemBoard[i][j]->getValBlock()*2);
                elemBoard[i+1][j]->setBlock(i+1, j, 0);
            }
        }
    }
    moveUp();
    return add;
}

int BoardClassic::addDown() {
    int add  = 0;
    for(int j = 0; j < wBoard; j++){
        for(int i = hBoard-1; i > 0; i--){
            if(elemBoard[i][j]->getValBlock() == elemBoard[i-1][j]->getValBlock()){
                add += elemBoard[i][j]->getValBlock()*2;
                elemBoard[i][j]->setBlock(i, j, elemBoard[i][j]->getValBlock()*2);
                elemBoard[i-1][j]->setBlock(i-1, j, 0);
            }
        }
    }
    moveDown();
    return add;
}

std::shared_ptr<Board> BoardClassic::clone() const {
    return std::make_shared<BoardClassic>(*this);
}

