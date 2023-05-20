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
        clearScreen();
        if(input == 'b')
            start();
        else{
            Game g(input);
            try{
                g.play();
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
            end(g.getScor(), g.getBoard());
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
    fisier << maxScor << " " <<nrClassicGame << " " << nrFiboGame;
}

void Meniu::printStats() const {

    std::cout << "Highscore: " << maxScor << "\n";
    std::cout << "Games played in Classic Mode: " << nrClassicGame << "\n";
    std::cout << "Games played in Fibonacci mode: " << nrFiboGame << "\n";
    std::cout << "Back (b)\n";
    std::cout << "User input: ";

}

void Meniu::printGameModes() {
    std::cout << "\n\tPlay 2048!\n\n";
    std::cout << "Classic (c)\n";
    std::cout << "Fibonacci (f)\n";
    std::cout << "Back (b)\n";
    std::cout << "User input: ";
}

char Meniu::readInput() {
    char input;
    std::cin >> input;
    return  input;
}

void Meniu::end(int scor, const std::shared_ptr<Board>& board) {

    if(scor > maxScor)
        maxScor = scor;
    if(std::dynamic_pointer_cast<BoardClassic>(board))
        nrClassicGame++;

    printStatsInFile();
}

void Meniu::clearScreen() {
    rlutil::cls();
}






