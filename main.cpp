#include <iostream>
#include <algorithm>
#include <cstdlib>
//#include <SFML/Graphics.hpp>

class Block{

//friend class Board;

private:    
    int val;
    int pozX, pozY;
   // sf::RectangleShape graphicBoard;

public:
    Block(const int val_ = 0, const int pozX_ = 0, const int pozY_ = 0): val(val_), pozX(pozX_), pozY(pozY_){
        std::cout << "Constructor Block\n";
    } 
    Block(const Block& other): val(other.val), pozX(other.pozX), pozY(other.pozY){
        std::cout << "Constructor de copiere Block\n";
    } // constructor de copiere

    Block& operator=(const Block& other) {
        val = other.val;
        pozX = other.pozX;
        pozY = other.pozY;
        std::cout << "operator= copiere Block\n";
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Block& el) {
        os << el.val << " ";
        return os;
    }

    void setBlock(const int pozX_, const int pozY_, const int val_){
        pozX = pozX_;
        pozY = pozY_;
        val = val_;
    }
    
    Block& swapBlock(Block& other){
        std::swap(val, other.val);
        std::swap(pozX, other.pozX);
        std::swap(pozY, other.pozY);
        return *this;
    }

    int getValBlock () const{
        return val;
    }

    bool isEmpty(){
        return val == 0;
    }


    ~Block(){} 
};

class Board{

//friend class Game;

private:
    static const int hBoard = 4;
    static const int wBoard = 4;
    Block elemBoard[hBoard][wBoard];
   // sf::RectangleShape graphicBoard;


public:
    Board():elemBoard(){
        makeBoard();
        std::cout << "Constructor Board\n";
    }
    Board(const Board& other){
        std::cout << "Constructor de copiere Board\n";
        for(int i = 0; i < hBoard; i++)
            for(int j = 0; j < wBoard; j++){
                elemBoard[i][j] = other.elemBoard[i][j];
            }
    } // constructor de copiere

    Board& operator=(const Board& other){
        std::cout << "operator= copiere Board\n";
        
        for(int i = 0; i < hBoard; i++)
            for(int j = 0; j < wBoard; j++){
                elemBoard[i][j] = other.elemBoard[i][j];
            }
        return *this;
    } // operator de copiere

