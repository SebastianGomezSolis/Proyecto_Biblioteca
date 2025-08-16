//
// Created by sebas on 15/8/2025.
//

#include "MaterialDigitalFormatoFisico.h"

// Constructor con parametros
MaterialDigitalFormatoFisico::MaterialDigitalFormatoFisico(int nC, int nCat, string t, string a, string pC, string eM, bool hpp,string tipo, string fF) : materialDigital(nC, nCat, t, a, pC, eM, hpp, tipo) { formatoFisico = fF;}

// Destructor
MaterialDigitalFormatoFisico::~MaterialDigitalFormatoFisico() {}

// Getters
int MaterialDigitalFormatoFisico::getNumeroClasificacion() const { return Material::getNumeroClasificacion(); }
int MaterialDigitalFormatoFisico::getNumeroCatalogo() const { return Material::getNumeroCatalogo(); }
string MaterialDigitalFormatoFisico::getTitulo() const { return Material::getTitulo(); }
string MaterialDigitalFormatoFisico::getAutor() const { return Material::getAutor(); }
string MaterialDigitalFormatoFisico::getPalabrasClave() const { return Material::getPalabrasClave(); }
string MaterialDigitalFormatoFisico::getEstadoMaterial() const { return Material::getEstadoMaterial(); }
string MaterialDigitalFormatoFisico::getTipo() const {return materialDigital::getTipo(); }
string MaterialDigitalFormatoFisico::getFormatoFisico() { return formatoFisico; }
bool MaterialDigitalFormatoFisico::getHabilitadoParaPrestamo() const{ return Material::getHabilitadoParaPrestamo(); }
string MaterialDigitalFormatoFisico::getTipoMaterial() const { return "Material Digital"; }

// Setters
void MaterialDigitalFormatoFisico::setNumeroClasificacion(int numeroClasificacion) { Material::setNumeroClasificacion(numeroClasificacion); }
void MaterialDigitalFormatoFisico::setNumeroCatalogo(int numeroCatalogo) { Material::setNumeroCatalogo(numeroCatalogo); }
void MaterialDigitalFormatoFisico::setTitulo(string titulo) { Material::setTitulo(titulo); }
void MaterialDigitalFormatoFisico::setAutor(string autor) { Material::setAutor(autor); }
void MaterialDigitalFormatoFisico::setPalabrasClave(string palabrasClave) { Material::setPalabrasClave(palabrasClave); }
void MaterialDigitalFormatoFisico::setEstadoMaterial(string estadoMaterial) { Material::setEstadoMaterial(estadoMaterial); }
void MaterialDigitalFormatoFisico::setFormatoFIsico(string formatoFIsico) { this->formatoFisico = formatoFIsico; }
void MaterialDigitalFormatoFisico::setHabilitadoParaPrestamo(bool habilitadoParaPrestamo) { Material::setHabilitadoParaPrestamo(habilitadoParaPrestamo); }

// ToString
string MaterialDigitalFormatoFisico::mostrar() const {
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
    s << "FormatoFisico: " << formatoFisico << endl;
    return s.str();
}

// ToString especifico
string MaterialDigitalFormatoFisico::stringEspecifico() {
    stringstream ss;
    ss << getTipoMaterial() << ";"
       << getNumeroClasificacion() << ";"
       << getNumeroCatalogo() << ";"
       << getTitulo() << ";"
       << getAutor() << ";"
       << getPalabrasClave() << ";"
       << getEstadoMaterial() << ";"
       << (getHabilitadoParaPrestamo() ? "1" : "0") << ";"
       << getTipo() << ";"
       << formatoFisico << "\n";
    return ss.str();
}