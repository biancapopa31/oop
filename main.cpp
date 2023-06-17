#include "headers/Meniu.h"


int main() {


    std::shared_ptr<Meniu> m = Meniu::getInstance();
    m->start();

    return 0;
}
