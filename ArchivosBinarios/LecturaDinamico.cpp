#include <iostream>
#include <fstream>
#include <vector>

/*
    Ejemplo de lectura dinamica, leyendo structs de un archivo 
    binario, sin conocer cuantas estructuras hay dentro del archivo, 
    empleando vector para guardar los datos.
*/

struct EstructuraTest{
    char nombre[35];
    float altura;
    int edad;
    bool validez;
};

int main() {
    std::vector<EstructuraTest> personasLeidas;
    EstructuraTest temp;

    // Abrimos el archivo para lectura binaria
    std::ifstream fentrada("archivoBinario.dat", std::ios::in | std::ios::binary);

    if (fentrada.is_open()) {
        // Leer las estructuras hasta llegar al final del archivo
        while (fentrada.read((char*)&temp, sizeof(EstructuraTest))) {
            personasLeidas.push_back(temp);  // Guardamos cada estructura leída en el vector
        }
        fentrada.close();

        // Imprimir los datos leídos
        for (const auto& persona : personasLeidas) {
            std::cout << "Nombre: " << persona.nombre << std::endl;
            std::cout << "Edad: " << persona.edad << std::endl;
            std::cout << "Altura: " << persona.altura << std::endl << std::endl;
        }
    } else {
        std::cerr << "Error al abrir el archivo para leer." << std::endl;
    }

    return 0;
}
