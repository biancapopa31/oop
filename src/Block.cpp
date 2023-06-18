#include "../headers/Block.h"
#include "../headers/Erori.h"



template
std::ostream& operator<< <>(std::ostream& o, const Block<int>& x);

template
void swap <>(Block<int>&, Block<int>&);


template <typename T> Block<T>::Block(const T val_, const int pozX_, const int pozY_): val(val_), pozX(pozX_), pozY(pozY_){
       if(pozX_ > maxX)
           throw EroareBlock("Index out of range!");
       if(pozY_ >maxY)
           throw EroareBlock("Index out of range!");
    }
template <typename T> Block<T>::Block(const Block& other): val(other.val), pozX(other.pozX), pozY(other.pozY){
    } // constructor de copiere

template <typename T> Block<T>& Block<T>::operator=(  Block& other) {
        swap(*this, other);
        return *this;
    }

template <typename T> void swap(Block<T>& b1, Block<T>& b2){
        std::swap(b1.val, b2.val);
        std::swap(b1.pozX, b2.pozY);
        std::swap(b1.pozY, b2.pozY);
}

template <typename T> std::ostream& operator<<(std::ostream& os, const Block<T>& el) {
        os << el.val << " ";
        return os;
    }

template <typename T> void Block<T>::setBlock(const int pozX_, const int pozY_, const T val_){
        pozX = pozX_;
        pozY = pozY_;
        val = val_;
    }

template <typename T> T Block<T>::getValBlock () const{
        return val;
    }

template <typename T> bool Block<T>::isEmpty() const{
        return val == 0;
    }

template <typename T> Block<T>::~Block()= default;
