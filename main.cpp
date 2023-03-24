#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdlib.h>

class Block{

friend class Board;

private:
    int val;
    int pozX, pozY;

    void setBlock(const int pozX_, const int pozY_, const int val_){
        pozX = pozX_;
        pozY = pozY_;
        val = val_;
    }

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
    
    Block& swapBlock(Block& other){
        std::swap(val, other.val);
        std::swap(pozX, other.pozX);
        std::swap(pozY, other.pozY);
        return *this;
    }

    bool isEmpty(){
        return val == 0;
    }


    ~Block(){} 
};

class Board{

friend class Game;

private:
    Block elemTabla[4][4];

public:
    Board():elemTabla(){
        makeBoard();
        std::cout << "Constructor Board\n";
    }
    Board(const Board& other): elemTabla(other.elemTabla){
        std::cout << "Constructor de copiere Board\n";
    } // constructor de copiere

    Board& operator=(const Board& other){
        std::cout << "operator= copiere Board\n";
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++){
                elemTabla[i][j] = other.elemTabla[i][j];
            }
        return *this;
    } // operator de copiere

    friend std::ostream& operator<<(std::ostream& os, const Board& tabla) {
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
            for (int j = 0; j < 20 ; j++)
                os << "_";
            os << "\n";
             for (int j = 0; j < 20 ; j++)
                os << " ";
            os << "\n";
        }
        /*for (int i = 0; i <20; i++)
            os << "_";
        os << "\n";*/
        return os;
    }

    /*void makeCustomBoard(){
        elemTabla[1][1].setBlock(1, 1, 2);
        elemTabla[1][3].setBlock(1, 3, 2);
        elemTabla[1][0].setBlock(1, 0, 2);
        elemTabla[1][2].setBlock(1, 2, 2);
        elemTabla[2][1].setBlock(2, 1, 2);
        elemTabla[0][3].setBlock(0, 3, 2);
        elemTabla[3][3].setBlock(3, 3, 4);
        elemTabla[3][0].setBlock(3, 0, 2);
    }*/

    void makeBoard(){
        genNewElement();
        genNewElement();

    }

    void genNewElement(){
        int X = rand() %3;
        int Y = rand() %3;
        int val = 1 + rand() %100;
        while (!elemTabla[X][Y].isEmpty())
        {
            X = rand() %3;
            Y = rand() %3;
        }
        if (val%4 == 0)
            elemTabla[X][Y].setBlock(X, Y, 4);
        else
            elemTabla[X][Y].setBlock(X, Y, 2);
    }
    
    void moveLeft(){
        for(int i = 0 ; i < 4; i++){
            for (int j = 0, e = 1; j < 4; j++){
                if(elemTabla[i][j].val == 0){
                    e = j;
                    while (elemTabla[i][e].val == 0 && e < 4)
                        e++;
                    if(elemTabla[i][e].val != 0 && e < 4)
                        elemTabla[i][j].swapBlock(elemTabla[i][e]);
                }
            }
        }
    }

    void moveRight(){
        for(int i = 0 ; i < 4; i++){
            for (int j = 3, e; j >= 0; j--){
                if(elemTabla[i][j].val == 0){
                    e = j;
                    while (elemTabla[i][e].val == 0 && e >= 0)
                        e--;
                    if(elemTabla[i][e].val != 0 && e >= 0)
                        elemTabla[i][j].swapBlock(elemTabla[i][e]);
                }
            }
        }
    }
    
    void moveUp(){
        for(int j = 0; j < 4; j++){
            for(int i = 0, e; i < 4; i++){
                if(elemTabla[i][j].val == 0){
                    e = i;
                    while (elemTabla[e][j].val == 0 && e < 4)
                        e++;
                    if(elemTabla[e][j].val != 0 && e < 4)
                        elemTabla[i][j].swapBlock(elemTabla[e][j]);
                }
            }
        }
    }

    void moveDown(){
        for(int j = 0; j < 4; j++){
            for(int i = 3, e; i >= 0; i--){
                if(elemTabla[i][j].val == 0){
                    e = i;
                    while (elemTabla[e][j].val == 0 && e >= 0)
                        e--;
                    if(elemTabla[e][j].val != 0 && e >= 0)
                        elemTabla[i][j].swapBlock(elemTabla[e][j]);
                }
            }
        }
    }

    int addLeft(){
        int add = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                if(elemTabla[i][j].val == elemTabla[i][j+1].val){
                    add += elemTabla[i][j].val*2;
                    elemTabla[i][j].setBlock(i, j, elemTabla[i][j].val*2);
                    elemTabla[i][j+1].setBlock(i, j+1, 0);
                }
                
            }
        }
        moveLeft();
        return add;
    }

    int addRight(){
        int add = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 3; j > 0; j--){
                if(elemTabla[i][j].val == elemTabla[i][j-1].val){
                    add += elemTabla[i][j].val*2;
                    elemTabla[i][j].setBlock(i, j, elemTabla[i][j].val*2);
                    elemTabla[i][j-1].setBlock(i, j-1, 0);
                }
            }
        }
        moveRight();
        return add;
    }

    int addUp(){
        int add  = 0;
        for(int j = 0; j < 4; j++){
            for(int i = 0; i < 4; i++){
                if(elemTabla[i][j].val == elemTabla[i+1][j].val){
                    add += elemTabla[i][j].val*2;
                    elemTabla[i][j].setBlock(i, j, elemTabla[i][j].val*2);
                    elemTabla[i+1][j].setBlock(i+1, j, 0);
                }
             }
        }
        moveUp();
        return add;
    }

    int addDown(){
        int add  = 0;
        for(int j = 0; j < 4; j++){
            for(int i = 3; i > 0; i--){
                if(elemTabla[i][j].val == elemTabla[i-1][j].val){
                    add += elemTabla[i][j].val*2;
                    elemTabla[i][j].setBlock(i, j, elemTabla[i][j].val*2);
                    elemTabla[i-1][j].setBlock(i-1, j, 0);
                }
             }
        }
        moveDown();
        return add;
    }

    ~Board(){}
};

