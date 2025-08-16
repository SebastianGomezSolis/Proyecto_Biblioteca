//
// Created by sebas on 15/8/2025.
//

#include "AdministrarAlmacenamiento.h"

void AdministrarAlmacenamiento::cargarCatalogo(Lista<Material>* &catalogo) {
    salidaCatalogo.open("catalogo.txt");
    string linea;
    if (!salidaCatalogo.is_open()) {
        cout << "No se pudo abrir el archivo catalogo.txt" << endl;
    }
    while (getline(salidaCatalogo, linea)) {
        Material *material = pasarLinea(linea);
        if (material != nullptr) {
            catalogo->insertarFinal(material);
        }
    }
    salidaCatalogo.close();
}

void AdministrarAlmacenamiento::guardarCatalogo(const Lista<Material> *catalogo) {
    entradaCatalogo.open("catalogo.txt", ios::trunc);
    if (!entradaCatalogo.is_open()) {
        cout << "No se pudo abrir el archivo catalogo.txt para escribir" << endl;
        return;
    }
    Nodo<Material> *aux = catalogo->primero1();
    while (aux != nullptr) {
        Material *mat = aux->getDato();
        if (!mat) {
            cout  << endl;
            aux = aux->getSiguiente();
            continue;
        }

            if (mat->getTipoMaterial() == "Libro") {
                Libro *libro = dynamic_cast<Libro *>(mat);
                entradaCatalogo << libro->stringEspecifico();
            } else if (mat->getTipoMaterial() == "Revista") {
                Revista *revista = dynamic_cast<Revista *>(mat);
                entradaCatalogo << revista->stringEspecifico();
            } else if (mat->getTipoMaterial() == "Articulo") {
                Articulo *articulo = dynamic_cast<Articulo *>(mat);
                entradaCatalogo << articulo->stringEspecifico();
            } else if (mat->getTipoMaterial() == "Video") {
                Video *video = dynamic_cast<Video *>(mat);
                entradaCatalogo << video->stringEspecifico();
            } else if (mat->getTipoMaterial() == "Material Digital") {
                materialDigital* materialDig = dynamic_cast<materialDigital *>(mat);
                if (materialDig->getTipo() == "Fisico" || materialDig->getTipo() == "fisico") {
                    MaterialDigitalFormatoFisico* materialForFis = dynamic_cast<MaterialDigitalFormatoFisico *>(materialDig);
                    entradaCatalogo << materialForFis->stringEspecifico();
                } else if (materialDig->getTipo() == "Digital" || materialDig->getTipo() == "digital") {
                    MaterialDigitalFormatoDigital* materialForDig = dynamic_cast<MaterialDigitalFormatoDigital *>(materialDig);
                    entradaCatalogo << materialForDig->stringEspecifico();
                }
            }
            aux = aux->getSiguiente();
    }
    entradaCatalogo.close();
}

void AdministrarAlmacenamiento::cargarUsuarios(Lista<Usuario> * &usuarios) {
    salidaUsuarios.open("usuarios.txt");
    string linea;
    if (!salidaUsuarios.is_open()) {
        cout << "No se pudo abrir el archivo usuarios.txt" << endl;
    }
    while (getline(salidaUsuarios, linea)) {
        stringstream ss(linea);
        string id, nombre, apellido1, apellido2, stringestado;
        bool estado;
        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, apellido1, ';');
        getline(ss, apellido2, ';');
        getline(ss, stringestado, ';');
        estado = (stringestado == "1");

        if (id.empty() || nombre.empty() || apellido1.empty() || stringestado.empty()) {
            continue;
        }

        Usuario* usuario = new Usuario(id, nombre, apellido1, apellido2, estado);
        if (usuario != nullptr) {
            usuarios->insertarFinal(usuario);
        } else {
            cout << "El usuario no se pudo cargar." << endl;
        }
    }
    salidaUsuarios.close();
}

void AdministrarAlmacenamiento::guardarUsuarios(const Lista<Usuario> *usuarios) {
    entradaUsuarios.open("usuarios.txt", ios::trunc);
    if (!entradaUsuarios.is_open()) {
        cout << "No se pudo abrir el archivo usuarios.txt para escribir" << endl;
        return;
    }

    Nodo<Usuario> *aux = usuarios->primero1();
    while (aux != nullptr) {
        Usuario *usuario = aux->getDato();
        string idUsuario = usuario->getId();

        if (!idUsuario.empty() && !usuario->getNombre().empty() && !usuario->getApellido1().empty()) {
            entradaUsuarios << usuario->stringEspecifico();
        }

        aux = aux->getSiguiente();
    }

    entradaUsuarios.close();
}

