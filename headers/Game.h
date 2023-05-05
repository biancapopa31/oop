#pragma once
#include <iostream>
#include <memory>
#include "Board.h"

class Game{
private:
    std::shared_ptr<Board> board;
    int scor;

public:
    Game() = delete;

    Game(bool);

    Game(const Game& other); // constructor de copiere

    Game& operator=(const Game& other); // operator =

    friend std::ostream& operator<<(std::ostream& os, const Game& gm); // operator << afisare

    void play();

    void incScor(const int add);

    static char readMove();

    static void clearScreen();

    ~Game() = default;
};