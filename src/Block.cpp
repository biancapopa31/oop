#include "../headers/Block.h"
#include "../headers/Erori.h"


    Block::Block(const int val_, const int pozX_, const int pozY_): val(val_), pozX(pozX_), pozY(pozY_){
       if(pozX_ > maxX)
           throw EroareBlock("Index out of range!");
       if(pozY_ >maxY)
           throw EroareBlock("Index out of range!");
    } 
    Block::Block(const Block& other): val(other.val), pozX(other.pozX), pozY(other.pozY){
    } // constructor de copiere

    Block& Block::operator=( Block& other) {
        swap(*this, other);
        return *this;
    }

    void swap(Block& b1, Block& b2){
        std::swap(b1.val, b2.val);
        std::swap(b1.pozX, b2.pozY);
        std::swap(b1.pozY, b2.pozY);
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

    int Block::getValBlock () const{
        return val;
    }

    bool Block::isEmpty() const{
        return val == 0;
    }


Block::~Block()= default;
