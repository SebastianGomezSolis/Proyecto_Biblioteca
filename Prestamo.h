//
// Created by sebas on 15/8/2025.
//

#ifndef PRESTAMO_H
#define PRESTAMO_H


#include "Utilities.h"
#include "Usuario.h"
#include "Materiales/Material.h"


class Prestamo {
private:
    Usuario* persona;
    Material* material;
    int fechaPrestamo;
public:
    Prestamo(Usuario* persona = nullptr, Material* material = nullptr, int fechaPrestamo = 0);
    ~Prestamo();
    int getFechaPrestamo();
    void setFechaPrestamo(int f);
    Usuario* getPersona();
    void setPersona(Usuario* u);
    Material* getMaterial();
    void setMaterial(Material* m);
    string mostrar();

    friend ostream& operator<<(ostream& os, const Prestamo& prestamo) {
        os << "--------- INFORMACION DEL PRESTAMO ---------" << endl << endl;
        os << "Tiempo del Prestamo: " << prestamo.fechaPrestamo << endl << endl;
        os << *(prestamo.persona) << endl;
        os << prestamo.material->mostrar() << endl;
        return os;
    }
};



#endif //PRESTAMO_H
