#include <iostream>
#include <algorithm>

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

    ~Block(){} 
};

class Board{

friend class Game;

private:
    Block elemTabla[4][4];

public:
    Board():elemTabla(){
        makeCustomBoard();
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

    void makeCustomBoard(){
        elemTabla[1][1].setBlock(1, 1, 2);
        elemTabla[1][3].setBlock(1, 3, 2);
        elemTabla[1][0].setBlock(1, 0, 2);
        elemTabla[1][2].setBlock(1, 2, 2);
        elemTabla[2][1].setBlock(2, 1, 2);
        elemTabla[0][3].setBlock(0, 3, 2);
        elemTabla[3][3].setBlock(3, 3, 4);
        elemTabla[3][0].setBlock(3, 0, 2);
    }

    void moveLeft(){
        for(int i = 0 ; i < 4; i++){
            for (int j = 0, e = 1; j < 4; j++){
                if(elemTabla[i][j].val == 0){
                    e = j;
                    while (elemTabla[i][e].val == 0 && e < 4)
                        e++;
                    if(elemTabla[i][j].val == 0 && elemTabla[i][e].val != 0 && e < 4)
                        elemTabla[i][j].swapBlock(elemTabla[i][e]);
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


    ~Board(){}
};

class Game{
private:
    Board tabla; 
    int scor;

public:
    Game(): scor(0), tabla(){
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
            if(move == 'l'){
                this->tabla.moveLeft();
                this->incScor(tabla.addLeft());
                std::cout << "stanga\n";
            }
            if(move == 'r')
                std::cout << "dreapta\n";
            if(move == 'u')
                std::cout << "sus\n";
            if(move == 'd')
                std::cout << "jos\n";
            //this->incScor(1);
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

    ~Game(){}
};


int main() {
    //Block a(2);
    //std::cout << "Am creat Block\n";
    Board B;
    //g = h;
    //std::cout << g;
    Game G;
    B.makeCustomBoard();
    std::cout << G;
    G.play();
    return 0;
}
