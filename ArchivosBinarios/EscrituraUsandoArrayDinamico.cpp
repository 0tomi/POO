#include <fstream>
#include <iostream>
#include <string.h>

/*
    Ejemplo de escribir un archivo usando,
    usando un array dinamico mediante un puntero.
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
    int MAX = 2;
    auto arrayStructs = new EstructuraTest[MAX];

    // Seteamos los datos de los structs:
    strcpy(arrayStructs[0].nombre, "Jorge");
    arrayStructs[0].altura = 1.90;
    arrayStructs[0].edad = 20;
    arrayStructs[0].validez = false;

    strcpy(arrayStructs[1].nombre, "Maria");
    arrayStructs[1].altura = 1.40;
    arrayStructs[1].edad = 40;
    arrayStructs[1].validez = true;

    // Escribimos los structs
    auto direccion = "archivoBinario.dat";
    ofstream archivoEscritura(direccion, ios::binary);

    /*
        Usamos char* para convertir los structs en simplemente una secuencia de bits.
        Ya que recuerden que c++ solo ve los archivos como una secuencia de los mismos.
        Este al ser un puntero a struct, no es necesario poner el & porque el puntero
        en si mismo apunta ya al primer byte donde arrancan los structs.
        Pasa algo similar que usando vector, write no sabe cuantos structs queremos escribir
        asi que tocara multiplicar el sizeof del struct, por la cantidad de espacios que 
        este usando nuestro array dinamico.
    */ 

    archivoEscritura.write((char*) arrayStructs, sizeof(EstructuraTest) * MAX);
    archivoEscritura.close();

    delete[] arrayStructs;
    return 0;
}