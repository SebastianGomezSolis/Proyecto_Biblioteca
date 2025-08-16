//
// Created by sebas on 15/8/2025.
//

#ifndef USUARIO_H
#define USUARIO_H


#include "Utilities.h"


class Usuario {
private:
    string id;
    string nombre;
    string apellido1;
    string apellido2;
    bool estado;
public:
    Usuario(string i = "-", string n = "-", string ap = "-", string ap2 = "-", bool estado = "-");
    ~Usuario();
    string getId() const;
    void setId(string id);
    string getNombre() const;
    void setNombre(string nombre);
    string getApellido1() const;
    void setApellido1(string apellido1);
    string getApellido2() const;
    void setApellido2(string apellido2);
    bool getEstado() const;
    void setEstado(bool estado);
    string mostrar();
    string stringEspecifico();
    friend std::ostream & operator<<(std::ostream &os, const Usuario &obj) {
        return os
               << "--------- INFORMACION DEL USUARIO --------- \n"
               << "Id: " << obj.getId() << "\n"
               << "Nombre: " << obj.getNombre() << "\n"
               << "Apellido1: " << obj.getApellido1() << "\n"
               << "Apellido2: " << obj.getApellido2() << "\n"
               << "Estado (1 = Activo, 0 = Inactivo): " << obj.getEstado() << "\n";
    }

};



#endif //USUARIO_H

