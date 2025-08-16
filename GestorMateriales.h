//
// Created by sebas on 15/8/2025.
//

#ifndef GESTORMATERIALES_H
#define GESTORMATERIALES_H

#include "Lista.h"
#include "Utilities.h"
#include "Materiales/Material.h"
#include "Materiales/Libro.h"
#include "Materiales/Revista.h"
#include "Materiales/Articulo.h"
#include "Materiales/Video.h"
#include "Materiales/materialDigital.h"
#include "Materiales/MaterialDigitalFormatoFisico.h"
#include "Materiales/MaterialDigitalFormatoDigital.h"

class GestorMateriales {
private:
    Lista<Material>* catalogo;
public:
    GestorMateriales(Lista<Material>* catalogo);
    ~GestorMateriales();
    void IncluirMaterial();
    void ModificarMaterial();
    void ReporteMaterial();
};



#endif //GESTORMATERIALES_H
