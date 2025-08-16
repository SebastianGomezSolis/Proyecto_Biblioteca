//
// Created by sebas on 15/8/2025.
//

#include "Video.h"

// Constructor con parametros
Video::Video(int nC, int nCat, string t, string a, string pC, string eM, bool hpp) : Material(nC, nCat, t, a, pC, eM, hpp) {}

// Destructor
Video::~Video() {}

// Getters
int Video::getNumeroClasificacion() const { return Material::getNumeroClasificacion(); }
int Video::getNumeroCatalogo() const { return Material::getNumeroCatalogo(); }
string Video::getTitulo() const { return Material::getTitulo(); }
string Video::getAutor() const { return Material::getAutor(); }
string Video::getPalabrasClave() const { return Material::getPalabrasClave(); }
string Video::getEstadoMaterial() const { return Material::getEstadoMaterial(); }
bool Video::getHabilitadoParaPrestamo() const { return Material::getHabilitadoParaPrestamo(); }
string Video::getTipoMaterial() const { return "Video"; }

// Setters
void Video::setNumeroClasificacion(int numeroClasificacion) { Material::setNumeroClasificacion(numeroClasificacion); }
void Video::setNumeroCatalogo(int numeroCatalogo) { Material::setNumeroCatalogo(numeroCatalogo); }
void Video::setTitulo(string titulo) { Material::setTitulo(titulo); }
void Video::setAutor(string autor) { Material::setAutor(autor); }
void Video::setPalabrasClave(string palabrasClave) { Material::setPalabrasClave(palabrasClave); }
void Video::setEstadoMaterial(string estadoMaterial) { Material::setEstadoMaterial(estadoMaterial); }
void Video::setHabilitadoParaPrestamo(bool habilitadoParaPrestamo){ Material::setHabilitadoParaPrestamo(habilitadoParaPrestamo); }

// ToString
string Video::mostrar() const {
    stringstream s;
    s << "--------- INFORMACION DEL VIDEO ---------" << endl
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
string Video::stringEspecifico() {
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
