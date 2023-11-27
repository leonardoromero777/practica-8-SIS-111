// Materia: Programaci�n I, Paralelo 1

// Autor: leonardo romero

// Fecha creaci�n: 22/11/2023

// Fecha modificaci�n: 23/11/2023

// N�mero de ejericio:6

// Problema planteado: ejercicio 6
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Articulo {
    int codigo;
    string nombre;
    int existencias;
    double precio;
};

void filtrarPorPrecio(const string& inputFile, const string& outputFile, double condicionPrecio) {
    ifstream archivoEntrada(inputFile, ios::binary);
    ofstream archivoSalida(outputFile, ios::binary);

    if (!archivoEntrada.is_open() || !archivoSalida.is_open()) {
        cout << "Error al abrir los archivos." << endl;
        return;
    }

    Articulo articulo;

    while (archivoEntrada.read(reinterpret_cast<char*>(&articulo), sizeof(articulo))) {
        // Verificar la condici�n de precio
        if (articulo.precio <= condicionPrecio) {
            archivoSalida.write(reinterpret_cast<const char*>(&articulo), sizeof(articulo));
        }
    }

    cout << "Filtrado de articulos completado. Resultado guardado en " << outputFile << endl;

    archivoEntrada.close();
    archivoSalida.close();
}

int main() {
    string inputFile = "almacen.dat";
    string outputFile = "salida.dat";

    double condicionPrecio;

    cout << "Ingrese la condicion de precio: ";
    cin >> condicionPrecio;

    filtrarPorPrecio(inputFile, outputFile, condicionPrecio);

    return 0;
}
