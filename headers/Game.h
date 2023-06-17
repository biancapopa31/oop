#pragma once
#include <iostream>
#include <memory>
#include "Board.h"

class Game{
private:
    static void clearScreen();

    static char readMove();

    void incScor(int add);

    std::shared_ptr<Board> board;
    int scor;

public:

    Game() = delete;

    explicit Game(char input);

    Game(const Game& other); // constructor de copiere

    Game& operator=(const Game& other); // operator =

    friend std::ostream& operator<<(std::ostream& os, const Game& gm); // operator << afisare

    void buildBoard(char);

    int getScor() const;

    const std::shared_ptr<Board> &getBoard() const;

    void play();

    ~Game() = default;
};