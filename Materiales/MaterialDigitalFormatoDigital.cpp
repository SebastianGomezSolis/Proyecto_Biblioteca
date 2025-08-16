//
// Created by sebas on 15/8/2025.
//

#include "MaterialDigitalFormatoDigital.h"

// Constructor con parametros
MaterialDigitalFormatoDigital::MaterialDigitalFormatoDigital(int nC, int nCat, string t, string a, string pC, string eM, bool hpp, string tipo) : materialDigital(nC, nCat, t, a, pC, eM, hpp, tipo) {}

// Destructor
MaterialDigitalFormatoDigital::~MaterialDigitalFormatoDigital() {}

// Getters
int MaterialDigitalFormatoDigital::getNumeroClasificacion() const { return Material::getNumeroClasificacion(); }
int MaterialDigitalFormatoDigital::getNumeroCatalogo() const { return Material::getNumeroCatalogo(); }
string MaterialDigitalFormatoDigital::getTitulo() const { return Material::getTitulo(); }
string MaterialDigitalFormatoDigital::getAutor() const { return Material::getAutor(); }
string MaterialDigitalFormatoDigital::getPalabrasClave() const { return Material::getPalabrasClave(); }
string MaterialDigitalFormatoDigital::getEstadoMaterial() const { return Material::getEstadoMaterial(); }
bool MaterialDigitalFormatoDigital::getHabilitadoParaPrestamo() const { return Material::getHabilitadoParaPrestamo(); }
string MaterialDigitalFormatoDigital::getTipo() const { return materialDigital::getTipo(); }
string MaterialDigitalFormatoDigital::getTipoMaterial() const { return "Material Digital"; }

// Setters
void MaterialDigitalFormatoDigital::setNumeroClasificacion(int numeroClasificacion) { Material::setNumeroClasificacion(numeroClasificacion); }
void MaterialDigitalFormatoDigital::setNumeroCatalogo(int numeroCatalogo) { Material::setNumeroCatalogo(numeroCatalogo); }
void MaterialDigitalFormatoDigital::setTitulo(string titulo) { Material::setTitulo(titulo); }
void MaterialDigitalFormatoDigital::setAutor(string autor) { Material::setAutor(autor); }
void MaterialDigitalFormatoDigital::setPalabrasClave(string palabrasClave) { Material::setPalabrasClave(palabrasClave); }
void MaterialDigitalFormatoDigital::setEstadoMaterial(string estadoMaterial) { Material::setEstadoMaterial(estadoMaterial); }
void MaterialDigitalFormatoDigital::setHabilitadoParaPrestamo(bool habilitadoParaPrestamo) { Material::setHabilitadoParaPrestamo(habilitadoParaPrestamo); }

// ToString
string MaterialDigitalFormatoDigital::mostrar() const {
    stringstream s;
    s << "--------- INFORMACION DEL MATERIAL DIGITAL ---------" << endl
      << "Tipo de material: " << getTipoMaterial() << endl
      << "Numero de clasificacion: " << Material::getNumeroClasificacion() << endl
      << "Numero de catalogo: " << Material::getNumeroCatalogo() << endl
      << "Titulo: " << Material::getTitulo() << endl
      << "Autor: " << Material::getAutor() << endl
      << "Palabras clave: " << Material::getPalabrasClave() << endl
      << "Estado del material: " << Material::getEstadoMaterial() << endl;
    s << "Habilitado para Prestamo (1 = Habilitado, 0 = Deshabilitado): " << Material::getHabilitadoParaPrestamo() << endl;
    s << "Tipo: " << materialDigital::getTipo() <<endl;
    return s.str();
}

// ToString especifico
string MaterialDigitalFormatoDigital::stringEspecifico() {
    stringstream ss;
    ss << getTipoMaterial() << ";"
       << getNumeroClasificacion() << ";"
       << getNumeroCatalogo() << ";"
       << getTitulo() << ";"
       << getAutor() << ";"
       << getPalabrasClave() << ";"
       << getEstadoMaterial() << ";"
       << (getHabilitadoParaPrestamo() ? "1" : "0") << ";"
       << getTipo() << "\n";
    return ss.str();
}