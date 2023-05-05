#include "../headers/Board.h"


    Board::Board():elemBoard(){
        std::cout << "Constructor Board\n";
    }

    Board::Board(const Board& other){
        std::cout << "Constructor de copiere Board\n";
        for(int i = 0; i < hBoard; i++)
            for(int j = 0; j < wBoard; j++){
                elemBoard[i][j] = other.elemBoard[i][j];
            }
    } // constructor de copiere

    Board& Board::operator=(const Board& other){
        std::cout << "operator= copiere Board\n";
        
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

    void Board::genNewElement(){
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
    
    void Board::moveLeft(){
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

    void Board::moveRight(){
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
    
    void Board::moveUp(){
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

    void Board::moveDown(){
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

    int Board::addLeft(){
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

    int Board::addRight(){
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

    int Board::addUp(){
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

    int Board::addDown(){
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
