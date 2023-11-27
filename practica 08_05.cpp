// Materia: Programación I, Paralelo 1

// Autor: leonardo romero

// Fecha creación: 22/11/2023

// Fecha modificación: 23/11/2023

// Número de ejericio: 5

// Problema planteado: ejercicio 5
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Articulo {
    int codigo;
    string nombre;
    int existencias;
    double precio;
};

bool compararPorCodigo(const Articulo& a, const Articulo& b) {
    return a.codigo < b.codigo;
}

int main() {
    ifstream archivo1("almacen1.dat", ios::binary);
    ifstream archivo2("almacen2.dat", ios::binary);
    ofstream archivoSalida("mezcla.dat", ios::binary);

    if (!archivo1.is_open() || !archivo2.is_open() || !archivoSalida.is_open()) {
        cout << "Error al abrir los archivos." << endl;
        return 1;
    }

    vector<Articulo> almacen1;
    vector<Articulo> almacen2;

    Articulo articulo;

    // Leer datos de los dos archivos
    while (archivo1.read(reinterpret_cast<char*>(&articulo), sizeof(articulo))) {
        almacen1.push_back(articulo);
    }

    while (archivo2.read(reinterpret_cast<char*>(&articulo), sizeof(articulo))) {
        almacen2.push_back(articulo);
    }

    // Mezclar los dos vectores
    vector<Articulo> almacenMezclado;
    merge(almacen1.begin(), almacen1.end(), almacen2.begin(), almacen2.end(), back_inserter(almacenMezclado), compararPorCodigo);

    // Escribir en el archivo de salida
    for (const auto& a : almacenMezclado) {
        archivoSalida.write(reinterpret_cast<const char*>(&a), sizeof(a));
    }

    archivo1.close();
    archivo2.close();
    archivoSalida.close();

    cout << "Mezcla de archivos completada. Resultado guardado en 'mezcla.dat'.\n";

    return 0;
}
