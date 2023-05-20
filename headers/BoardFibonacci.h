//
// Created by bianca on 13.05.2023.
//

#ifndef OOP_BOARDFIBONACCI_H
#define OOP_BOARDFIBONACCI_H


#include "Board.h"

class BoardFibonacci: public Board {
public:
    using Board::Board;

    std::shared_ptr<Board> clone() const override;

    void genNewElement() override;

    bool canBeAdded(std::shared_ptr<Block> , std::shared_ptr<Block>) override;


};


#endif //OOP_BOARDFIBONACCI_H
