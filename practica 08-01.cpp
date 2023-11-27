#include <iostream>
#include <fstream>

void encrypt(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        inputFile.close();
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        ch = ch + 3; // Encriptar: reemplazar cada carácter por el tercero siguiente en la tabla ASCII
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Archivo encriptado guardado como " << outputFileName << std::endl;
}

void decrypt(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
        return;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
        inputFile.close();
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        ch = ch - 3; // Desencriptar: reemplazar cada carácter por el tercero anterior en la tabla ASCII
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Archivo desencriptado guardado como " << outputFileName << std::endl;
}

int main() {
    std::string fileName;
    std::cout << "Ingrese el nombre del archivo (sin extensión): ";
    std::cin >> fileName;

    std::string inputFileName = fileName + ".txt";
    std::string encryptedFileName = fileName + ".COD";
    std::string decryptedFileName = fileName + "_decrypted.txt";

    // Encriptar el archivo de entrada
    encrypt(inputFileName, encryptedFileName);

    // Desencriptar el archivo encriptado
    decrypt(encryptedFileName, decryptedFileName);

    return 0;
}
