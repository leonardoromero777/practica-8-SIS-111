// Materia: Programación I, Paralelo 1

// Autor: leonardo romero

// Fecha creación: 22/11/2023

// Fecha modificación: 23/11/2023

// Número de ejericio: 8

// Problema planteado: ejercicio 8
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    string nombreArchivoEntrada;
    cout << "Ingrese el nombre del archivo de entrada en formato binario: ";
    cin >> nombreArchivoEntrada;

    ifstream archivoEntrada(nombreArchivoEntrada, ios::binary);
    if (!archivoEntrada.is_open()) {
        cout << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    vector<vector<double>> tabla;

    while (!archivoEntrada.eof()) {
        vector<double> fila;
        double numero;

        while (archivoEntrada.read(reinterpret_cast<char*>(&numero), sizeof(double))) {
            fila.push_back(numero);
        }

        if (!fila.empty()) {
            tabla.push_back(fila);
        }
    }

    archivoEntrada.close();

    // Calcular la suma horizontal y vertical
    vector<double> sumaHorizontal(tabla.size(), 0.0);
    vector<double> sumaVertical(tabla[0].size(), 0.0);

    for (size_t i = 0; i < tabla.size(); ++i) {
        for (size_t j = 0; j < tabla[i].size(); ++j) {
            sumaHorizontal[i] += tabla[i][j];
            sumaVertical[j] += tabla[i][j];
        }
    }

    cout << "Tabla original:\n";
    for (const auto& fila : tabla) {
        for (const auto& numero : fila) {
            cout <<fixed <<setprecision(2) << numero << " ";
        }
        cout << endl;
    }

    cout << "\nSuma horizontal:\n";
    for (const auto& suma : sumaHorizontal) {
        cout << fixed << setprecision(2) << suma << " ";
    }
    cout << endl;

    cout << "\nSuma vertical:\n";
    for (const auto& suma : sumaVertical) {
        cout << fixed << setprecision(2) << suma << endl;
    }

    string nombreArchivoSalida;
    cout << "\nIngrese el nombre del archivo de salida (con extensión .txt o .bin): ";
    cin >> nombreArchivoSalida;

    ofstream archivoSalida(nombreArchivoSalida, ios::binary);

    if (!archivoSalida.is_open()) {
        cout << "Error al abrir el archivo de salida." <<endl;
        return 1;
    }

    for (const auto& fila : tabla) {
        archivoSalida.write(reinterpret_cast<const char*>(fila.data()), fila.size() * sizeof(double));
    }

    archivoSalida.write(reinterpret_cast<const char*>(sumaHorizontal.data()), sumaHorizontal.size() * sizeof(double));

    archivoSalida.write(reinterpret_cast<const char*>(sumaVertical.data()), sumaVertical.size() * sizeof(double));

    archivoSalida.close();

    cout << "\nResultados guardados en el archivo " << nombreArchivoSalida << endl;

    return 0;
}
