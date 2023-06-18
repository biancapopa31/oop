#include "../headers/Game.h"
#include "../headers/Erori.h"
#include "../headers/BoardFactory.h"
#include <rlutil.h>
#include <iomanip>

//std::shared_ptr<Game> Game::instance = NULL;


    Game::Game(char mode): scor(0) {
        buildBoard(mode);
    }

 /*   std::shared_ptr<Game> Game::getInstance(char mode) {
        if(instance != NULL){
            return instance;
        }
        else{
            instance = std::shared_ptr<Game>(new Game(mode));
            return instance;
        }
    }
*/

    std::ostream& operator<<(std::ostream& os, const Game& gm) {
        os << "   PLAY 2048!\n"; 
        os << "   Scor: " << gm.scor << "\n";
        os << *gm.board;
        return os;
    } // operator << afisare


    void Game::play(){
        clearScreen();
        this->board->makeBoard();
        board->updateMaxVal();
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
            board->updateMaxVal();

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

void Game::buildBoard(char mode) {
    BoardFactory fact;

    board = fact.build(mode);
}


