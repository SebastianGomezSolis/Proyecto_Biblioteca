//
// Created by sebas on 15/8/2025.
//

#ifndef LIBRO_H
#define LIBRO_H

#include "../Utilities.h"
#include "Material.h"

class Libro : public Material {
private:
    string ubicacionFisica;
public:
    Libro(int nC, int nCat, string t, string a, string pC, string eM, bool hpp, string uF);
    virtual ~Libro();
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
    string getUbicacionFisica();
    void setUbicacionFisica(string ubicacionFisica);
    string getTipoMaterial() const;
    virtual string mostrar() const override;
    string stringEspecifico();
};



#endif //LIBRO_H
