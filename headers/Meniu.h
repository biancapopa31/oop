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

public:
    Meniu() = default;

    void start();

    static void printMeniu();

    void printStatsInFile() const;

    void printStats() const;

    static void printGameModes();

    static char readInput();

    void end(int , const std::shared_ptr<Board>&);

    void readStats();

    static int strToChr(const std::string&);


};


#endif //OOP_MENIU_H
