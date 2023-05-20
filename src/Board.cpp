#include "../headers/Board.h"
#include "../headers/Erori.h"


Board::Board(){
        for (int i = 0; i < hBoard; i++){
            std::vector <std::shared_ptr<Block>> aux;
            for (int j = 0; j <wBoard; j++){
                std::shared_ptr<Block> b(new Block(0,i,j));
                aux.push_back(b);
            }
            elemBoard.push_back(aux);
        }

        //std::cout << "Constructor Board\n";
    }

    Board::Board(const Board& other){
       // std::cout << "Constructor de copiere Board\n";
        for(int i = 0; i < hBoard; i++)
            for(int j = 0; j < wBoard; j++){
                elemBoard[i][j] = other.elemBoard[i][j];
            }
    } // constructor de copiere

    Board& Board::operator=(const Board& other){
       // std::cout << "operator= copiere Board\n";
        
        for(int i = 0; i < hBoard; i++)
            for(int j = 0; j < wBoard; j++){
                elemBoard[i][j] = other.elemBoard[i][j];
            }
        return *this;
    } // operator de copiere

    std::ostream& operator<<(std::ostream& os, const Board& board) {
        for (int i = 0; i < 20 ; i++)
            os << "_";
        os << "\n";
        for (int i = 0; i < 20 ; i++)
            os << " ";
        os << "\n";
        
        for (int i = 0; i < Board::hBoard; i++){
            for(int j = 0; j< Board::wBoard; j++)
                os << "| " << *board.elemBoard[i][j] << "|";
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

    /*void Board::makeCustomBoard(){
        elemBoard[1][1].setBlock(1, 1, 2);
        elemBoard[1][3].setBlock(1, 3, 2);
        elemBoard[1][0].setBlock(1, 0, 2);
        elemBoard[1][2].setBlock(1, 2, 2);
        elemBoard[2][1].setBlock(2, 1, 2);
        elemBoard[0][3].setBlock(0, 3, 2);
        elemBoard[3][3].setBlock(3, 3, 4);
        elemBoard[3][0].setBlock(3, 0, 2);
    }*/


    void Board::makeBoard(){
        genNewElement();
        genNewElement();

    }
    bool Board::isFull(){
        for (int i = 0; i < hBoard; i++){
            for (int j = 0; j < wBoard; j++){
                if(elemBoard[i][j]->isEmpty())
                    return false;
            }
        }
        return true;
    }

    
    void Board::moveLeft(){
        for(int i = 0 ; i < hBoard; i++){
            for (int j = 0, e; j < wBoard; j++){
                if(elemBoard[i][j]->getValBlock() == 0){
                    e = j;
                    while (e < wBoard && elemBoard[i][e]->getValBlock() == 0)
                        e++;
                    if(e <wBoard && elemBoard[i][e]->getValBlock() != 0)
                        swap(elemBoard[i][j], elemBoard[i][e]);
                }
            }
        }
    }

    void Board::moveRight(){
        for(int i = 0 ; i < hBoard; i++){
            for (int j = wBoard-1, e; j >= 0; j--){
                if(elemBoard[i][j]->getValBlock() == 0){
                    e = j;
                    while (e >= 0 && elemBoard[i][e]->getValBlock() == 0)
                        e--;
                    if(e >= 0 && elemBoard[i][e]->getValBlock() != 0)
                        swap(elemBoard[i][j], elemBoard[i][e]);
                }
            }

        }
    }
    
    void Board::moveUp(){
        for(int j = 0; j < wBoard; j++){
            for(int i = 0, e; i < hBoard; i++){
                if(elemBoard[i][j]->getValBlock() == 0){
                    e = i;
                    while (e < hBoard && elemBoard[e][j]->getValBlock() == 0)
                        e++;
                    if(e < hBoard && elemBoard[e][j]->getValBlock() != 0)
                        swap(elemBoard[i][j], elemBoard[e][j]);
                }
            }
        }
    }

    void Board::moveDown(){
        for(int j = 0; j < wBoard; j++){
            for(int i = hBoard-1, e; i >= 0; i--){
                if(elemBoard[i][j]->getValBlock() == 0){
                    e = i;
                    while (e >= 0 && elemBoard[e][j]->getValBlock() == 0)
                        e--;
                    if(e >= 0 && elemBoard[e][j]->getValBlock() != 0)
                        swap(elemBoard[i][j], elemBoard[e][j]);
                }
            }
        }
    }

int Board::addLeft() {
    int add = 0;
    for(int i = 0; i < hBoard; i++){
        for(int j = 0; j < wBoard-1; j++){
            if(canBeAdded(elemBoard[i][j], elemBoard[i][j+1])){
                add += elemBoard[i][j]->getValBlock() + elemBoard[i][j+1]->getValBlock() ;
                elemBoard[i][j]->setBlock(i, j, elemBoard[i][j]->getValBlock() + elemBoard[i][j+1]->getValBlock());
                elemBoard[i][j+1]->setBlock(i, j+1, 0);
            }

        }
    }
    moveLeft();
    return add;
}

int Board::addRight() {
    int add = 0;
    for(int i = 0; i < hBoard; i++){
        for(int j = wBoard-1; j > 0; j--){
            if(canBeAdded(elemBoard[i][j], elemBoard[i][j-1])){
                add += elemBoard[i][j]->getValBlock() + elemBoard[i][j-1]->getValBlock();
                elemBoard[i][j]->setBlock(i, j, elemBoard[i][j]->getValBlock() + elemBoard[i][j-1]->getValBlock());
                elemBoard[i][j-1]->setBlock(i, j-1, 0);
            }
        }
    }
    moveRight();
    return add;
}

int Board::addUp() {
    int add  = 0;
    for(int j = 0; j < wBoard; j++){
        for(int i = 0; i < hBoard-1; i++){
            if(canBeAdded(elemBoard[i][j], elemBoard[i+1][j])){
                add += elemBoard[i][j]->getValBlock() + elemBoard[i+1][j]->getValBlock();
                elemBoard[i][j]->setBlock(i, j, elemBoard[i][j]->getValBlock() + elemBoard[i+1][j]->getValBlock());
                elemBoard[i+1][j]->setBlock(i+1, j, 0);
            }
        }
    }
    moveUp();
    return add;
}

int Board::addDown() {
    int add  = 0;
    for(int j = 0; j < wBoard; j++){
        for(int i = hBoard-1; i > 0; i--){
            if(canBeAdded(elemBoard[i][j], elemBoard[i-1][j])){
                add += elemBoard[i][j]->getValBlock() + elemBoard[i-1][j]->getValBlock();
                elemBoard[i][j]->setBlock(i, j, elemBoard[i][j]->getValBlock() + elemBoard[i-1][j]->getValBlock());
                elemBoard[i-1][j]->setBlock(i-1, j, 0);
            }
        }
    }
    moveDown();
    return add;
}

void Board::canMakeMove() {
    if(!this->isFull())
        return;

    throw EroareBoard("Nu se mai pot face mutari!");

}