    friend std::ostream& operator<<(std::ostream& os, const Board& board) {
        for (int i = 0; i < 20 ; i++)
            os << "_";
        os << "\n";
        for (int i = 0; i < 20 ; i++)
            os << " ";
        os << "\n";
        
        for (int i = 0; i < hBoard; i++){
            for(int j = 0; j< wBoard; j++)
                os << "| " << board.elemBoard[i][j] << "|";
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
        elemBoard[1][1].setBlock(1, 1, 2);
        elemBoard[1][3].setBlock(1, 3, 2);
        elemBoard[1][0].setBlock(1, 0, 2);
        elemBoard[1][2].setBlock(1, 2, 2);
        elemBoard[2][1].setBlock(2, 1, 2);
        elemBoard[0][3].setBlock(0, 3, 2);
        elemBoard[3][3].setBlock(3, 3, 4);
        elemBoard[3][0].setBlock(3, 0, 2);
    }*/

   /* void setGraphicBoard(){
        graphicBoard.setSize(sf::Vector2f(430, 430));
        graphicBoard.setOutlineColor(sf::Color(187, 173, 160));
        graphicBoard.setFillColor(sf::Color(187, 173, 160));
        graphicBoard.setOutlineThickness(10);
        graphicBoard.setPosition(185, 85);
    }*/

    void makeBoard(){
        genNewElement();
        genNewElement();

    }

    void genNewElement(){
        int X = rand() %3;
        int Y = rand() %3;
        int val = 1 + rand() %100;
        while (!elemBoard[X][Y].isEmpty())
        {
            X = rand() %3;
            Y = rand() %3;
        }
        if (val%10 == 0)
            elemBoard[X][Y].setBlock(X, Y, 4);
        else
            elemBoard[X][Y].setBlock(X, Y, 2);
    }
    
    void moveLeft(){
        for(int i = 0 ; i < hBoard; i++){
            for (int j = 0, e = 1; j < wBoard; j++){
                if(elemBoard[i][j].getValBlock() == 0){
                    e = j;
                    while (e < wBoard && elemBoard[i][e].getValBlock() == 0)
                        e++;
                    if(e <wBoard && elemBoard[i][e].getValBlock() != 0)
                        elemBoard[i][j].swapBlock(elemBoard[i][e]);
                }
            }
        }
    }

    void moveRight(){
        for(int i = 0 ; i < hBoard; i++){
            for (int j = wBoard-1, e; j >= 0; j--){
                if(elemBoard[i][j].getValBlock() == 0){
                    e = j;
                    while (e >= 0 && elemBoard[i][e].getValBlock() == 0)
                        e--;
                    if(e >= 0 && elemBoard[i][e].getValBlock() != 0)
                        elemBoard[i][j].swapBlock(elemBoard[i][e]);
                }
            }

        }
    }
    
    void moveUp(){
        for(int j = 0; j < wBoard; j++){
            for(int i = 0, e; i < hBoard; i++){
                if(elemBoard[i][j].getValBlock() == 0){
                    e = i;
                    while (e < hBoard && elemBoard[e][j].getValBlock() == 0)
                        e++;
                    if(e < hBoard && elemBoard[e][j].getValBlock() != 0)
                        elemBoard[i][j].swapBlock(elemBoard[e][j]);
                }
            }
        }
    }

    void moveDown(){
        for(int j = 0; j < wBoard; j++){
            for(int i = hBoard-1, e; i >= 0; i--){
                if(elemBoard[i][j].getValBlock() == 0){
                    e = i;
                    while (e >= 0 && elemBoard[e][j].getValBlock() == 0)
                        e--;
                    if(e >= 0 && elemBoard[e][j].getValBlock() != 0)
                        elemBoard[i][j].swapBlock(elemBoard[e][j]);
                }
            }
        }
    }

    int addLeft(){
        int add = 0;
        for(int i = 0; i < hBoard; i++){
            for(int j = 0; j < wBoard-1; j++){
                if(elemBoard[i][j].getValBlock() == elemBoard[i][j+1].getValBlock()){
                    add += elemBoard[i][j].getValBlock()*2;
                    elemBoard[i][j].setBlock(i, j, elemBoard[i][j].getValBlock()*2);
                    elemBoard[i][j+1].setBlock(i, j+1, 0);
                }
                
            }
        }
        moveLeft();
        return add;
    }

    int addRight(){
        int add = 0;
        for(int i = 0; i < hBoard; i++){
            for(int j = wBoard-1; j > 0; j--){
                if(elemBoard[i][j].getValBlock() == elemBoard[i][j-1].getValBlock()){
                    add += elemBoard[i][j].getValBlock()*2;
                    elemBoard[i][j].setBlock(i, j, elemBoard[i][j].getValBlock()*2);
                    elemBoard[i][j-1].setBlock(i, j-1, 0);
                }
            }
        }
        moveRight();
        return add;
    }

    int addUp(){
        int add  = 0;
        for(int j = 0; j < wBoard; j++){
            for(int i = 0; i < hBoard-1; i++){
                if(elemBoard[i][j].getValBlock() == elemBoard[i+1][j].getValBlock()){
                    add += elemBoard[i][j].getValBlock()*2;
                    elemBoard[i][j].setBlock(i, j, elemBoard[i][j].getValBlock()*2);
                    elemBoard[i+1][j].setBlock(i+1, j, 0);
                }
             }
        }
        moveUp();
        return add;
    }

    int addDown(){
        int add  = 0;
        for(int j = 0; j < wBoard; j++){
            for(int i = hBoard-1; i > 0; i--){
                if(elemBoard[i][j].getValBlock() == elemBoard[i-1][j].getValBlock()){
                    add += elemBoard[i][j].getValBlock()*2;
                    elemBoard[i][j].setBlock(i, j, elemBoard[i][j].getValBlock()*2);
                    elemBoard[i-1][j].setBlock(i-1, j, 0);
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
    Board board; 
    int scor;
   // sf::RenderWindow window;

public:
    Game():  board(), scor(0){
        std::cout << "Constructor Game\n";
    }
    Game(const Game& other): board(other.board), scor(0){
        std::cout << "Constructor de copiere Game\n";
    } // constructor de copiere

    Game& operator=(const Game& other){
        std::cout << "operator= copiere Game\n";
        board = other.board;
        scor = other.scor;
        return *this;
    } // operator de copiere

    friend std::ostream& operator<<(std::ostream& os, const Game& gm) {
        os << "   PLAY 2048!\n"; 
        os << "   Scor: " << gm.scor << "\n";
        os << gm.board;
        return os;
    } // operator << afisare

    /*void setWindow(){
        window.create(sf::VideoMode(800, 600), "Play 2048!");
        window.clear (sf::Color(250, 248, 239));
        board.setGraphicBoard();
    }*/

    void play(){
        void setWindow();
        while (1){
            char move = this->readMove();
            if(move == 'q')
                break;
            if(move == 'a'){
                this->board.moveLeft();
                this->incScor(board.addLeft());
                this->board.genNewElement();
                clearScreen();
            }
            if(move == 'd'){
                this->board.moveRight();
                this->incScor(board.addRight());
                this->board.genNewElement();
                clearScreen();

            }
            if(move == 'w'){
                this->board.moveUp();
                this->incScor(board.addUp());
                this->board.genNewElement();
                clearScreen();
            }
            if(move == 's'){
                this->board.moveDown();
                this->incScor(board.addDown());
                this->board.genNewElement();
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
