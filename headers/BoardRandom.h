//
// Created by bianca on 01.06.2023.
//

#ifndef OOP_BOARDRANDOM_H
#define OOP_BOARDRANDOM_H


#include "Board.h"

class BoardRandom : public Board{

public:
    using Board::Board;

    //std::shared_ptr<Board> clone() const override;

    void genNewElement() override;

    bool canBeAdded(std::shared_ptr<Block> , std::shared_ptr<Block>) override;


};

#endif //OOP_BOARDRANDOM_H
