#include "Menu.h"

int main() {
    Menu*  menu1 = new Menu();
    menu1->mostrarMenu();
    delete menu1;
    return 0;
}

// El Principio de Sustitución de Liskov(LSP) establece que las clases derivadas deben ser sustituibles por sus clases base sin alterar el comportamiento esperado del programa.
// En este proyecto, el LSP se aplica principalmente en la jerarquía de clases relacionadas con los materiales(Material) y los usuarios (Usuario).
// Ejemplo en el Proyecto: Clase Material
// La clase Material parece ser una clase base que puede tener subclases como Libro, Revista, Video, etc.
// Estas subclases heredan de Material y pueden ser utilizadas de manera intercambiable en el programa, siempre que respeten la interfaz y el comportamiento definido en la clase base.
// Por ejemplo: En el metodo cargarPrestamos, se accede a los materiales a través de punteros o referencias a la clase base Material.
// Esto permite que cualquier subclase de Material(como Libro o Revista) sea utilizada sin necesidad de modificar el código que gestiona los préstamos.
// Este diseño respeta el LSP porque las subclases de Material no alteran el comportamiento esperado del programa.
// Cada subclase puede implementar su propio comportamiento específico (por ejemplo, un metodo getTipoMaterial), pero sigue siendo tratada como un Material en el contexto general.
// En este proyecto:
//    -El LSP se aplica en la jerarquía de clases como Material y sus subclases, permitiendo que las subclases sean utilizadas de manera intercambiable sin alterar el comportamiento del programa.
//    -La delegación mediante composición se utiliza en clases como Menu, que delega la gestión de usuarios, materiales y préstamos a la clase Biblioteca, promoviendo un diseño modular y flexible.
