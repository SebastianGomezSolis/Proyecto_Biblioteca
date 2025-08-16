//
// Created by sebas on 15/8/2025.
//

#include "Articulo.h"

// Constructor con parametros
Articulo::Articulo(int nC, int nCat, string t, string a, string pC, string eM, bool hpp) : Material(nC, nCat, t, a, pC, eM, hpp) {}

// Destructor
Articulo::~Articulo() {}

// Getters
int Articulo::getNumeroClasificacion() const { return Material::getNumeroClasificacion(); }
int Articulo::getNumeroCatalogo() const { return Material::getNumeroCatalogo(); }
string Articulo::getTitulo() const { return Material::getTitulo(); }
string Articulo::getAutor() const { return Material::getAutor(); }
string Articulo::getPalabrasClave() const { return Material::getPalabrasClave(); }
string Articulo::getEstadoMaterial() const { return Material::getEstadoMaterial(); }
bool Articulo::getHabilitadoParaPrestamo() const{ return Material::getHabilitadoParaPrestamo(); }
string Articulo::getTipoMaterial() const { return "Articulo"; }

// Setters
void Articulo::setNumeroClasificacion(int numeroClasificacion) { Material::setNumeroClasificacion(numeroClasificacion); }
void Articulo::setNumeroCatalogo(int numeroCatalogo) { Material::setNumeroCatalogo(numeroCatalogo); }
void Articulo::setTitulo(string titulo) { Material::setTitulo(titulo); }
void Articulo::setAutor(string autor) { Material::setAutor(autor); }
void Articulo::setPalabrasClave(string palabrasClave) { Material::setPalabrasClave(palabrasClave); }
void Articulo::setEstadoMaterial(string estadoMaterial) { Material::setEstadoMaterial(estadoMaterial); }
void Articulo::setHabilitadoParaPrestamo(bool habilitadoParaPrestamo){ Material::setHabilitadoParaPrestamo(habilitadoParaPrestamo); }

// ToString
string Articulo::mostrar() const {
    stringstream s;
    s << "--------- INFORMACION DEL ARTICULO ---------" << endl
      << "Tipo de material: " << getTipoMaterial() << endl
      << "Numero de clasificacion: " << Material::getNumeroClasificacion() << endl
      << "Numero de catalogo: " << Material::getNumeroCatalogo() << endl
      << "Titulo: " << Material::getTitulo() << endl
      << "Autor: " << Material::getAutor() << endl
      << "Palabras clave: " << Material::getPalabrasClave() << endl
      << "Estado del material: " << Material::getEstadoMaterial() << endl;
    s << "Habilitado para Prestamo (1 = Habilitado, 0 = Deshabilitado): " << Material::getHabilitadoParaPrestamo() << endl;
    return s.str();
}

// ToString especifico
string Articulo::stringEspecifico() {
    stringstream ss;
    ss << getTipoMaterial() << ";"
       << getNumeroClasificacion() << ";"
       << getNumeroCatalogo() << ";"
       << getTitulo() << ";"
       << getAutor() << ";"
       << getPalabrasClave() << ";"
       << getEstadoMaterial() << ";"
       << (getHabilitadoParaPrestamo() ? "1" : "0") << "\n";
    return ss.str();
}