#pragma once
#include <iostream>
#include "Block.h"

class Board{

//friend class Game;

private:
    static const int hBoard = 4;
    static const int wBoard = 4;
    Block elemBoard[hBoard][wBoard];
   // sf::RectangleShape graphicBoard;


public:
    Board();
    Board(const Board& other); // constructor de copiere

    Board& operator=(const Board& other); // operator =

    friend std::ostream& operator<<(std::ostream& os, const Board& board);

    /*void makeCustomBoard();*/

   /* void setGraphicBoard();*/

    void makeBoard();

    void genNewElement();
    
    void moveLeft();

    void moveRight();
    
    void moveUp();

    void moveDown();

    int addLeft();

    int addRight();

    int addUp();

    int addDown();

    ~Board();
};