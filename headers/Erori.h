//
// Created by bianca on 13.05.2023.
//

#ifndef OOP_ERORI_H
#define OOP_ERORI_H


#include <stdexcept>

class AppError : public std::logic_error{
public:
    explicit AppError(const std::string &err) noexcept;

};

class EroareGame : public AppError{
public:
    explicit EroareGame(const std::string &err) noexcept;
};

class EroareBoard : public AppError{
public:
    explicit EroareBoard(const std::string &err) noexcept;

};

class EroareBlock : public AppError{
public:
    explicit EroareBlock(const std::string &err) noexcept;

};


#endif //OOP_ERORI_H
