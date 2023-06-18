#include "headers/Meniu.h"


int main() {


    std::shared_ptr<Meniu> m = Meniu::getInstance();
    m->start();

    //std::shared_ptr<Game> m = Game::getInstance('c');

    return 0;
}
