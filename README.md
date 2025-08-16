# 📚 Proyecto Biblioteca

Este es un sistema modular en **C++** que permite gestionar los materiales, usuarios y préstamos de una biblioteca.  
Su diseño se basa en **Programación Orientada a Objetos** y estructuras de datos personalizadas, ofreciendo un enfoque didáctico y escalable.

---

## 🚀 Características principales

- **Gestión de usuarios**: registro y administración de lectores.
- **Gestión de materiales**: libros, revistas y otros recursos.
- **Préstamos y devoluciones**: control del estado de los materiales prestados.
- **Manejo de excepciones**: errores controlados y mensajes claros al usuario.
- **Estructuras de datos propias**: listas enlazadas y nodos.
- **Interfaz de consola**: menú interactivo para navegar por el sistema.
- **Almacenamiento persistente**: carga y guardado de datos en archivos de texto.

---

## 📂 Estructura del proyecto

| Carpeta / Archivo             | Descripción |
|-------------------------------|-------------|
| `Biblioteca`                | Clase principal que integra todos los módulos |
| `GestorUsuario`             | Manejo de usuarios |
| `GestorMateriales`          | Manejo de materiales |
| `GestorPrestamos`           | Flujo de los préstamos |
| `AdministrarAlmacenamiento` | Persistencia de datos |
| `Excepciones`               | Manejo de errores personalizados |
| `Lista`, `Nodo`           | Implementación de estructuras de datos |
| `Usuario`, `Prestamo`     | Entidades principales |
| `Utilities`                 | Funciones auxiliares |
| `Menu`, `main.cpp`          | Interfaz de usuario y punto de entrada |

---

## ⚙️ Compilación y ejecución

Este proyecto utiliza **CMake** como sistema de compilación.  

### 🔧 Pasos para compilar

1. Clonar el repositorio:
   ```bash
   git clone https://github.com/SebastianGomezSolis/Proyecto_Biblioteca.git
   cd Proyecto_Biblioteca
2. Crear carpeta de compilación:
   ```bash
   mkdir build
   cd build
3. Generar los archivos de construcción:
   ```bash
   cmake ..
4. Compilar el proyecto:
   ```bash
   cmake --build .
5. Ejecutar el programa:
   ```bash
   ./Proyecto_Biblioteca

## 🖼️ Capturas de ejecución

<img width="691" height="277" alt="image" src="https://github.com/user-attachments/assets/c68fb9ad-5859-48f8-a3e5-3f110dac254e" />

- Aqui un ejemplo del programa en ejecucion.

## 🔮 Algunas posibles extensiones futuras

Reportes de uso y estadísticas.

Control de roles y permisos de administradores.

## 👥 Autores

- Sebastián Gómez Solís - [@SebastianGomezSolis](https://github.com/SebastianGomezSolis)
- Josue Peñaranda Alvarado - [@JosuePenaranda](https://github.com/JosuePenaranda)

Este proyecto fue realizado como parte del curso Programación 2 (EIF204) en la Universidad Nacional de Costa Rica.





