#include <iostream>
using namespace std;

// Estructura automóvil
struct Auto {
    string marca;
    string modelo;
    int year;
};


int main()
{
    string nombre = "Grupo Estructuras de Datos y Algoritmos 1";
    cout << "Hola " << nombre << ", hoy es lunes" << endl;

    // Crear tres Automóviles
    Auto carrito1 = {"Volvo", "XC30", 2024};
    Auto carrito2 = {"Mazda", "CX5", 2026};
    Auto carrito3 = {"BMW", "Hatchback", 2025};

    // Mostrar la información de los vehículos
    cout << carrito1.marca << ", " << carrito1.modelo << ", " << carrito1.year << endl;
    cout << carrito2.marca << ", " << carrito2.modelo << ", " << carrito2.year << endl;
    cout << carrito3.marca << ", " << carrito3.modelo << ", " << carrito3.year << endl;
    
    return 0;
}