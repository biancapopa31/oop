#pragma once
#include <iostream>

template <typename T>
class Block;

template<typename T>
std::ostream& operator<<(std::ostream&, const Block<T>&);

template<typename T>
void swap(Block<T>&, Block<T>&);



template <typename T>
class Block{

private:    
    T val;
    int pozX, pozY;
    static const int maxX = 4;
    static const int maxY = 4;


public:
    explicit Block(T = 0, int = 0, int = 0);

    Block(const Block<T>& other); // constructor de copiere

    Block& operator=(Block<T>& other);

    friend void swap <T>(Block<T>&, Block<T>&);

    friend std::ostream& operator<< <T>(std::ostream& os, const Block<T>& el);

    void setBlock(int pozX_, int pozY_, T val_);

    T getValBlock ()const;


    bool isEmpty() const;

    ~Block();
};