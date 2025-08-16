//
// Created by sebas on 15/8/2025.
//

#include "Excepciones.h"

void Excepciones::handleUnknownMaterialType(const std::string& tipoMaterial) {
    std::cerr << "Tipo de material no reconocido: \"" << tipoMaterial << "\". Por favor ingrese un Material Valido (Solo la primera Mayuscula y bien Escrita)" << std::endl;
    std::cerr << "Presione Enter para Volver al Menu ";
}

void Excepciones::EmptyList() {
    std::cerr << "El Catalogo no contiene ningun Material Registrado o error en la Iniciacion" << std::endl;
    std::cerr << "Presione Enter para Volver al Menu ";
}

void Excepciones::ErrorPrestamo() {
    std::cerr << "No se pudo Registrar el Prestamo" << std::endl;
    std::cerr << "Presione Enter para Volver al Menu ";
}

void Excepciones::PrestamoInactivo() {
    std::cerr << "No se encontro un préstamo activo con los datos ingresados" << std::endl;
    std::cerr << "Presione Enter para Volver al Menu ";
}

void Excepciones::NumberOfDaysExceeded(const int& dias) {
    std::cerr << "El numero de dias para el Prestamo se Excede del Limite: \"" << dias << "\". En el registro de la Biblioteca" << std::endl;
    std::cerr << "Presione Enter para Volver al Menu ";
}

void Excepciones::handleUnknownTitleType(const std::string& nombreTitulo) {
    std::cerr << "No existe un Material: \"" << nombreTitulo << "\". En el registro de la Biblioteca" << std::endl;
    std::cerr << "Presione Enter para Volver al Menu ";
}

void Excepciones::NoHabilitado() {
    std::cerr << "El Material NO esta Habilitado para Prestamo" << std::endl;
    std::cerr << "Presione Enter para Volver al Menu ";
}

void Excepciones::handleUnknownTitleName(const std::string& nombre) {
    std::cerr << "No existe un Usuario Con el Nombre: \"" << nombre << "\". En el registro de la Biblioteca" << std::endl;
    std::cerr << "Presione Enter para Volver al Menu ";
}

void Excepciones::handleUnknownIDType(const std::string& ID) {
    std::cerr << "No existe un ID: \"" << ID << "\". En el registro de la Biblioteca" << std::endl;
    std::cerr << "Presione Enter para Volver al Menu ";
}

void Excepciones::handleInvalidInput(const std::string &input) {
    std::cerr << "Entrada Invalida: \"" << input << "\". Por favor Ingrese una Entrada Valida" << std::endl;
    std::cerr << "Presione Enter para Volver al Menu ";
}

void Excepciones::handleUnhandledException(const std::exception &e) {
    std::cerr << "Excepcion Sin Manejar: " << e.what() << std::endl;
    std::cerr << "Presione Enter para Volver al Menu ";
}

void Excepciones::OpcionInvalidaMenu() {
    std::cerr << "\nLa opcion seleccionada no es valida. Por favor, intente nuevamente." << std::endl;
    std::cerr << "Presione Enter para volver al menu principal..." << std::endl;
}
