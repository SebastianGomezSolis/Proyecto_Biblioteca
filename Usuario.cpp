//
// Created by sebas on 15/8/2025.
//

#include "Usuario.h"

// Constructor por con parametros
Usuario::Usuario(string i, string n, string ap, string ap2, bool estado) : id(i), nombre(n), apellido1(ap), apellido2(ap2), estado(estado) {}

// Destructor
Usuario::~Usuario() {}

// Getters
string Usuario::getId() const { return id; }
string Usuario::getNombre() const { return nombre; }
string Usuario::getApellido1() const { return apellido1; }
string Usuario::getApellido2() const { return apellido2; }
bool Usuario::getEstado() const { return estado; }

// Setters
void Usuario::setId(string id) { this->id = id; }
void Usuario::setNombre(string nombre) { this->nombre = nombre; }
void Usuario::setApellido1(string apellido1) { this->apellido1 = apellido1; }
void Usuario::setApellido2(string apellido2) { this->apellido2 = apellido2; }
void Usuario::setEstado(bool estado) { this->estado = estado; }

// ToString
string Usuario::mostrar() {
    stringstream s;
    cout << "--------- INFORMACION DEL USUARIO ---------" << endl;
    s << "ID: " << id << endl;
    s << "Nombre: " << nombre << endl;
    s << "Apellido1: " << apellido1 << endl;
    s << "Apellido2: " << apellido2 << endl;
    s << "Estado: " << estado << endl;
    return s.str();
}

// ToString especifico para guardar en archivo
string Usuario::stringEspecifico() {
    return id + ";" + nombre + ";" + apellido1 + ";" + apellido2 + ";" + (estado ? "1" : "0") + "\n";
}