//
// Created by sebas on 15/8/2025.
//

#include "Biblioteca.h"

// Constructor
Biblioteca::Biblioteca() : listaUsuarios(new Lista<Usuario>()), listaMateriales(new Lista<Material>()), listaPrestamos(new Lista<Prestamo>()), gestorUsuarios(listaUsuarios), gestorMateriales(listaMateriales), gestorPrestamos(listaPrestamos, listaUsuarios, listaMateriales), admin(new AdministrarAlmacenamiento()) {}

// Destructor
Biblioteca::~Biblioteca() {
    delete listaUsuarios;
    delete listaMateriales;
    delete listaPrestamos;
    delete admin;
}

void Biblioteca::incluirMateriales() {
    gestorMateriales.IncluirMaterial();
}

void Biblioteca::modificarMateriales() {
    gestorMateriales.ModificarMaterial();
}

void Biblioteca::incluirUsuarios() {
    gestorUsuarios.incluirUsuario();
}

void Biblioteca::modificarUsuarios() {
    gestorUsuarios.ModificarUsuario();
}

void Biblioteca::registrarPrestamos() {
    gestorPrestamos.registrarPrestamo();
}

void Biblioteca::registrarDevolcuiones() {
    gestorPrestamos.registrarDevolucion();
}

void Biblioteca::reporteInventarioMaterial() {
    gestorMateriales.ReporteMaterial();
}

void Biblioteca::reporteUsuarios() {
    gestorUsuarios.reportarUsuario();
}

void Biblioteca::reporteMaterialesPrestamoGeneral() {
    gestorPrestamos.reportePrestamoPorMaterialGeneral();
}

void Biblioteca::reporteMaterialesPrestamoEspecifico() {
    gestorPrestamos.reportePrestamoPorMaterialEspecifico();
}

void Biblioteca::reportePrestamoPorUsuario() {
    gestorPrestamos.reportePrestamoPorUsuario();
}

void Biblioteca::cargarMateriales() {
    admin->cargarCatalogo(listaMateriales);
}
void Biblioteca::cargarPrestamos() {
    admin->cargarPrestamos(listaPrestamos,listaUsuarios,listaMateriales);
}
void Biblioteca::cargarUsuarios() {
    admin->cargarUsuarios(listaUsuarios);
}

void Biblioteca::guardarMateriales() {
    admin->guardarCatalogo(listaMateriales);
}
void Biblioteca::guardarPrestamos() {
    admin->guardarPrestamos(listaPrestamos);
}
void Biblioteca::guardarUsuarios() {
    admin->guardarUsuarios(listaUsuarios);
}