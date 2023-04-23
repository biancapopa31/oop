#include "headers/Block.h"
#include "headers/Board.h"
#include "headers/Game.h"


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
