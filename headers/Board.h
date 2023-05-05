#pragma once
#include <iostream>
#include "Block.h"

class Board{
protected:

    static const int hBoard = 4;
    static const int wBoard = 4;
    Block elemBoard[hBoard][wBoard];

public:
    Board();
    Board(const Board& other); // constructor de copiere

    Board& operator=(const Board& other); // operator =

    friend std::ostream& operator<<(std::ostream& os, const Board& board);

    /*void makeCustomBoard();*/


    virtual void makeBoard();

    virtual void genNewElement() = 0;
    
    void moveLeft();

    void moveRight();
    
    void moveUp();

    void moveDown();

    virtual int addLeft() = 0;

    virtual int addRight() = 0;

    virtual int addUp() = 0;

    virtual int addDown() = 0;

    virtual ~Board() = default;
};