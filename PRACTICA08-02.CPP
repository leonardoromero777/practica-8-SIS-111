// Materia: Programación I, Paralelo 1

// Autor: leonardo romero

// Fecha creación: 22/11/2023

// Fecha modificación: 23/11/2023

// Número de ejericio: 2

// Problema planteado: ejercicio 2
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

struct Persona {
    string nombre;
    int edad;
    char sexo;
    string fechaNacimiento;
};

int main() {
    ofstream archivo("PERSONAS.BIN", ios::binary);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    Persona persona;

    while (true) {
        cout << "Nombre (Ingrese espacio para terminar): ";
        getline(cin, persona.nombre);

        if (persona.nombre.empty() || persona.nombre[0] == ' ') {
            break;
        }

        cout << "Edad: ";
        cin >> persona.edad;

        cout << "Sexo (M/F): ";
        cin >> persona.sexo;

        cout << "Fecha de Nacimiento (dd/mm/yyyy): ";
        cin >> persona.fechaNacimiento;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Escribir la información al archivo binario
        archivo.write(reinterpret_cast<const char*>(&persona), sizeof(persona));
    }

    archivo.close();
    cout << "Informacion de personas guardada en PERSONAS.BIN" << endl;

    return 0;
}