class Game{
private:
    Board tabla; 
    int scor;

public:
    Game():  tabla(), scor(0){
        std::cout << "Constructor Game\n";
    }
    Game(const Game& other): tabla(other.tabla){
        std::cout << "Constructor de copiere Game\n";
    } // constructor de copiere

    Game& operator=(const Game& other){
        std::cout << "operator= copiere Game\n";
        tabla = other.tabla;
        return *this;
    } // operator de copiere

    friend std::ostream& operator<<(std::ostream& os, const Game& gm) {
        os << "   PLAY 2048!\n"; 
        os << "   Scor: " << gm.scor << "\n";
        os << gm.tabla;
        return os;
    } // operator << afisare

    void play(){
        while (1){
            char move = this->readMove();
            if(move == 'q')
                break;
            if(move == 'a'){
                this->tabla.moveLeft();
                this->incScor(tabla.addLeft());
                this->tabla.genNewElement();
                clearScreen();
            }
            if(move == 'd'){
                this->tabla.moveRight();
                this->incScor(tabla.addRight());
                this->tabla.genNewElement();
                clearScreen();

            }
            if(move == 'w'){
                this->tabla.moveUp();
                this->incScor(tabla.addUp());
                this->tabla.genNewElement();
                clearScreen();
            }
            if(move == 's'){
                this->tabla.moveDown();
                this->incScor(tabla.addDown());
                this->tabla.genNewElement();
                clearScreen();

            }
            std::cout << *this;
        }
    }

    void incScor(const int add){
        this->scor += add;
    }
    char readMove(){
        char move;
        std::cin >> move;
        return move;
    }
    void clearScreen(){
        if (system("CLS")) system("clear");
    }

    ~Game(){}
};


int main() {
    //Block a(2);
    //std::cout << "Am creat Block\n";
    Board B;
    //g = h;
    //std::cout << g;
    Game G;
    //B.makeCustomBoard();
   // B.makeBoard();
    G.clearScreen();
    std::cout << G;
    G.play();
    return 0;
}
