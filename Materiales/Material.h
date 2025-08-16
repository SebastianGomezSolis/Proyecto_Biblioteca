//
// Created by sebas on 15/8/2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H

#include "../Utilities.h"

class Material {
private:
    int numeroClasificacion;
    int numeroCatalogo;
    string titulo;
    string autor;
    string palabrasClave;
    string estadoMaterial;
    bool HabilitadoParaPrestamo;
public:
    Material(int nC = 0, int nCat = 0, string t = "-", string a = "-", string pC = "-", string eM = "-", bool hpp= true);
    virtual ~Material();
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
    virtual string getTipoMaterial() const = 0;
    virtual string mostrar() const = 0;
    friend std::ostream & operator<<(std::ostream &os, const Material &obj);

};

#endif //MATERIAL_H
