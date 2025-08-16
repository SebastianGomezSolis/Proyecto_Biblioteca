//
// Created by sebas on 15/8/2025.
//

#ifndef MATERIALDIGITALFORMATOFISICO_H
#define MATERIALDIGITALFORMATOFISICO_H

#include "../Utilities.h"
#include "materialDigital.h"

class MaterialDigitalFormatoFisico : public materialDigital {
private:
    string formatoFisico;
public:
    MaterialDigitalFormatoFisico(int nC, int nCat, string t, string a, string pC, string eM, bool hpp,string tipo, string fF);
    ~MaterialDigitalFormatoFisico();
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
    virtual string getTipo() const ;
    string getFormatoFisico();
    void setFormatoFIsico(string formatoFIsico);
    string getTipoMaterial() const;
    virtual string mostrar() const override;
    string stringEspecifico() ;

};



#endif //MATERIALFORMATOFISICO_H
