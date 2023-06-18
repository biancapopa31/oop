//
// Created by bianca on 18.06.2023.
//

#ifndef OOP_SINGLETONTEMPLATE_H
#define OOP_SINGLETONTEMPLATE_H

#include <memory>
//#include "Game.h"

template <typename T>
class SingletonTemplate {
private:
    static std::shared_ptr<T> instance;
protected:
    SingletonTemplate() = default;
    explicit SingletonTemplate(char mode) {};
    virtual ~SingletonTemplate() = default;

public:
    static std::shared_ptr<T> getInstance(){
        if(instance != nullptr)
            return instance;
        else{
            instance = std::shared_ptr<T>(new T);
            return instance;
        }
    };

    static std::shared_ptr<T> getInstance(char mode){
        if(instance != nullptr)
            return instance;
        else{
            instance = std::shared_ptr<T>(new T(mode));
            return instance;
        }
    };

    SingletonTemplate (const SingletonTemplate&) = delete;

    SingletonTemplate& operator= (const SingletonTemplate) = delete;

};

template <typename T>
std::shared_ptr<T> SingletonTemplate<T>:: instance = nullptr;
/*
template<typename T>
std::shared_ptr<T> SingletonTemplate<T>::getInstance(char mode) {
    if(instance != nullptr)
        return instance;
    else{
        instance = std::shared_ptr<T>(new T(mode));
        return instance;
    }
}

template<typename T>
std::shared_ptr<T> SingletonTemplate<T>::getInstance() {
    if(instance != nullptr)
        return instance;
    else{
        instance = std::shared_ptr<T>(new T);
        return instance;
    }
}
*/



#endif //OOP_SINGLETONTEMPLATE_H
