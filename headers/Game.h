#pragma once
#include <iostream>
#include "Board.h"

class Game{
private:
    Board board; 
    int scor;
   // sf::RenderWindow window;

public:
    Game();

    Game(const Game& other); // constructor de copiere

    Game& operator=(const Game& other); // operator =

    friend std::ostream& operator<<(std::ostream& os, const Game& gm); // operator << afisare

    /*void setWindow();*/

    void play();

    void incScor(const int add);

    char readMove();

    void clearScreen();

    ~Game();
};