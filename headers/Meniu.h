//
// Created by bianca on 07.05.2023.
//

#ifndef OOP_MENIU_H
#define OOP_MENIU_H


#include <ostream>
#include <memory>
#include "Board.h"

class Meniu {

    int maxScor;
    int nrClassicGame;
    int nrFiboGame;
    int nrRandomGame;

    Meniu() = default;

    static std::shared_ptr<Meniu> instance;

public:

    static std::shared_ptr<Meniu> getInstance();

    Meniu (const Meniu&) = delete;

    Meniu& operator=(const Meniu& other) = delete;

    void start();

    static void printMeniu();

    void printStatsInFile() const;

    void printStats() const;

    static void printGameModes();

    static char readInput();

    template<class T>
    void end(int scor, const std::shared_ptr<T> &board);

   // void end(int , const std::shared_ptr<Board>&);

    void readStats();

    static int strToChr(const std::string&);

    static void clearScreen();


};


#endif //OOP_MENIU_H
