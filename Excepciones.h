//
// Created by sebas on 15/8/2025.
//

#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <iostream>
#include <stdexcept>
#include <string>

class Excepciones {
public:

    static void handleUnknownMaterialType(const std::string& tipoMaterial);

    static void EmptyList();

    static void ErrorPrestamo();

    static void PrestamoInactivo();

    static void NumberOfDaysExceeded(const int& dias);

    static void handleUnknownTitleType(const std::string& nombreTitulo);

    static void NoHabilitado();

    static void handleUnknownTitleName(const std::string& nombre);

    static void handleUnknownIDType(const std::string& id);

    static void handleInvalidInput(const std::string &input);

    static void handleUnhandledException(const std::exception &e);

    static void OpcionInvalidaMenu();
};



#endif //EXCEPCIONES_H