#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

struct EstructuraTest{
    char nombre[35];
    float altura;
    int edad;
    bool validez;
};

int main(int argc, char const *argv[])
{
    EstructuraTest pruebas[2];
    // Seteamos los datos de los structs:
    strcpy(pruebas[0].nombre, "Jorge");
    pruebas[0].altura = 1.90;
    pruebas[0].edad = 20;
    pruebas[0].validez = false;

    strcpy(pruebas[1].nombre, "Maria");
    pruebas[1].altura = 1.40;
    pruebas[1].edad = 40;
    pruebas[1].validez = true;

    // Escribimos loes structs
    auto direccion = "archivoBinario.dat";
    ofstream archivoEscritura(direccion, ios::binary);
    // Usamos char* para convertir los structs en simplemente una secuencia de bits.
    // Ya que recuerden que c++ solo ve los archivos como una secuencia de los mismos.
    // El & es para indicar donde empieza el bloque de memoria.
    // Sizeof sirve para indicarle a c++ cuanto debe escribir, como el array es estatico
    // implictamente ya le estamos diciendo que escriba TODO el array.
    archivoEscritura.write((char*) &pruebas, sizeof(pruebas));
    archivoEscritura.close();

    return 0;
}

