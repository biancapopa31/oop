#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Block.h"

class Board{
protected:

    static const int hBoard = 4;
    static const int wBoard = 4;
    std::vector<std::vector<std::shared_ptr<Block <int>>>> elemBoard;

public:
    Board();
    Board(const Board& other); // constructor de copiere

    Board& operator=(const Board& other); // operator =

    friend std::ostream& operator<<(std::ostream& os, const Board& board);

    virtual std::shared_ptr<Board> clone() const = 0;

    /*void makeCustomBoard();*/

    virtual void makeBoard();

    virtual void genNewElement() = 0;

     virtual bool isFull();

    virtual void canMakeMove() ;
    
    void moveLeft();

    void moveRight();
    
    void moveUp();

    void moveDown();

    virtual int addLeft();

    virtual int addRight();

    virtual int addUp();

    virtual int addDown();

    virtual bool canBeAdded(std::shared_ptr<Block <int>> , std::shared_ptr<Block <int>>) = 0;

    virtual ~Board() = default;
};