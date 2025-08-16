//
// Created by sebas on 15/8/2025.
//

#include "materialDigital.h"

// Constructor con parametros
materialDigital::materialDigital(int nC, int nCat, string t, string a, string pC, string eM, bool hpp, string tipo) : Material(nC, nCat, t, a, pC, eM) { this->tipo = tipo;}

// Destructor
materialDigital::~materialDigital() {}
\
// Getters
int materialDigital::getNumeroClasificacion() const { return Material::getNumeroClasificacion(); }
int materialDigital::getNumeroCatalogo() const { return Material::getNumeroCatalogo(); }
string materialDigital::getTitulo() const { return Material::getTitulo(); }
string materialDigital::getAutor() const { return Material::getAutor(); }
string materialDigital::getPalabrasClave() const { return Material::getPalabrasClave(); }
string materialDigital::getEstadoMaterial() const { return Material::getEstadoMaterial(); }
bool materialDigital::getHabilitadoParaPrestamo() const{ return Material::getHabilitadoParaPrestamo(); }
string materialDigital::getTipoMaterial() const { return "Material Digital"; }
string materialDigital::getTipo() const { return tipo; }

// Setters
void materialDigital::setNumeroClasificacion(int numeroClasificacion) { Material::setNumeroClasificacion(numeroClasificacion); }
void materialDigital::setNumeroCatalogo(int numeroCatalogo) { Material::setNumeroCatalogo(numeroCatalogo); }
void materialDigital::setTitulo(string titulo) { Material::setTitulo(titulo); }
void materialDigital::setAutor(string autor) { Material::setAutor(autor); }
void materialDigital::setPalabrasClave(string palabrasClave) { Material::setPalabrasClave(palabrasClave); }
void materialDigital::setEstadoMaterial(string estadoMaterial) { Material::setEstadoMaterial(estadoMaterial); }
void materialDigital::setHabilitadoParaPrestamo(bool habilitadoParaPrestamo){ Material::setHabilitadoParaPrestamo(habilitadoParaPrestamo); }