//
// Created by sebas on 15/8/2025.
//

#include "GestorUsuario.h"

GestorUsuario::GestorUsuario(Lista<Usuario>* personas) {
    this->personas = personas;
}

GestorUsuario::~GestorUsuario() {
}

void GestorUsuario::incluirUsuario() {
    try {
        string id, nombre, apellido1, apellido2;
        cout <<"\n\n------------------------------------Incluir datos de usuarios------------------------------------------------------"<<endl;
        cout << "Ingrese el id del usuario: "; getline(cin, id);
        cout << "Ingrese el nombre del usuario: "; getline(cin, nombre);
        cout << "Ingrese el primer apallido del usuario: "; getline(cin, apellido1);
        cout << "Ingrese el segundo apellido del usuario: "; getline(cin, apellido2);

        Usuario* persona = nullptr;
        try {
            persona = new Usuario(id, nombre, apellido1, apellido2, true);
        } catch (const std::bad_alloc& e) {
            cout << "Error al crear el objeto Usuario: " << e.what() << endl;
            return;
        }

        try {
            personas->insertarFinal(persona);
        } catch (const std::bad_alloc& e) {
            cout << "Error al insertar el objeto Usuario en la lista: " << e.what() << endl;
            delete persona;
            return;
        }
    } catch (const exception& e) {
        Excepciones::handleUnhandledException(e);
        return;
    }

    cout << "Usuario incluido correctamente." << endl;
    cout << "\nPresione Enter para volver al menu...";
    cout << "\n------------------------------------------------------------------------------------------------";
    cin.ignore();
}

void GestorUsuario::ModificarUsuario() {
    try {
        string id;
        cout <<"\n\n------------------------------------Modificar datos de usuarios------------------------------------------------------"<<endl << endl;
        cout << "Lista de Usuarios Ingresados: " << endl;
        for (int i = 0; i < personas->tamanio(); i++) {
            Usuario* user = personas->obtenerUsuario(i);
            cout << i+1 << ") " << user->getId() << endl;
        }

        cout<<endl;
        cout << "Ingrese el id del usuario a modificar: "; getline(cin, id);
        bool encontrado = false;
        for (int i = 0; i < personas->tamanio(); i++) {
            Usuario* per = personas->obtenerUsuario(i);
            if (per->getId() == id) {
                encontrado = true;
                cout << "\n-------Usuario encontrado--------\n";
                string nuevoId, nuevoNombre, nuevoApellido1, nuevoApellido2;
                bool estado;
                cout << "Ingrese el nuevo id del usuario: "; getline(cin, nuevoId);
                cout << "Ingrese el nuevo nombre del usuario: "; getline(cin, nuevoNombre);
                cout << "Ingrese el nuevo primer apellido del usuario: "; getline(cin, nuevoApellido1);
                cout << "Ingrese el nuevo segundo apellido del usuario: "; getline(cin, nuevoApellido2);
                cout << "Ingrese el nuevo estado (1 = Activo, 0 = Inactivo): "; cin >> estado;
                try {
                    per->setId(nuevoId);
                    per->setNombre(nuevoNombre);
                    per->setApellido1(nuevoApellido1);
                    per->setApellido2(nuevoApellido2);
                    per->setEstado(estado);
                    cout << "\nUsuario modificado correctamente.\n";
                } catch (const std::bad_alloc& e) {
                    cout << "Error al modificar al usuario: " << e.what() << endl;
                    return;
                }
            }
        }
        if (!encontrado) {
            Excepciones::handleUnknownIDType(id);
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
    cin.get();
}

void GestorUsuario::reportarUsuario() {
    cout <<"\n\n------------------------------------Reporte de usuarios------------------------------------------------------"<<endl;
    cout << personas->mostrar();
    cout << "\n Presione Enter para volver al menu...";
    cout <<"\n------------------------------------------------------------------------------------------------";
    cin.get();
}