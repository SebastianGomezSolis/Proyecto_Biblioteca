//
// Created by sebas on 15/8/2025.
//

#include "Prestamo.h"

Prestamo::Prestamo(Usuario* persona, Material* material, int fechaPrestamo) : persona(persona),material(material),fechaPrestamo(fechaPrestamo) {}

Prestamo::~Prestamo() {}

int Prestamo::getFechaPrestamo() {
    return fechaPrestamo;
}

void Prestamo::setFechaPrestamo(int f) {
    fechaPrestamo = f;
}

Usuario* Prestamo::getPersona() {
    return persona;
}

void Prestamo::setPersona(Usuario* u) {
    persona = u;
}


Material* Prestamo::getMaterial() {
    return material;
}

void Prestamo::setMaterial(Material* m) {
    material = m;
}

string Prestamo::mostrar() {
    stringstream ss;
    ss << "--------- INFORMACION DEL PRESTAMO---------" << endl<<endl;
    ss << "Tiempo del Prestamo: " << getFechaPrestamo() << endl;
    if (persona != nullptr) {
        ss << persona->mostrar() << endl << endl;
    } else {
        ss << "Persona no inicializada" << endl;
    }

    if (material != nullptr) {
        ss << material->mostrar() << endl << endl;
    } else {
        ss << "Material no inicializado" << endl;
    }
    return ss.str();
}