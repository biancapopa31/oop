//
// Created by bianca on 13.05.2023.
//

#include "../headers/Erori.h"

AppError::AppError(const std::string &err) noexcept: logic_error(err) {

}

EroareBoard::EroareBoard(const std::string &err) noexcept: AppError(err) {

}

EroareGame::EroareGame(const std::string &err) noexcept: AppError(err) {

}


EroareBlock::EroareBlock(const std::string &err) noexcept: AppError(err) {

}