void AdministrarAlmacenamiento::cargarPrestamos(Lista<Prestamo>* &prestamos, Lista<Usuario>* &usuarios, Lista<Material>* &materiales) {
    salidaPrestamo.open("prestamos.txt");
    if (!salidaPrestamo.is_open()) {
        cout << "No se pudo abrir el archivo prestamos.txt" << endl;
        return;
    }

    if (salidaPrestamo.peek() == ifstream::traits_type::eof()) {
        salidaPrestamo.close();
        return;
    }

    string linea, idUsuario, idMaterial, strFecha;
    int fecha;

    while (getline(salidaPrestamo, linea)) {
        stringstream ss(linea);
        getline(ss, idUsuario, ';');
        getline(ss, idMaterial, ';');
        getline(ss, strFecha, ';');

        try {
            fecha = stoi(strFecha);
        } catch (const std::invalid_argument& e) {
            cout <<  endl;
            continue;
        } catch (const std::out_of_range& e) {
            cout << "Error: la fecha está fuera de rango: [" << strFecha << "]. Se omite este préstamo." << endl;
            continue;
        }


        Usuario* usuario = nullptr;
        for (Nodo<Usuario>* nodoU = usuarios->getInicio(); nodoU != nullptr; nodoU = nodoU->getSiguiente()) {
            if (nodoU->getDato()->getId() == idUsuario) {
                usuario = nodoU->getDato();
                break;
            }
        }


        int intmaterialid;
        try {
            intmaterialid = stoi(idMaterial);
        } catch (const std::invalid_argument& e) {
            cout << "Error: idMaterial no es un número: [" << idMaterial << "]" << endl;
            continue;
        }
        Material* material = nullptr;
        for (Nodo<Material>* nodoM = materiales->getInicio(); nodoM != nullptr; nodoM = nodoM->getSiguiente()) {
            if (nodoM->getDato()->getNumeroCatalogo() == intmaterialid) {
                material = nodoM->getDato();
                break;
            }
        }


        if (usuario != nullptr && material != nullptr) {
            Prestamo* prestamo = new Prestamo(usuario, material, fecha);
            prestamos->insertarFinal(prestamo);
        }
    }

    salidaPrestamo.close();
}

void AdministrarAlmacenamiento::guardarPrestamos(const Lista<Prestamo> *prestamos) {
    entradaPrestamo.open("prestamos.txt", ios::out);
    if (!entradaPrestamo.is_open()) {
        cout << "No se pudo abrir el archivo prestamos.txt para escribir" << endl;
        return;
    }

    Nodo<Prestamo>* actual = prestamos->getInicio();
    while (actual != nullptr) {
        Prestamo* p = actual->getDato();
        if (p != nullptr && p->getPersona() != nullptr && p->getMaterial() != nullptr) {
            entradaPrestamo << p->getPersona()->getId() << ';'
                            << p->getMaterial()->getNumeroCatalogo() << ';'
                            << p->getFechaPrestamo() << endl;
        }
        actual = actual->getSiguiente();
    }

    entradaPrestamo.close();
}

Material *AdministrarAlmacenamiento::pasarLinea(const string &linea) {
    stringstream ss(linea);
    string tipoMat, strNumeroClasificacion, strNumeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, HabilitadoParaPrestamo;
    int numeroClasificacion, numeroCatalogo;

    bool BoolHabilitadoParaPrestamo;
    getline(ss, tipoMat, ';');
    getline(ss, strNumeroClasificacion, ';');
    getline(ss, strNumeroCatalogo, ';');
    getline(ss, titulo, ';');
    getline(ss, autor, ';');
    getline(ss, palabrasClave, ';');
    getline(ss, estadoMaterial, ';');
    getline(ss, HabilitadoParaPrestamo, ';');

    try {
        BoolHabilitadoParaPrestamo = (stoi(HabilitadoParaPrestamo) == 1);
    } catch (const std::invalid_argument& e) {
        return nullptr;
    }

    try {
        numeroClasificacion = stoi(strNumeroClasificacion);
        numeroCatalogo = stoi(strNumeroCatalogo);
    } catch (const std::invalid_argument& e) {
        cout << "Error: número inválido en catalogo.txt. Cadena: ["
             << strNumeroClasificacion << "] o [" << strNumeroCatalogo << "]" << endl;
        return nullptr;
    }

    if (tipoMat == "Libro") {
        string uf;
        getline(ss, uf, ';');
        return new Libro(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, BoolHabilitadoParaPrestamo, uf);
    } else if (tipoMat == "Revista") {
        string ubicacionFisica, numero, volumen;
        int intVolumen, Intnumero;
        getline(ss, ubicacionFisica, ';');
        getline(ss, numero, ';');
        getline(ss, volumen, ';');
        Intnumero = stoi(numero);
        intVolumen = stoi(volumen);
        return new Revista(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, BoolHabilitadoParaPrestamo, Intnumero, intVolumen, ubicacionFisica);
    } else if (tipoMat == "Articulo") {
        return new Articulo(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, BoolHabilitadoParaPrestamo);
    } else if (tipoMat == "Video") {
        return new Video(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, BoolHabilitadoParaPrestamo);
    } else if (tipoMat == "Material Digital") {
        string tipo;
        getline(ss, tipo, ';');
        if (tipo == "Digital" || tipo == "digital") {
            return new MaterialDigitalFormatoDigital(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, BoolHabilitadoParaPrestamo, tipo);
        } else if (tipo == "Fisico" || tipo == "físico" || tipo == "fisico") {
            string formato;
            getline(ss, formato, ';');
            return new MaterialDigitalFormatoFisico(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, BoolHabilitadoParaPrestamo, tipo, formato);
        }
    }
    return nullptr;
}
