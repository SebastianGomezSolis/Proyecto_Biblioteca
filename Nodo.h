//
// Created by sebas on 15/8/2025.
//

#ifndef NODO_H
#define NODO_H

#include "Utilities.h"
#include "Usuario.h"

template<class T>
class Nodo {
private:
    T* dato;
    Nodo<T>* siguiente;
public:
    Nodo() {
        dato = nullptr;
        siguiente = nullptr;
    }
    ~Nodo() {}

    T* getDato() {
        return dato;
    }
    void setDato(T* dato) {
        this->dato = dato;
    }
    Nodo<T>* getSiguiente() {
        return siguiente;
    }
    void setSiguiente(Nodo<T>* siguiente) {
        this->siguiente = siguiente;
    }
};



#endif // NODO_H
