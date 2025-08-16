//
// Created by sebas on 15/8/2025.
//

#ifndef MENU_H
#define MENU_H


#include "Utilities.h"
#include "Biblioteca.h"


class Menu {
private:
    Biblioteca* library;
public:
    Menu();
    ~Menu();
    void mostrarMenu();
};



#endif //MENU_H
