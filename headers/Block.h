#pragma once
#include <iostream>

class Block{

private:    
    int val;
    int pozX, pozY;

public:
    explicit Block(int = 0, int = 0, int = 0);

    Block(const Block& other); // constructor de copiere

    Block& operator=(Block& other);

    friend void swap(Block&, Block&);

    friend std::ostream& operator<<(std::ostream& os, const Block& el);

    void setBlock(int pozX_, int pozY_, int val_);
    
    Block& swapBlock(Block& other);

    int getValBlock ()const;

    bool isEmpty() const;

    ~Block();
};