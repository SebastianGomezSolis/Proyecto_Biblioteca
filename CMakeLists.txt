cmake_minimum_required(VERSION 3.31)
project(Proyecto_Biblioteca)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_Biblioteca main.cpp
        Materiales/Material.cpp
        Materiales/Material.h
        Utilities.h
        Materiales/Articulo.cpp
        Materiales/Articulo.h
        Materiales/Libro.cpp
        Materiales/Libro.h
        Materiales/materialDigital.cpp
        Materiales/materialDigital.h
        Materiales/MaterialDigitalFormatoDigital.cpp
        Materiales/MaterialDigitalFormatoDigital.h
        Materiales/MaterialDigitalFormatoFisico.cpp
        Materiales/MaterialDigitalFormatoFisico.h
        Materiales/Revista.cpp
        Materiales/Revista.h
        Materiales/Video.cpp
        Materiales/Video.h
        AdministrarAlmacenamiento.cpp
        AdministrarAlmacenamiento.h
        Biblioteca.cpp
        Biblioteca.h
        Excepciones.cpp
        Excepciones.h
        Nodo.h
        Lista.h
        GestorMateriales.cpp
        GestorMateriales.h
        Prestamo.cpp
        Prestamo.h
        Usuario.cpp
        Usuario.h
        GestorPrestamos.cpp
        GestorPrestamos.h
        GestorUsuario.cpp
        GestorUsuario.h
        Menu.cpp
        Menu.h)
