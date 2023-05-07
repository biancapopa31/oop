#pragma once
#include <iostream>
#include <memory>
#include "Board.h"

class Game{
private:
    static void clearScreen();

    static char readMove();

    void incScor(const int add);

public:

    std::shared_ptr<Board> board;
    int scor;

    Game() = delete;

    explicit Game(char);

    Game(const Game& other); // constructor de copiere

    Game& operator=(const Game& other); // operator =

    friend std::ostream& operator<<(std::ostream& os, const Game& gm); // operator << afisare

    void play();


    ~Game() = default;
};