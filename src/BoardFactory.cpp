//
// Created by bianca on 17.06.2023.
//

#include <memory>

#include "../headers/BoardFactory.h"
#include "../headers/BoardRandom.h"
#include "../headers/BoardFibonacci.h"
#include "../headers/BoardClassic.h"

std::shared_ptr<Board> BoardFactory::build(char mode) {
    if (mode == 'c')
        return  std::make_shared<BoardClassic> ();
    else if(mode == 'f')
        return std::make_shared<BoardFibonacci>();
    else
        return std::make_shared<BoardRandom>();

}
