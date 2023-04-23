#include "../headers/Game.h"
#include <cstdlib>
//#include <SFML/Graphics.hpp>

    Game::Game():  board(), scor(0){
        std::cout << "Constructor Game\n";
    }
    Game::Game(const Game& other): board(other.board), scor(0){
        std::cout << "Constructor de copiere Game\n";
    } // constructor de copiere

    Game& Game::operator=(const Game& other){
        std::cout << "operator= copiere Game\n";
        board = other.board;
        scor = other.scor;
        return *this;
    } // operator de copiere

    std::ostream& operator<<(std::ostream& os, const Game& gm) {
        os << "   PLAY 2048!\n"; 
        os << "   Scor: " << gm.scor << "\n";
        os << gm.board;
        return os;
    } // operator << afisare

    /*void Game::setWindow(){
        window.create(sf::VideoMode(800, 600), "Play 2048!");
        window.clear (sf::Color(250, 248, 239));
        board.setGraphicBoard();
    }*/

    void Game::play(){
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

    void Game::incScor(const int add){
        this->scor += add;
    }
    char Game::readMove(){
        char move;
        std::cin >> move;
        return move;
    }
    void Game::clearScreen(){
        if (system("CLS")) system("clear");
    }

    Game::~Game(){}
