//
// Created by sebas on 15/8/2025.
//

#ifndef LISTA_H
#define LISTA_H

#include "Materiales/Material.h"
#include "Nodo.h"
#include "Utilities.h"
#include "Prestamo.h"


template<class T>
class Lista {
private:
    Nodo<T>* primero;
public:
    Lista();
    ~Lista();
    Nodo<T>* primero1() const;
    void insertarInicio(T* dato);
    void insertarFinal(T* dato);
    Material* obtenerMaterial(int posicion);
    Usuario* obtenerUsuario(int posicion);
    Prestamo* obtenerPrestamo(int posicion);
    int tamanio();
    bool esVacia();
    string mostrar();
    Nodo<T>* getInicio() const { return primero; }
    void eliminar(int posicion);
    friend std::ostream & operator<<(std::ostream &os, const Lista &obj) {
        Nodo<T> *aux = obj.primero;
        if (aux == nullptr) {
            os << "Lista vacia!" << endl;
        } else {
            aux = aux->getSiguiente();
            do {
                os << *aux->getDato() << endl;
                aux = aux->getSiguiente();
            } while (aux != nullptr);
        }
        return os;
    }

};

template<class T>
Lista<T>::Lista() {
    primero = nullptr;
}


template<class T>
Lista<T>::~Lista() {
    Nodo<T>* temp;
    while (primero != nullptr) {
        temp = primero;
        primero = primero->getSiguiente();
        delete temp->getDato();
        delete temp;
    }
}

template<class T>
Nodo<T> * Lista<T>::primero1() const {
    return primero;
}

template<class T>
void Lista<T>::insertarInicio(T* dato) {
    Nodo<T>* nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    if (primero == nullptr) {
        primero = nuevo;
        nuevo->setSiguiente(nullptr);
    } else {
        nuevo->setSiguiente(primero);
        primero = nuevo;
    }
}

template<class T>
void Lista<T>::insertarFinal(T* dato) {
    Nodo<T>* nuevo = new Nodo<T>;
    nuevo->setDato(dato);
    if (primero == nullptr) {
        primero = nuevo;
        nuevo->setSiguiente(nullptr);
    } else {
        Nodo<T>* actual = primero;
        while (actual->getSiguiente() != nullptr) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
        nuevo->setSiguiente(nullptr);
    }
}

template<class T>
string Lista<T>::mostrar() {
    stringstream ss;
    Nodo<T>* actual = primero;

    if (actual == nullptr) {
        ss << "La lista esta vacia." << endl;
    }

    while (actual != nullptr) {
        if (actual->getDato() != nullptr) {
            ss << *(actual->getDato()) << endl;
        } else {
            ss << "Nodo con dato nulo." << endl;
        }
        actual = actual->getSiguiente();
    }
    return ss.str();
}

template <class T>
Material* Lista<T>::obtenerMaterial(int posicion) {
    if (posicion < 0 || posicion > tamanio()) {
        throw std::out_of_range("Posición fuera de rango");
    }

    Nodo<T>* actual = primero;
    int indice = 0;

    while (actual != nullptr) {
        if (indice == posicion) {
            return actual->getDato();
        }
        actual = actual-> getSiguiente();
        indice++;
    }

    throw std::runtime_error("Error al obtener el elemento");
}

template <class T>
Usuario* Lista<T>::obtenerUsuario(int posicion) {
    if (posicion < 0 || posicion > tamanio()) {
        throw std::out_of_range("Posición fuera de rango");
    }

    Nodo<T>* actual = primero;
    int indice = 0;

    while (actual != nullptr) {
        if (indice == posicion) {
            return actual->getDato();
        }
        actual = actual-> getSiguiente();
        indice++;
    }

    throw std::runtime_error("Error al obtener el elemento");
}

template <class T>
Prestamo* Lista<T>::obtenerPrestamo(int posicion) {
    if (posicion < 0 || posicion > tamanio()) {
        throw std::out_of_range("Posición fuera de rango");
    }

    Nodo<T>* actual = primero;
    int indice = 0;

    while (actual != nullptr) {
        if (indice == posicion) {
            return actual->getDato();
        }
        actual = actual-> getSiguiente();
        indice++;
    }

    throw std::runtime_error("Error al obtener el elemento");
}

template<typename T>
int Lista<T>::tamanio() {
    Nodo<T>* actual = primero;
    int contador = 0;

    // Recorremos toda la lista
    while (actual != nullptr) {
        contador++;
        actual = actual->getSiguiente();
    }

    return contador;
}

template<class T>
bool Lista<T>::esVacia() {
    return primero == nullptr;
}

template <class T>
void Lista<T>::eliminar(int posicion) {
    if (posicion < 0 || posicion >= tamanio()) {
        throw std::out_of_range("Posición fuera de rango");
    }

    Nodo<T>* actual = primero;
    Nodo<T>* anterior = nullptr;

    for (int i = 0; i < posicion; ++i) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    if (anterior == nullptr) {
        primero = actual->getSiguiente();
    } else {
        anterior->setSiguiente(actual->getSiguiente());
    }

    delete actual;
}


#endif //LISTA_H
