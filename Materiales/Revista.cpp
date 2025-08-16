//
// Created by sebas on 15/8/2025.
//

#include "Revista.h"

// Constructor con parametros
Revista::Revista(int nC, int nCat, string t, string a, string pC, string eM, bool hpp, int n, int v, string uF) : Material(nC, nCat, t, a, pC, eM, hpp) { numero = n; volumen = v; ubicacionFisica = uF;}

// Destructor
Revista::~Revista() {}

// Getters
int Revista::getNumeroClasificacion() const { return Material::getNumeroClasificacion(); }
int Revista::getNumeroCatalogo() const { return Material::getNumeroCatalogo(); }
string Revista::getTitulo() const { return Material::getTitulo(); }
string Revista::getAutor() const { return Material::getAutor(); }
string Revista::getPalabrasClave() const { return Material::getPalabrasClave(); }
string Revista::getEstadoMaterial() const { return Material::getEstadoMaterial(); }
bool Revista::getHabilitadoParaPrestamo() const{ return Material::getHabilitadoParaPrestamo(); }
int Revista::getNumero() const { return numero; }
int Revista::getVolumen() const { return volumen; }
string Revista::getUbicacionFisica() const { return ubicacionFisica; }
string Revista::getTipoMaterial() const { return "Revista"; }

// Setters
void Revista::setNumeroClasificacion(int numeroClasificacion) { Material::setNumeroClasificacion(numeroClasificacion); }
void Revista::setNumeroCatalogo(int numeroCatalogo) { Material::setNumeroCatalogo(numeroCatalogo); }
void Revista::setTitulo(string titulo) { Material::setTitulo(titulo); }
void Revista::setAutor(string autor) { Material::setAutor(autor); }
void Revista::setPalabrasClave(string palabrasClave) { Material::setPalabrasClave(palabrasClave); }
void Revista::setEstadoMaterial(string estadoMaterial) { Material::setEstadoMaterial(estadoMaterial); }
void Revista::setHabilitadoParaPrestamo(bool habilitadoParaPrestamo){ Material::setHabilitadoParaPrestamo(habilitadoParaPrestamo); }
void Revista::setNumero(int numero) { this->numero = numero; }
void Revista::setVolumen(int volumen) { this->volumen = volumen; }
void Revista::setUbicacionFisica(string ubicacionFisica) { this->ubicacionFisica = ubicacionFisica; }

// ToString
string Revista::mostrar() const {
    stringstream s;
    s << "--------- INFORMACION DE LA REVISTA ---------" << endl
      << "Tipo de material: " << getTipoMaterial() << endl
      << "Numero de clasificacion: " << Material::getNumeroClasificacion() << endl
      << "Numero de catalogo: " << Material::getNumeroCatalogo() << endl
      << "Titulo: " << Material::getTitulo() << endl
      << "Autor: " << Material::getAutor() << endl
      << "Palabras clave: " << Material::getPalabrasClave() << endl
      << "Estado del material: " << Material::getEstadoMaterial() << endl;
    s << "Habilitado para Prestamo (1 = Habilitado, 0 = Deshabilitado): " << Material::getHabilitadoParaPrestamo() << endl;
    s << "Ubicacion Fisica: : " << ubicacionFisica << endl;
    s << "Numero: " << numero << endl;
    s << "Volumen: : " << volumen << endl;
    return s.str();
}

// ToString especifico
string Revista::stringEspecifico() {
    stringstream ss;
    ss << getTipoMaterial() << ";"
       << getNumeroClasificacion() << ";"
       << getNumeroCatalogo() << ";"
       << getTitulo() << ";"
       << getAutor() << ";"
       << getPalabrasClave() << ";"
       << getEstadoMaterial() << ";"
       << (getHabilitadoParaPrestamo() ? "1" : "0") << ";"
       << ubicacionFisica << ";"
       << numero << ";"
       << volumen << "\n";
    return ss.str();
}