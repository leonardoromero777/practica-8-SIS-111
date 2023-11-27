// Materia: Programación I, Paralelo 1

// Autor: leonardo romero

// Fecha creación: 22/11/2023

// Fecha modificación: 23/11/2023

// Número de ejericio: 9

// Problema planteado: ejercicio 9
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
 int main()
 {
     string inputfilename = "ficheroentrada.txt";
     string outputfilename = "ficherosalida.bin";
     ifstream inputFile(inputfilename);
     if (!inputFile.is_open())
     {
         cout<<"error al abrir el archivo"<<endl;
         return 1;
     }
     vector <double> numeros;
     double numero;
     while(inputFile >> numero)
     {
         numeros.push_back(numero);
     }
     inputFile.close();
     ofstream outputFile(outputfilename, ios::binary);
     if (!outputFile.is_open())
     {
         cout<<"error al abrir el archivo"<<endl;
         return 1;
     }
     outputFile.write(reinterpret_cast<const char*>(numeros.data()), numeros.size() * sizeof(double));
     outputFile.close();
     cout<<"archivo binario generado "<<outputfilename<<endl;
     return 0;
 }
