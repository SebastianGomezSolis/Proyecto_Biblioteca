//
// Created by sebas on 15/8/2025.
//

#include "Material.h"

#include "Material.h"

// Constructor con parametros
Material::Material(int nC, int nCat, string t, string a, string pC, string eM, bool hpp) : numeroClasificacion(nC), numeroCatalogo(nCat), titulo(t), autor(a), palabrasClave(pC), estadoMaterial(eM), HabilitadoParaPrestamo(hpp) {}

// Destructor
Material::~Material() {}

// Getters
int Material::getNumeroClasificacion() const { return numeroClasificacion; }
int Material::getNumeroCatalogo() const { return numeroCatalogo; }
string Material::getTitulo() const { return titulo; }
string Material::getAutor() const { return autor; }
string Material::getPalabrasClave() const { return palabrasClave; }
string Material::getEstadoMaterial() const { return estadoMaterial; }
bool Material::getHabilitadoParaPrestamo() const { return HabilitadoParaPrestamo; }

// Setters
void Material::setNumeroClasificacion(int numeroClasificacion) { this->numeroClasificacion = numeroClasificacion; }
void Material::setNumeroCatalogo(int numeroCatalogo) { this->numeroCatalogo = numeroCatalogo; }
void Material::setTitulo(string titulo) { this->titulo = titulo; }
void Material::setAutor(string autor) { this->autor = autor; }
void Material::setPalabrasClave(string palabrasClave) { this->palabrasClave = palabrasClave; }
void Material::setEstadoMaterial(string estadoMaterial) { this->estadoMaterial = estadoMaterial; }
void Material::setHabilitadoParaPrestamo(bool habilitadoParaPrestamo){ this->HabilitadoParaPrestamo = habilitadoParaPrestamo; }

// Sobrecarga del operador de salida
std::ostream & operator<<(std::ostream &os, const Material& obj) {
    os << obj.mostrar();
    return os;
}
