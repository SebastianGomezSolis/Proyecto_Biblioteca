//
// Created by sebas on 15/8/2025.
//

#ifndef ADMINISTRADORALMACENAMIENTO_H
#define ADMINISTRADORALMACENAMIENTO_H

#include "Materiales/Material.h"
#include "Usuario.h"
#include "Materiales/Articulo.h"
#include "Materiales/Revista.h"
#include "Materiales/Libro.h"
#include "Materiales/Video.h"
#include "Materiales/materialDigital.h"
#include "Lista.h"
#include "Materiales/MaterialDigitalFormatoDigital.h"
#include "Materiales/MaterialDigitalFormatoFisico.h"
#include "Prestamo.h"
#include "Utilities.h"


class AdministrarAlmacenamiento {
private:
    ifstream salidaUsuarios;
    ifstream salidaCatalogo;
    ifstream salidaPrestamo;
    ofstream entradaCatalogo;
    ofstream entradaUsuarios;
    ofstream entradaPrestamo;
public:
    void cargarCatalogo(Lista<Material>* &catalogo);
    void cargarUsuarios(Lista<Usuario>* &usuarios);
    void cargarPrestamos(Lista<Prestamo>* &prestamos,Lista<Usuario>* &usuarios,Lista<Material>* &catalogo);
    void guardarCatalogo(const Lista<Material>* catalogo);
    void guardarUsuarios(const Lista<Usuario>* usuarios);
    void guardarPrestamos(const Lista<Prestamo>* prestamos);
    Material* pasarLinea(const string& linea);
    string serializarPrestamo();

};



#endif //ADMINISTRARALMACENAMIENTO_H
