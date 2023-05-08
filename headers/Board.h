#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Block.h"

class Board{
protected:

    static const int hBoard = 4;
    static const int wBoard = 4;
    std::vector<std::vector<std::shared_ptr<Block>>> elemBoard;

public:
    Board();
    Board(const Board& other); // constructor de copiere

    Board& operator=(const Board& other); // operator =

    friend std::ostream& operator<<(std::ostream& os, const Board& board);

    virtual std::shared_ptr<Board> clone() const = 0;

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