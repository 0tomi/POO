#ifndef LEER_BINARIO_H
#include <vector>
#include <fstream>
using namespace std;

/*
    Funcion template para leer un archivo binario automaticamente
    Devuelve un vector con el tipo de dato.
*/

template <class Struct>
vector <Struct> read (const char * direccion){
    Struct aux;
    ifstream archivo(direccion, ios::binary | ios::ate);
    auto tamanioArchivo = archivo.tellg();
    size_t cantidadDatos = tamanioArchivo / sizeof(Struct);
    archivo.seekg(0, ios::beg); 

    vector<Struct> datos(cantidadDatos);
    if (archivo.is_open()) {
        // Leer las estructuras hasta llegar al final del archivo
        while (archivo.read((char*) &aux, sizeof(Struct))) {
            datos.push_back(aux);  // Guardamos cada estructura leída en el vector
        }
        archivo.close();
    } 
    
    return datos;
}

#endif // !LEER_BINARIO_H
