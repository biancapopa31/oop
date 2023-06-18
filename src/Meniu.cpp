//
// Created by bianca on 07.05.2023.
//

#include <iostream>
#include <fstream>
#include <string>
#include <rlutil.h>
#include "../headers/Meniu.h"
#include "../headers/Game.h"
#include "../headers/BoardClassic.h"
#include "../headers/Erori.h"
#include "../headers/BoardFibonacci.h"
#include "../headers/BoardRandom.h"


void Meniu::start() {
    char input;

    readStats();
    printMeniu();

    input = readInput();
    clearScreen();

    if(input == 'q')
        return;
    else if(input == 's'){
        printStats();
        input = readInput();
        clearScreen();
        if(input == 'b')
            start();

    } else{
        printGameModes();
        input = readInput();
        std::cout << input;
        clearScreen();
        if(input == 'b')
            start();
        else{
            std::shared_ptr <Game> g = Game::getInstance(input);

            try{
                g->play();
            }
            catch (EroareBlock &err){
                clearScreen();
                std::cout << err.what() << "\nNu s-a putut crea jocul!";
            }
            catch (EroareBoard &err) {
                clearScreen();
                std::cout << err.what() << "\nAi pierdut!";
            }
            catch (EroareGame &err) {
                clearScreen();
                std::cout << err.what();
            }
            if(std::dynamic_pointer_cast<BoardClassic>(g->getBoard()))
                end(g->getScor(), std::dynamic_pointer_cast<BoardClassic>(g->getBoard()));

            else if(std::dynamic_pointer_cast<BoardFibonacci>(g->getBoard()))
                end(g->getScor(), std::dynamic_pointer_cast<BoardFibonacci>(g->getBoard()));

            else if(std::dynamic_pointer_cast<BoardRandom>(g->getBoard()))
                end(g->getScor(), std::dynamic_pointer_cast<BoardRandom>(g->getBoard()));

        }
    }
}

void Meniu::printMeniu() {
    std::cout << "\tPlay 2048!\n\n";
    std::cout << "Play (p)\n";
    std::cout << "Statistics (s)\n";
    std::cout << "Quit (q)\n\n";
    std::cout << "User input: ";
}

void Meniu::readStats() {
    std::string input;
    std::fstream fisier;
    fisier.open("../fis/stats.txt",std::ios::in) ;

    std::getline(fisier,input,' ');
    maxScor = strToChr(input);

    std::getline(fisier,input,' ');
    nrClassicGame = strToChr(input);

    std::getline(fisier,input,' ');
    nrFiboGame = strToChr(input);

    std::getline(fisier,input,' ');
    nrRandomGame = strToChr(input);

    fisier.close();
}
int Meniu::strToChr(const std::string& str) {
    int nr = 0;
    for(auto i : str){
        nr = nr*10 + int(i - '0');
    }
    return nr;
}

void Meniu::printStatsInFile() const {
    std::fstream fisier;
    fisier.open("../fis/stats.txt",std::ios::out | std::ios::trunc) ;
    fisier << maxScor << " " <<nrClassicGame << " " << nrFiboGame << " " << nrRandomGame;
}

void Meniu::printStats() const {
    std::cout << "\tPlay 2048!\n\n";

    std::cout << "Highscore: " << maxScor << "\n";
    std::cout << "Games played in Classic Mode: " << nrClassicGame << "\n";
    std::cout << "Games played in Fibonacci mode: " << nrFiboGame << "\n";
    std::cout << "Games played in Random mode: " << nrRandomGame << "\n";
    std::cout << "Back (b)\n\n";
    std::cout << "User input: ";

}

void Meniu::printGameModes() {
    std::cout << "\tPlay 2048!\n\n";
    std::cout << "Classic (c)\n";
    std::cout << "Fibonacci (f)\n";
    std::cout << "Random (r)\n";
    std::cout << "Back (b)\n\n";
    std::cout << "User input: ";
}

char Meniu::readInput() {
    char input;
    std::cin >> input;
    return  input;
}

template<typename T>
void Meniu::end(int scor, const std::shared_ptr<T> &){
    if(scor > maxScor)
        maxScor = scor;
    nrClassicGame += std::is_same<T, BoardClassic>::value;
    nrFiboGame += std::is_same<T, BoardFibonacci>::value;
    nrRandomGame += std::is_same<T, BoardRandom>::value;

    printStatsInFile();

}

void Meniu::clearScreen() {
    rlutil::cls();
}






