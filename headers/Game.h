#pragma once
#include <iostream>
#include <memory>
#include "Board.h"

class Game{
private:
    static void clearScreen();

    static char readMove();

    void incScor(int add);

    explicit Game(char input);

    std::shared_ptr<Board> board;
    int scor;
    static std::shared_ptr<Game> instance;


public:

    Game() = delete;

    static std::shared_ptr<Game> getInstance(char);

    Game(const Game& other) = delete; // constructor de copiere

    Game& operator=(const Game& other) = delete; // operator =

    friend std::ostream& operator<<(std::ostream& os, const Game& gm); // operator << afisare

    void buildBoard(char);

    int getScor() const;

    const std::shared_ptr<Board> &getBoard() const;

    void play();

    ~Game() = default;
};