#include "../headers/Game.h"
#include "../headers/BoardClassic.h"
#include "../headers/Erori.h"
#include "../headers/BoardFibonacci.h"

#include <rlutil.h>

    Game::Game(char mode): scor(0) {
        if (mode == 'c')
            board = std::make_shared<BoardClassic>();
        else
            board = std::make_shared<BoardFibonacci>();

    }
    Game::Game(const Game& other): board(other.board->clone()), scor(other.scor){
    } // constructor de copiere

    Game& Game::operator=(const Game& other){
        board = other.board->clone();
        scor = other.scor;
        return *this;
    } // operator de copiere

    std::ostream& operator<<(std::ostream& os, const Game& gm) {
        os << "   PLAY 2048!\n"; 
        os << "   Scor: " << gm.scor << "\n";
        os << *gm.board;
        return os;
    } // operator << afisare


    void Game::play(){
        clearScreen();
        this->board->makeBoard();
        std::cout << *this;
        while (true){

            char move = readMove();
            if(move == 'q')
                throw EroareGame("Ai oprit jocul!");
            if(move == 'a'){
                this->board->moveLeft();
                this->incScor(board->addLeft());
            }
            if(move == 'd'){
                this->board->moveRight();
                this->incScor(board->addRight());

            }
            if(move == 'w'){
                this->board->moveUp();
                this->incScor(board->addUp());
            }
            if(move == 's'){
                this->board->moveDown();
                this->incScor(board->addDown());

            }
            this->board->genNewElement();
            clearScreen();
            std::cout << *this;

            board->canMakeMove();

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
       // std::cout << "***********************";
        rlutil::cls();
    }

int Game::getScor() const {
    return scor;
}

const std::shared_ptr<Board> &Game::getBoard() const {
    return board;
}
