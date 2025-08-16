//
// Created by sebas on 15/8/2025.
//

#include "GestorMateriales.h"

GestorMateriales::GestorMateriales(Lista<Material>* catalogo) { this->catalogo = catalogo; }

GestorMateriales::~GestorMateriales() {}

void GestorMateriales::IncluirMaterial() {
    try {
        string titulo, autor, palabrasClave, estadoMaterial, material, ubicacionFisica, tipo, formato;
        int volumen, numero, numeroClasificacion, numeroCatalogo;
        cout << "\n\n------------------------------------Incluir datos de materiales------------------------------------------------------" << endl;
        cout << "Datos: " << endl;
        cout << "Tipo material (libro/revista/articulo/video/material digital): "; getline(cin, material);
        cout << "Titulo: "; getline(cin, titulo);
        cout << "Autor: "; getline(cin, autor);
        cout << "Palabras Claves: "; getline(cin, palabrasClave);
        cout << "Estado Material (Excelente, Regular, Malo): "; getline(cin, estadoMaterial);
        cout << "Numero Catalogo: "; cin >> numeroCatalogo;
        if (cin.fail()) throw invalid_argument("Numero Invalido para el Catalogo del1 Material");
        cout << "Numero de Clasificacion: "; cin >> numeroClasificacion;
         if (cin.fail()) throw invalid_argument("Numero Invalido para la Clasificacion del Material");

        Material* nuevoMaterial = nullptr;

        if (material == "libro" || material == "Libro") {
            cin.ignore();
            cout << "Ubicacion Fisica: "; getline(cin, ubicacionFisica);
            nuevoMaterial = new Libro(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, true, ubicacionFisica);
        } else if (material == "revista" || material == "Revista") {
            cout << "Numero de la revista: "; cin >> numero;
            if (cin.fail()) throw invalid_argument("Numero invalido para la revista");
            cout << "Volumen: ";cin >> volumen;
            if (cin.fail()) throw invalid_argument("Volumen inválido para la revista");
            cin.ignore();
            cout << "Ubicacion Fisica: "; getline(cin, ubicacionFisica);
            nuevoMaterial = new Revista(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, true, numero, volumen, ubicacionFisica);
        } else if (material == "articulo" || material == "Articulo") {
            nuevoMaterial = new Articulo(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, true);
        } else if (material == "video" || material == "Video") {
            nuevoMaterial = new Video(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, true);
        } else if (material == "material digital" || material == "Material Digital" || material == "material Digital" || material == "Material digital") {
            cin.ignore();
            cout << "Tipo (Digital o Fisico): "; getline(cin, tipo);
            if (tipo == "Digital" || tipo == "digital") {
                nuevoMaterial = new MaterialDigitalFormatoDigital(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, true, tipo);
            } else if (tipo == "Fisico" || tipo == "físico" || tipo == "fisico") {
                cout << "Formato((CD, DVD, BluRay): "; getline(cin, formato);
                nuevoMaterial = new MaterialDigitalFormatoFisico(numeroClasificacion, numeroCatalogo, titulo, autor, palabrasClave, estadoMaterial, true, tipo, formato);
            }
        } else {
            Excepciones::handleUnknownMaterialType(material);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        if (nuevoMaterial != nullptr) {
            catalogo->insertarFinal(nuevoMaterial);
            cout << "\nMaterial creado y agregado exitosamente." << endl;
        }
    } catch (const invalid_argument& ia) {
        Excepciones::handleInvalidInput(ia.what());
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    } catch (const exception& e) {
        Excepciones::handleUnhandledException(e);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return;
    }
    cout << "\n Presione Enter para volver al menu...";
    cout <<"\n------------------------------------------------------------------------------------------------";
    cin.get();
}


void GestorMateriales::ModificarMaterial() {
    try {
        string titulo;
        cout <<"\n\n--------------------------------Modificar datos de materiales---------------------------------------------------"<<endl << endl;
        cout << "Lista de Materiales Ingresados: " << endl;
        for (int i = 0; i < catalogo->tamanio(); i++) {
            Material* mate = catalogo->obtenerMaterial(i);
            cout << i+1 << ")" << mate->getTitulo() << endl;
        }

        cout << endl;
        cout << "Ingrese el titulo del material que desea modificar: "; getline(cin, titulo);

        bool encontrado = false;

        for (int i = 0; i < catalogo->tamanio(); ++i) {
            Material* mat = catalogo->obtenerMaterial(i);
            if (mat->getTitulo() == titulo) {
                encontrado = true;

                cout << "\n-------Material encontrado--------\n";

                string nuevoTitulo, tipoNuevo, nuevoFormato, nuevoAutor, nuevasPalabras, nuevoEstado, nuevaUbicacionFisica;
                int nuevoNumero, nuevoVolumen, nuevoNumeroCatalogo, nuevoNumeroClasificacion;
                cout << "\nIngrese nuevo titulo: "; getline(cin, nuevoTitulo);
                cout << "Ingrese nuevo autor: "; getline(cin, nuevoAutor);
                cout << "Ingrese nuevas palabras clave: "; getline(cin, nuevasPalabras);
                cout << "Ingrese nuevo estado (Excelente, Regular, Malo): "; getline(cin, nuevoEstado);
                cout<< "Nuevo numero Catalogo: "; cin >> nuevoNumeroCatalogo;
                if (cin.fail()) throw invalid_argument("Nuevo Numero Catalogo para el Material");
                cout<< "Nuevo numero de Clasificacion: ";  cin >> nuevoNumeroClasificacion;
                if (cin.fail()) throw invalid_argument("Nuevo Numero Clasificacion para el Material");

                if (mat->getTipoMaterial() == "libro" || mat->getTipoMaterial() == "Libro") {
                    Libro* libro = dynamic_cast<Libro*>(mat);
                    cin.ignore();
                    cout<< "Nueva ubicacion Fisica: "; getline(cin,nuevaUbicacionFisica);
                    libro->setTitulo(nuevoTitulo);
                    libro->setAutor(nuevoAutor);
                    libro->setPalabrasClave(nuevasPalabras);
                    libro->setEstadoMaterial(nuevoEstado);
                    libro->setNumeroCatalogo(nuevoNumeroCatalogo);
                    libro->setNumeroClasificacion(nuevoNumeroClasificacion);
                    libro->setUbicacionFisica(nuevaUbicacionFisica);
                } else if (mat->getTipoMaterial() == "revista" || mat->getTipoMaterial() == "Revista") {
                    cout << "Nuevo numero de la revista: "; cin >> nuevoNumero;
                    if (cin.fail()) throw invalid_argument("Nuevo Numero inválido.");
                    cout<< "Nuevo volumen: "; cin >> nuevoVolumen;
                    if (cin.fail()) throw invalid_argument("Nuevo Volumen inválido.");
                    cin.ignore();
                    cout << "Nueva ubicacion Fisica: "; getline(cin,nuevaUbicacionFisica);
                    Revista* revista = dynamic_cast<Revista*>(mat);
                    revista->setTitulo(nuevoTitulo);
                    revista->setAutor(nuevoAutor);
                    revista->setPalabrasClave(nuevasPalabras);
                    revista->setEstadoMaterial(nuevoEstado);
                    revista->setNumeroCatalogo(nuevoNumeroCatalogo);
                    revista->setNumeroClasificacion(nuevoNumeroClasificacion);
                    revista->setUbicacionFisica(nuevaUbicacionFisica);
                    revista->setVolumen(nuevoVolumen);
                    revista->setNumero(nuevoNumero);
                } else if (mat->getTipoMaterial() == "articulo" || mat->getTipoMaterial() == "Articulo") {
                    Articulo* articulo = dynamic_cast<Articulo*>(mat);
                    articulo->setTitulo(nuevoTitulo);
                    articulo->setAutor(nuevoAutor);
                    articulo->setPalabrasClave(nuevasPalabras);
                    articulo->setEstadoMaterial(nuevoEstado);
                    articulo->setNumeroCatalogo(nuevoNumeroCatalogo);
                    articulo->setNumeroClasificacion(nuevoNumeroClasificacion);
                    cin.ignore();
                } else if (mat->getTipoMaterial() == "video" || mat->getTipoMaterial() == "Video") {
                    Video* video = dynamic_cast<Video*>(mat);
                    video->setTitulo(nuevoTitulo);
                    video->setAutor(nuevoAutor);
                    video->setPalabrasClave(nuevasPalabras);
                    video->setEstadoMaterial(nuevoEstado);
                    video->setNumeroCatalogo(nuevoNumeroCatalogo);
                    video->setNumeroClasificacion(nuevoNumeroClasificacion);
                    cin.ignore();
                } else if (mat->getTipoMaterial() == "material digital" || mat->getTipoMaterial() == "Material Digital" || mat->getTipoMaterial() == "material Digital" || mat->getTipoMaterial() == "Material digital") {
                    materialDigital* mateDigital = dynamic_cast<materialDigital*>(mat);
                    if (mateDigital->getTipo() == "Digital" || mateDigital->getTipo() == "digital") {
                        MaterialDigitalFormatoDigital* materialDigitalFormatoDigital = dynamic_cast<MaterialDigitalFormatoDigital*>(mateDigital);
                        materialDigitalFormatoDigital->setTitulo(nuevoTitulo);
                        materialDigitalFormatoDigital->setAutor(nuevoAutor);
                        materialDigitalFormatoDigital->setPalabrasClave(nuevasPalabras);
                        materialDigitalFormatoDigital->setEstadoMaterial(nuevoEstado);
                        materialDigitalFormatoDigital->setNumeroCatalogo(nuevoNumeroCatalogo);
                        materialDigitalFormatoDigital->setNumeroClasificacion(nuevoNumeroClasificacion);
                        cin.ignore();
                    } else if (mateDigital->getTipo() == "Fisico" || mateDigital->getTipo() == "físico" || mateDigital->getTipo() == "fisico") {
                        cin.ignore();
                        cout<< "Nuevo formato((CD, DVD, BluRay): " ; getline(cin,nuevoFormato);
                        MaterialDigitalFormatoFisico* materialDigitalFormatofisico = dynamic_cast<MaterialDigitalFormatoFisico*>(mateDigital);
                        materialDigitalFormatofisico->setTitulo(nuevoTitulo);
                        materialDigitalFormatofisico->setAutor(nuevoAutor);
                        materialDigitalFormatofisico->setPalabrasClave(nuevasPalabras);
                        materialDigitalFormatofisico->setEstadoMaterial(nuevoEstado);
                        materialDigitalFormatofisico->setNumeroCatalogo(nuevoNumeroCatalogo);
                        materialDigitalFormatofisico->setNumeroClasificacion(nuevoNumeroClasificacion);
                        materialDigitalFormatofisico->setFormatoFIsico(nuevoFormato);
                    }
                }
                cout << "\nMaterial modificado con exito.\n";
            }
        }

        if (!encontrado) {
            Excepciones::handleUnknownTitleType(titulo);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
    } catch (const invalid_argument& e) {
        Excepciones::handleInvalidInput(e.what());
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    } catch (const exception& e) {
        Excepciones::handleUnhandledException(e);
        return;
    }

    cout << "\n Presione Enter para volver al menu...";
    cout <<"\n------------------------------------------------------------------------------------------------";
    cin.ignore();
}


void GestorMateriales::ReporteMaterial() {
try {
    cout <<"\n\n------------------------------------Reporte Materiales------------------------------------------------------"<<endl;

    if (catalogo == nullptr || catalogo->esVacia()) {
        Excepciones::EmptyList();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    } else {
        cout << catalogo->mostrar() << endl;
    }

    } catch (const exception& e) {
        Excepciones::handleUnhandledException(e);
        return;
    }

    cout << "\n Presione Enter para volver al menu...";
    cout<<"\n------------------------------------------------------------------------------------------------";
    cin.get();
}
