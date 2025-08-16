//
// Created by sebas on 15/8/2025.
//

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "GestorPrestamos.h"
#include "GestorMateriales.h"
#include "GestorUsuario.h"
#include "Utilities.h"
#include "Lista.h"
#include "AdministrarAlmacenamiento.h"

class Biblioteca {
private:
    Lista<Usuario>* listaUsuarios;
    Lista<Material>* listaMateriales;
    Lista<Prestamo>* listaPrestamos;

    GestorUsuario gestorUsuarios;
    GestorMateriales gestorMateriales;
    GestorPrestamos gestorPrestamos;

    AdministrarAlmacenamiento* admin;
public:
    Biblioteca();
    ~Biblioteca();
    void incluirMateriales();
    void modificarMateriales();
    void incluirUsuarios();
    void modificarUsuarios();
    void registrarPrestamos();
    void registrarDevolcuiones();
    void reporteInventarioMaterial();
    void reporteUsuarios();
    void reporteMaterialesPrestamoGeneral();
    void reporteMaterialesPrestamoEspecifico();
    void reportePrestamoPorUsuario();
    void cargarUsuarios();
    void cargarMateriales();
    void cargarPrestamos();
    void guardarPrestamos();
    void guardarUsuarios();
    void guardarMateriales();
};



#endif //BIBLIOTECA_H
