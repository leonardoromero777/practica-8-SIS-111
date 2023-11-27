// Materia: Programación I, Paralelo 1

// Autor: leonardo romero

// Fecha creación: 22/11/2023

// Fecha modificación: 23/11/2023

// Número de ejericio: 3

// Problema planteado: ejercicio 3
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Persona {
    string nombre;
    int edad;
    char sexo;
    string fechaNacimiento;
};

void leerPersonasDesdeArchivo(const string& nombreArchivo,  vector<Persona>& personas) {
    ifstream archivo(nombreArchivo, ios::binary);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." <<endl;
        return;
    }

    Persona persona;
    while (archivo.read(reinterpret_cast<char*>(&persona), sizeof(persona))) {
        personas.push_back(persona);
    }

    archivo.close();
}

void escribirCandidatosAceptados(const string& nombreArchivo, const vector<Persona>& candidatosAceptados) {
    ofstream archivo(nombreArchivo, ios::binary);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." <<endl;
        return;
    }

    for (const auto& candidato : candidatosAceptados) {
        archivo.write(reinterpret_cast<const char*>(&candidato), sizeof(candidato));
    }

    archivo.close();
}

int main() {
    vector<Persona> candidatos;
    leerPersonasDesdeArchivo("PERSONAS.BIN", candidatos);

    vector<Persona> candidatosAceptados;

    Persona cliente;
    cout << "Ingrese sus datos como cliente:" << endl;
    cout << "Nombre: ";
    getline(cin, cliente.nombre);

    cout << "Edad: ";
    cin >> cliente.edad;

    cout << "Sexo (M/F): ";
    cin >> cliente.sexo;

    cout << "Fecha de Nacimiento (dd/mm/yyyy): ";
    cin >> cliente.fechaNacimiento;

    // Comprobar la compatibilidad con los candidatos y generar la lista de aceptados
    for (const auto& candidato : candidatos) {
        if (candidato.sexo != cliente.sexo &&
            candidato.fechaNacimiento.substr(3, 7) == cliente.fechaNacimiento.substr(3, 7)) {
            candidatosAceptados.push_back(candidato);
        }
    }

    cout << "\nCandidatos Aceptados:\n";
    for (const auto& candidato : candidatosAceptados) {
        cout << candidato.nombre <<endl;
    }

    escribirCandidatosAceptados("ACEPTADOS.DAT", candidatosAceptados);

    return 0;
}
