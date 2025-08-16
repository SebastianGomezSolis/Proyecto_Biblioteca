//
// Created by sebas on 15/8/2025.
//

#ifndef GESTORUSUARIO_H
#define GESTORUSUARIO_H


#include "Utilities.h"
#include "Usuario.h"
#include "Lista.h"


class GestorUsuario {
private:
    Lista<Usuario>* personas;
public:
    GestorUsuario(Lista<Usuario>*);
    ~GestorUsuario();
    void incluirUsuario();
    void ModificarUsuario();
    void reportarUsuario();
};



#endif //GESTORUSUARIO_H
