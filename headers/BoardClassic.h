//
// Created by bianca on 04.05.2023.
//

#ifndef OOP_BOARDCLASSIC_H
#define OOP_BOARDCLASSIC_H

#include "Board.h"

class BoardClassic: public Board{

public:
    using Board::Board;

    std::shared_ptr<Board> clone() const override;

    void genNewElement() override;

    void canMakeMove() override;

    bool canBeAdded(std::shared_ptr<Block> , std::shared_ptr<Block>) override;


};

#endif //OOP_BOARDCLASSIC_H
