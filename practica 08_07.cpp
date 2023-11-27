// Materia: Programación I, Paralelo 1

// Autor: leonardo romero

// Fecha creación: 22/11/2023

// Fecha modificación: 23/11/2023

// Número de ejericio: 7

// Problema planteado: ejercicio 7
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
string limpiar (const string& palabra)
{
    string palabralimpia = palabra;
    palabralimpia.erase(remove_if(palabralimpia.begin(),palabralimpia.end(), ::ispunct),palabralimpia.end());
    transform (palabralimpia.begin(), palabralimpia.end(),palabralimpia.begin(), ::tolower);
    return palabralimpia;
}
int main()
{
    string nombreArchivo;
    cout<<"ingrese nombre del archivo: ";
    cin>>nombreArchivo;
    ifstream archivo(nombreArchivo);
    if(!archivo.is_open())
    {
        cout<<"error al abrir el archivo"<<endl;
        return 1;
    }
    string palabra;
    vector<string> palabras;
    while (archivo>>palabra)
    {
        palabra = limpiar(palabra);
        if(!palabra.empty())
        {
            palabras.push_back(palabra);
        }
    }
    archivo.close();
    cout<<"estadistica del numero de palabras";
    cout<<"numero total de palabras: "<<palabras.size()<<endl;
    sort(palabras.begin(), palabras.end());
    palabras.erase(unique(palabras.begin(), palabras.end()), palabras.end());
    cout<<"numero de plabras unicas: "<<palabras.size()<<endl;
    return 0;
}
