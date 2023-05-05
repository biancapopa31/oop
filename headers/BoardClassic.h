//
// Created by bianca on 04.05.2023.
//

#ifndef OOP_BOARDCLASSIC_H
#define OOP_BOARDCLASSIC_H

#include "Board.h"

class BoardClassic: public Board{

public:
    using Board::Board;

    void genNewElement() override;

    int addLeft() override;

    int addRight() override;

    virtual int addUp() override;

    virtual int addDown() override;


};

#endif //OOP_BOARDCLASSIC_H
