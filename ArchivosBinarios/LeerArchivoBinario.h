#ifndef LEER_BINARIO_H
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

/*
    Funcion template para leer un archivo binario automaticamente
    Devuelve un vector con el tipo de dato.

    Pendiente a mejorar, quiero que pueda leer el archivo
    entero y inferir cuantos datos hay para no tener que estar
    recolocando memoria constantemente con el pushback.
*/

template <class Struct>
vector <Struct> read (const char * direccion){
    Struct aux;
    ifstream archivo(direccion, ios::binary | ios::ate);
    vector<Struct> datos;

    if (archivo.is_open()) {
        int tamanioArchivo = archivo.tellg();
        size_t cantidadDatos = tamanioArchivo / sizeof(Struct);
        archivo.seekg(0, ios::beg); 
        datos.reserve(tamanioArchivo);

        // Leer las estructuras hasta llegar al final del archivo
        while (archivo.read((char*) &aux, sizeof(Struct))) {
            datos.push_back(aux);  // Guardamos cada estructura leída en el vector
        }
        archivo.close();
    } 
    
    return datos;
}

#endif // !LEER_BINARIO_H
