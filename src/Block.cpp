#include "../headers/Block.h"
#include <algorithm>

  /*  Block::Block(){
        val = 0;
        pozX = pozY = 0;
    }*/

    Block::Block(const int val_, const int pozX_, const int pozY_): val(val_), pozX(pozX_), pozY(pozY_){
        std::cout << "Constructor Block\n";
    } 
    Block::Block(const Block& other): val(other.val), pozX(other.pozX), pozY(other.pozY){
        std::cout << "Constructor de copiere Block\n";
    } // constructor de copiere

    Block& Block::operator=(const Block& other) {
        val = other.val;
        pozX = other.pozX;
        pozY = other.pozY;
        std::cout << "operator= copiere Block\n";
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Block& el) {
        os << el.val << " ";
        return os;
    }

    void Block::setBlock(const int pozX_, const int pozY_, const int val_){
        pozX = pozX_;
        pozY = pozY_;
        val = val_;
    }
    
    Block& Block::swapBlock(Block& other){
        std::swap(val, other.val);
        std::swap(pozX, other.pozX);
        std::swap(pozY, other.pozY);
        return *this;
    }

    int Block::getValBlock () const{
        return val;
    }

    bool Block::isEmpty(){
        return val == 0;
    }

    Block::~Block(){} 
