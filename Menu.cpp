//
// Created by sebas on 15/8/2025.
//

#include "Menu.h"

Menu::Menu() : library(new Biblioteca()) {}

Menu::~Menu() { delete library; }

void Menu::mostrarMenu() {
 int opcion;
    library->cargarUsuarios();
    library->cargarMateriales();
    library->cargarPrestamos();
    do {
        cout<<"\n\n------------------------Bienvenidos Al Menu Principal De La Biblioteca-------------------------"<<endl;
        cout<<"1. Inclusion de datos de materiales (libros, revistas, articulos, videos, material digital)"<<endl;
        cout<<"2. Modificacion de datos de materiales"<<endl;
        cout<<"3. Inclusion de usuarios"<<endl;
        cout<<"4. Modificacion de datos de usuarios"<<endl;
        cout<<"5. Registro de solicitudes de prestamo y devoluciones"<<endl;
        cout<<"6. Reporte de inventario de materiales"<<endl;
        cout<<"7. Reporte de usuarios"<<endl;
        cout<<"8. Reporte de materiales en prestamo (general y por tipo de material)"<<endl;
        cout<<"9. Reporte de prestamos por usuario"<<endl;
        cout << "0. Salir" << endl;
        cout << "------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Escoga el numero de su Interes: ";

        string entrada;
        getline(cin, entrada);

        try {
            opcion = stoi(entrada);
        } catch (...) {
            Excepciones::OpcionInvalidaMenu();
            opcion = -1;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        try {
            switch(opcion) {
            case 1:
                library->incluirMateriales();
                break;
            case 2:
                library->modificarMateriales();
                break;
            case 3:
                library->incluirUsuarios();
                break;
            case 4:
                library->modificarUsuarios();
                break;
            case 5: {
                int opinion;
                cout <<"\n\n---------------------Registrar solicitudes de Prestamos y Devoluciones----------------------------"<<endl;
                cout << "1. Registrar Prestamo" << endl;
                cout << "2. Registrar Devoluciones"<<endl;
                cout<<"\n------------------------------------------------------------------------------------------------"<<endl;
                cout<<"Digite su opcion:";

                string subopcion;
                getline(cin, subopcion);
                try {
                    opinion = stoi(subopcion);
                } catch (...) {
                    Excepciones::OpcionInvalidaMenu();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                switch(opinion) {
                case 1:
                    library->registrarPrestamos();
                    break;
                case 2:
                    library->registrarDevolcuiones();
                    break;
                default:
                    Excepciones::OpcionInvalidaMenu();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                break;
            }
            case 6:
                library->reporteInventarioMaterial();
                break;
            case 7:
                library->reporteUsuarios();
                break;
            case 8: {
                int seleccion;
                cout <<"\n\n---------------------Reporte de materiales en prestamo (general y por tipo de material)----------------------------"<<endl;
                cout << "1. Reporte General" << endl;
                cout << "2. Reporte Por Tipo De Material"<<endl;
                cout<<"\n------------------------------------------------------------------------------------------------"<<endl;
                cout<<"Digite su opcion:";

                string subentrada;
                getline(cin, subentrada);
                try {
                    seleccion = stoi(subentrada);
                } catch (...) {
                    Excepciones::OpcionInvalidaMenu();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                switch(seleccion) {
                case 1:
                    library->reporteMaterialesPrestamoGeneral();
                    break;
                case 2:
                    library->reporteMaterialesPrestamoEspecifico();
                    break;
                default:
                    Excepciones::OpcionInvalidaMenu();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                break;
            }
            case 9:
                library->reportePrestamoPorUsuario();
                break;
            case 0:
                library->guardarUsuarios();
                library->guardarMateriales();
                library->guardarPrestamos();
                cout << "Muchas Gracias Por su Visita, Vuelva Pronto" << endl;
                cin.clear();
                cin.sync();
                break;

            default:
                Excepciones::OpcionInvalidaMenu();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        } catch (const std::exception& e) {
            Excepciones::handleUnhandledException(e);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while(opcion != 0);
}
