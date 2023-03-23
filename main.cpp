#include <iostream>

class Block{
private:
    int val;
    int m;
public:
    Block(const int val_ = 0): val(val_){
        std::cout << "Constructor Block\n";
    } 
    Block(const Block& other): val(other.val){
        std::cout << "Constructor de copiere Block\n";
    } // constructor de copiere

    Block& operator=(const Block& other) {
        val = other.val;
        std::cout << "operator= copiere Block\n";
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Block& el) {
        os << el.val << " ";
        return os;
    }

    ~Block(){} 
};

class Grid{
private:
    Block elemTabla[4][4];

public:
    Grid(){
        std::cout << "Constructor Grid\n";
    }
    Grid(const Grid& other): elemTabla(other.elemTabla){
        std::cout << "Constructor de copiere Grid\n";
    } // constructor de copiere

    Grid& operator=(const Grid& other){
        std::cout << "operator= copiere Grid\n";
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++){
                elemTabla[i][j] = other.elemTabla[i][j];
            }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Grid& tabla) {
        for (int i = 0; i < 20 ; i++)
            os << "_";
        os << "\n";
        for (int i = 0; i < 20 ; i++)
            os << " ";
        os << "\n";
        
        for (int i = 0; i < 4; i++){
            for(int j = 0; j< 4; j++)
                os << "| " << tabla.elemTabla[i][j] << "|";
            os << "\n";
            for (int i = 0; i < 20 ; i++)
                os << "_";
            os << "\n";
             for (int i = 0; i < 20 ; i++)
                os << " ";
            os << "\n";
        }
        /*for (int i = 0; i <20; i++)
            os << "_";
        os << "\n";*/
        return os;
    }

    ~Grid(){}
};

class Game{
private:
    Grid tabla; 
    int scor;

public:
    ~Game(){}
};


int main() {
    Block a(2);
    std::cout << "Am creat Block\n";
    Grid g;
    //g = h;
    std::cout << g;
    return 0;
}
