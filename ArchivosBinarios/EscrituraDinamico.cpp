#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

/*
    Ejemplo de escribir un archivo usando,
    usando un vector dinamico de structs.
*/

using namespace std;

struct EstructuraTest{
    char nombre[35];
    float altura;
    int edad;
    bool validez;
};

int main(int argc, char const *argv[])
{
    EstructuraTest temporal;
    vector <EstructuraTest> VectorEstructuras;

    // Seteamos los datos de los structs:
    strcpy(temporal.nombre, "Jorge");
    temporal.altura = 1.90;
    temporal.edad = 20;
    temporal.validez = false;
    VectorEstructuras.push_back(temporal);

    strcpy(temporal.nombre, "Maria");
    temporal.altura = 1.40;
    temporal.edad = 40;
    temporal.validez = true;
    VectorEstructuras.push_back(temporal);

    // Escribimos los structs
    auto direccion = "archivoBinario.dat";
    ofstream archivoEscritura(direccion, ios::binary);

    // Usamos char* para convertir los structs en simplemente una secuencia de bits.
    // Ya que recuerden que c++ solo ve los archivos como una secuencia de los mismos.
    // Para escribir los datos usando un vector dinamico, usamos el 
    // metodo data() que nos devuelve el puntero al array con los datos. 
    // Sizeof sirve para indicarle a c++ cuanto debe escribir, en este caso 
    // como el vector es dinamico, el compilador no sabra cuantos structs queremos 
    // escribir, por lo que toca multiplicar el tamanio de EstructuraTest por la 
    // cantidad de structs que tenemos, suando el metodo size()

    archivoEscritura.write((char*) VectorEstructuras.data(), sizeof(EstructuraTest) * VectorEstructuras.size());
    archivoEscritura.close();

    return 0;
}