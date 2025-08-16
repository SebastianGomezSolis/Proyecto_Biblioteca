//
// Created by sebas on 15/8/2025.
//

#ifndef MATERIALDIGITAL_H
#define MATERIALDIGITAL_H

#include "Material.h"
#include "../Utilities.h"

class materialDigital : public Material {
private:
    string tipo;
public:
    materialDigital(int nC, int nCat, string t, string a, string pC, string eM, bool hpp, string tipo);
    virtual ~materialDigital();
    virtual int getNumeroClasificacion() const;
    void setNumeroClasificacion(int numeroClasificacion);
    virtual int getNumeroCatalogo() const;
    void setNumeroCatalogo(int numeroCatalogo);
    virtual string getTitulo() const;
    void setTitulo(string titulo);
    virtual string getAutor() const;
    void setAutor(string autor);
    virtual string getPalabrasClave() const;
    void setPalabrasClave(string palabrasClave);
    virtual string getEstadoMaterial() const;
    void setEstadoMaterial(string estadoMaterial);
    virtual bool getHabilitadoParaPrestamo() const;
    void setHabilitadoParaPrestamo(bool habilitadoParaPrestamo);
    virtual string getTipo() const;
    string getTipoMaterial() const;
    virtual string mostrar() const = 0;

};



#endif //MATERIALDIGITAL_H
