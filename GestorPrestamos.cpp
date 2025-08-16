//
// Created by sebas on 15/8/2025.
//

#include "GestorPrestamos.h"

GestorPrestamos::GestorPrestamos(Lista<Prestamo>* prestamos, Lista<Usuario>* personas, Lista<Material>* catalogo) {
    this->prestamos = prestamos;
    this->personas = personas;
    this->catalogo = catalogo;
}

GestorPrestamos::~GestorPrestamos() {}

void GestorPrestamos::registrarPrestamo() {
    try {
        string nombre, titulo;
        int tiempo;
        Prestamo* nuevoPrestamo = nullptr;
        cout <<"\n\n------------------------------------Registrar Prestamos------------------------------------------------------"<<endl << endl;
        cout << "Lista de Usuarios Ingresados: " << endl;
        for (int i = 0; i < personas->tamanio(); i++) {
            Usuario* people = personas->obtenerUsuario(i);
            cout << i+1 << ") " << people->getNombre() << endl;
        }
        cout<<endl;
        cout << "Ingrese el nombre del Usuario Registrado: "; getline(cin, nombre);

        bool encontrado = false;

        for (int i = 0; i < personas->tamanio(); ++i) {
            Usuario* user = personas->obtenerUsuario(i);
            if (user->getNombre() == nombre) {
                encontrado = true;

                cout << "\n-------Usuario Encontrado--------\n" << endl;

                cout << "Lista de Materiales Ingresados: " << endl;
                for (int i = 0; i < catalogo->tamanio(); i++) {
                    Material* mate = catalogo->obtenerMaterial(i);
                    cout << i+1 << ") " << mate->getTitulo() << endl;
                }
                cout << endl;
                cout << "Ingrese el titulo del material que desea Adquirir: "; getline(cin, titulo);

                bool hayado = false;

                for (int i = 0; i < catalogo->tamanio(); ++i) {
                    Material* mat = catalogo->obtenerMaterial(i);
                        if (mat->getTitulo() == titulo) {
                            hayado = true;

                            if (!mat->getHabilitadoParaPrestamo()) {
                                Excepciones::NoHabilitado();
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                return;
                            }

                            cout << "\n-------Material encontrado--------\n" << endl;

                            if (mat->getTipoMaterial() == "libro" || mat->getTipoMaterial() == "Libro" ){
                                cout <<"El limite de dias para un Prestamo de un Libro es una semana (Poner el numero de dias que desea): "; cin >> tiempo ;
                                if (tiempo > 7){
                                    throw tiempo;
                                } else {
                                    mat->setHabilitadoParaPrestamo(false);
                                    nuevoPrestamo = new Prestamo(user,mat,tiempo);
                                }
                            }
                            if (mat->getTipoMaterial() == "revista" || mat->getTipoMaterial() == "Revista" ){
                                cout <<"El limite de dias para un Prestamo de una Revista son 2 dias (Poner el numero de días que desea): "; cin >> tiempo ;
                                if (tiempo > 2){
                                    throw tiempo;
                                } else {
                                    mat->setHabilitadoParaPrestamo(false);
                                    nuevoPrestamo = new Prestamo(user,mat,tiempo);
                                }
                            }
                            if (mat->getTipoMaterial() == "Video" || mat->getTipoMaterial() == "video" || mat->getTipoMaterial() == "articulo" || mat->getTipoMaterial() == "Articulo" ){
                                cout <<"El limite de dias para un Prestamo de un Video/Articulo es de 4 dias (Poner el numero de dias que desea): "; cin >> tiempo ;
                                if (tiempo > 4){
                                    throw tiempo;
                                } else {
                                    mat->setHabilitadoParaPrestamo(false);
                                    nuevoPrestamo = new Prestamo(user,mat,tiempo);
                                }
                            }
                            if (mat->getTipoMaterial() == "material digital" || mat->getTipoMaterial() == "Material Digital" || mat->getTipoMaterial() == "material Digital" || mat->getTipoMaterial() == "Material digital"){
                                cout <<"El limite de dias para un Prestamo de un Material Digital es de 5 dias (Poner el numero de dias que desea): "; cin >> tiempo ;
                                if (tiempo > 5){
                                    throw tiempo;
                                } else {
                                    mat->setHabilitadoParaPrestamo(false);
                                    nuevoPrestamo = new Prestamo(user,mat,tiempo);
                                }
                            }

                            if (nuevoPrestamo != nullptr) {
                                prestamos->insertarFinal(nuevoPrestamo);
                                cout << "\nPrestamo creado y agregado exitosamente." << endl;
                            } else {
                                Excepciones::ErrorPrestamo();
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                return;
                            }
                        }
                    }

                if (!hayado) {
                    Excepciones::handleUnknownTitleType(titulo);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    return;
                }
            }
        }

        if (!encontrado) {
            Excepciones::handleUnknownTitleName(nombre);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
    } catch (const exception& e) {
        Excepciones::handleUnhandledException(e);
        return;
    } catch (int diasExcedidos) {
        Excepciones::NumberOfDaysExceeded(diasExcedidos);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    cout << "\n Presione Enter para volver al menu...";
    cout <<"\n------------------------------------------------------------------------------------------------";
    cin.get();
}

void GestorPrestamos::registrarDevolucion() {
    try {
        string nombre, titulo;
        cout << "\n\n------------------------------------Registrar Devolucion------------------------------------------------------" << endl;
        cout << "Lista de Usuarios Ingresados: " << endl;
        for (int i = 0; i < personas->tamanio(); i++) {
            Usuario* user = personas->obtenerUsuario(i);
            cout << i+1 << ")" << user->getNombre() << endl;
        }
        cout << endl;
        cout << "Ingrese el nombre del Usuario que devuelve el material: ";
        getline(cin, nombre);

        bool hayado = false;

        for (int i = 0; i < personas->tamanio(); ++i) {
            Usuario* user = personas->obtenerUsuario(i);
            if (user->getNombre() == nombre) {
                hayado = true;

                cout << "\n-------Usuario Encontrado--------\n" << endl << endl;

                cout << "Lista de Materiales Ingresados: " << endl;
                for (int i = 0; i < catalogo->tamanio(); i++) {
                    Material* mate = catalogo->obtenerMaterial(i);
                    cout << i+1 << ")" << mate->getTitulo() << endl;
                }
                cout << endl << endl;
                cout << "Ingrese el titulo del Material que esta devolviendo: ";
                getline(cin, titulo);

                bool buscado = false;

                for (int i = 0; i < catalogo->tamanio(); ++i) {
                    Material* mat = catalogo->obtenerMaterial(i);
                    if (mat->getTitulo() == titulo) {
                        buscado = true;

                        cout << "\n-------Material encontrado--------\n" << endl << endl;

                        bool encontrado = false;

                        for (int i = 0; i < prestamos->tamanio(); ++i) {
                            Prestamo* prest = prestamos->obtenerPrestamo(i);

                            if (prest->getPersona()->getNombre() == nombre &&
                                prest->getMaterial()->getTitulo() == titulo && prest->getMaterial()->getHabilitadoParaPrestamo() == false) {

                                prest->getMaterial()->setHabilitadoParaPrestamo(true);
                                prestamos->eliminar(i);
                                encontrado = true;
                                cout << "\nDevolucion registrada y prestamo eliminado exitosamente.\n";
                                break;
                                }
                        }
                        if (!encontrado) {
                            Excepciones::PrestamoInactivo();
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            return;
                        }
                    }
                }
                if (!buscado) {
                    Excepciones::handleUnknownTitleType(titulo);
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    return;
                }
            }
        }
        if (!hayado) {
            Excepciones::handleUnknownTitleName(nombre);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

    } catch (const exception& e) {
        Excepciones::handleUnhandledException(e);
        return;
    }
    cout << "\n Presione Enter para volver al menu...";
    cout <<"\n------------------------------------------------------------------------------------------------";
    cin.get();
}

void GestorPrestamos::reportePrestamoPorUsuario() {
    try {
        string nombre;
        cout <<"\n\n------------------------------------Reporte Prestamos Por Usuario------------------------------------------------------"<<endl;
        cout << "Lista de Usuarios Ingresados: " << endl;
        for (int i = 0; i < personas->tamanio(); i++) {
            Usuario* user = personas->obtenerUsuario(i);
            cout << i+1 << ")" << user->getNombre() << endl;
        }
        cout<<endl;
        cout << "Ingrese el nombre del Usuario por ver Prestamos : "; getline(cin, nombre);

        bool encontrado = false;

        for (int i = 0; i < prestamos->tamanio(); ++i) {
            Prestamo* prest = prestamos->obtenerPrestamo(i);
            if (prest->getPersona()->getNombre() == nombre) {
                encontrado = true;
                cout << prest->mostrar();
            }
        }
        if (!encontrado) {
            Excepciones::handleUnknownTitleName(nombre + "Con un Prestamo Activo");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
    } catch (const exception& e) {
        Excepciones::handleUnhandledException(e);
        return;
    }

    cout << "\n Presione Enter para volver al menu...";
    cout <<"\n------------------------------------------------------------------------------------------------";
    cin.ignore();
}

void GestorPrestamos::reportePrestamoPorMaterialGeneral() {
    try {
        cout <<"\n\n------------------------------------Reporte Prestamos Por Material General-------------------------------"<<endl;

        cout << prestamos->mostrar() << endl;
    } catch (const exception& e) {
        Excepciones::handleUnhandledException(e);
        return;
    }
    cout << "\n Presione Enter para volver al menu...";
    cout <<"\n------------------------------------------------------------------------------------------------";
    cin.ignore();
}

void GestorPrestamos::reportePrestamoPorMaterialEspecifico() {
    try {
        string material;
        cout <<"\n\n------------------------------------Reporte Prestamos Por Material Especifico----------------------------------------"<<endl;
        cout << "Lista de Materiales Ingresados: " << endl;
        for (int i = 0; i < catalogo->tamanio(); i++) {
            Material* mate = catalogo->obtenerMaterial(i);
            cout << i+1 << ")" << mate->getTipoMaterial() << endl;
        }
        cout << endl;
        cout << "Ingrese el nombre del Material por ver Prestamos: "; getline(cin, material);

        bool encontrado = false;

        for (int i = 0; i < prestamos->tamanio(); ++i) {
            Prestamo* prest = prestamos->obtenerPrestamo(i);
            if (prest->getMaterial()->getTipoMaterial() == material) {
                encontrado = true;
                cout << prest->mostrar();
            }
        }
        if (!encontrado) {
            Excepciones::handleUnknownMaterialType(material + " Con un Prestamo Activo");
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
    } catch (const exception& e) {
        Excepciones::handleUnhandledException(e);
        return;
    }
    cout << "\n Presione Enter para volver al menu...";
    cout <<"\n------------------------------------------------------------------------------------------------";
    cin.ignore();
}