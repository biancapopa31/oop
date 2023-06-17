//
// Created by bianca on 17.06.2023.
//

#ifndef OOP_BOARDFACTORY_H
#define OOP_BOARDFACTORY_H


#include <memory>
#include "Board.h"

class BoardFactory {

public:

    std::shared_ptr<Board> build(char mode);

};


#endif //OOP_BOARDFACTORY_H
