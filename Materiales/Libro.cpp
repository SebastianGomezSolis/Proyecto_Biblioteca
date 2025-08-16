//
// Created by sebas on 15/8/2025.
//

#include "Libro.h"

// Constructor con parametros
Libro::Libro(int nC, int nCat, string t, string a, string pC, string eM, bool hpp, string uF) : Material(nC, nCat, t, a, pC, eM, hpp) { ubicacionFisica = uF;}

// Destructor
Libro::~Libro() {}

// Getters
int Libro::getNumeroClasificacion() const { return Material::getNumeroClasificacion(); }
int Libro::getNumeroCatalogo() const { return Material::getNumeroCatalogo(); }
string Libro::getTitulo() const { return Material::getTitulo(); }
string Libro::getAutor() const { return Material::getAutor(); }
string Libro::getPalabrasClave() const { return Material::getPalabrasClave(); }
string Libro::getEstadoMaterial() const { return Material::getEstadoMaterial(); }
bool Libro::getHabilitadoParaPrestamo() const{ return Material::getHabilitadoParaPrestamo(); }
string Libro::getUbicacionFisica(){ return ubicacionFisica; }
string Libro::getTipoMaterial() const { return "Libro"; }

// Setters
void Libro::setNumeroClasificacion(int numeroClasificacion) { Material::setNumeroClasificacion(numeroClasificacion); }
void Libro::setNumeroCatalogo(int numeroCatalogo) { Material::setNumeroCatalogo(numeroCatalogo); }
void Libro::setTitulo(string titulo) { Material::setTitulo(titulo); }
void Libro::setAutor(string autor) { Material::setAutor(autor); }
void Libro::setPalabrasClave(string palabrasClave) { Material::setPalabrasClave(palabrasClave); }
void Libro::setEstadoMaterial(string estadoMaterial) { Material::setEstadoMaterial(estadoMaterial); }
void Libro::setHabilitadoParaPrestamo(bool habilitadoParaPrestamo){ Material::setHabilitadoParaPrestamo(habilitadoParaPrestamo); }
void Libro::setUbicacionFisica(string ubicacionFisica) { this->ubicacionFisica = ubicacionFisica; }

// ToString
string Libro::mostrar() const {
    stringstream s;
    s << "--------- INFORMACION DEL LIBRO ---------" << endl
      << "Tipo de material: " << getTipoMaterial() << endl
      << "Numero de clasificacion: " << Material::getNumeroClasificacion() << endl
      << "Numero de catalogo: " << Material::getNumeroCatalogo() << endl
      << "Titulo: " << Material::getTitulo() << endl
      << "Autor: " << Material::getAutor() << endl
      << "Palabras clave: " << Material::getPalabrasClave() << endl
      << "Estado del material: " << Material::getEstadoMaterial() << endl;
    s << "Habilitado para Prestamo (1 = Habilitado, 0 = Deshabilitado): " << Material::getHabilitadoParaPrestamo() << endl;
    s << "Ubicacion Fisica: : " << ubicacionFisica << endl;
    return s.str();
}

// ToString especifico
string Libro::stringEspecifico() {
    stringstream ss;
    ss << getTipoMaterial() << ";"
       << getNumeroClasificacion() << ";"
       << getNumeroCatalogo() << ";"
       << getTitulo() << ";"
       << getAutor() << ";"
       << getPalabrasClave() << ";"
       << getEstadoMaterial() << ";"
       << (getHabilitadoParaPrestamo() ? "1" : "0") << ";"
       << ubicacionFisica << "\n";
    return ss.str();
}