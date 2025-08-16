//
// Created by sebas on 15/8/2025.
//

#ifndef GESTORPRESTAMOS_H
#define GESTORPRESTAMOS_H


#include "Lista.h"
#include "Utilities.h"
#include "Prestamo.h"
#include "Materiales/Material.h"
#include "Usuario.h"


class GestorPrestamos {
private:
    Lista<Prestamo>* prestamos;
    Lista<Usuario>* personas;
    Lista<Material>* catalogo;
public:
    GestorPrestamos(Lista<Prestamo>*, Lista<Usuario>*, Lista<Material>*);
    ~GestorPrestamos();
    void registrarPrestamo();
    void registrarDevolucion();
    void reportePrestamoPorUsuario();
    void reportePrestamoPorMaterialGeneral();
    void reportePrestamoPorMaterialEspecifico();

};



#endif //GESTORPRESTAMOS_H
