//
// Created by sebas on 15/8/2025.
//

#ifndef REVISTA_H
#define REVISTA_H

#include "Material.h"
#include "../Utilities.h"

class Revista : public Material {
private:
    string ubicacionFisica;
    int volumen;
    int numero;
public:
    Revista(int nC, int nCat, string t, string a, string pC, string eM, bool hpp, int n, int v, string uF);
    virtual ~Revista();
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
    string getUbicacionFisica() const;
    void setUbicacionFisica(string ubicacionFisica);
    int getVolumen() const;
    void setVolumen(int volumen);
    int getNumero() const;
    void setNumero(int numero);
    string getTipoMaterial() const;
    virtual string mostrar() const override;
    string stringEspecifico() ;

};



#endif //REVISTA_H
