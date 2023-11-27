// Materia: Programación I, Paralelo 1

// Autor: leonardo romero

// Fecha creación: 22/11/2023

// Fecha modificación: 23/11/2023

// Número de ejericio: 4

// Problema planteado: ejercicio 4
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
    vector<Articulo> almacen;
    Articulo articulo;

    cout << "Ingrese datos de los articulos. Para finalizar, introduzca el codigo: "<<endl;

    while (true) {
        cout << "Codigo del articulo (0 para finalizar): ";
        cin >> articulo.codigo;

        if (articulo.codigo == 0) {
            break;
        }

        cin.ignore(); // Limpiar el buffer de entrada

        cout << "Nombre del articulo: ";
        getline(cin, articulo.nombre);

        cout << "Existencias actuales: ";
        cin >> articulo.existencias;

        cout << "Precio: ";
        cin >> articulo.precio;

        almacen.push_back(articulo);
    }

    // Ordenar el vector por el código del artículo
    sort(almacen.begin(), almacen.end(), compararPorCodigo);

    // Crear y escribir en el archivo
    ofstream archivo("almacen.dat", ios::binary);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    for (const auto& a : almacen) {
        archivo.write(reinterpret_cast<const char*>(&a), sizeof(a));
    }

    archivo.close();

    cout << "Datos almacenados en el archivo 'almacen2.dat'"<<endl;

    return 0;
}
