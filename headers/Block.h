#pragma once
#include <iostream>

class Block{

private:    
    int val;
    int pozX, pozY;
   // sf::RectangleShape graphicBoard;

public:
    Block();
    Block(const int, const int, const int);
    Block(const Block& other); // constructor de copiere

    Block& operator=(const Block& other);

    friend std::ostream& operator<<(std::ostream& os, const Block& el);

    void setBlock(const int pozX_, const int pozY_, const int val_);
    
    Block& swapBlock(Block& other);

    int getValBlock ()const;

    bool isEmpty();

    ~Block();
};