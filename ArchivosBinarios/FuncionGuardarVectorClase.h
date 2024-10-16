#ifndef FUNCION_H
#include <vector>
#include <fstream>
#include <string>
using namespace std;

/*
    Test de funcion generica para escribir archivos
    Para que esta funcion ande, necesita que la clase
    la cual queremos guardar en el archivo binario, 
    tenga un metodo dato() que devuelva una estructura
    del tipo de parametro que pasamos a la funcion.
*/ 

template <class Clase, class DatosClase>
void write(vector <Clase> &VectorClase, string Direccion){
    vector <DatosClase> datos;
    datos.resize(VectorClase.size());

    for (auto &Objeto: VectorClase)
        datos.push_back(Objeto.dato());

    ofstream archivo(Direccion, ios::binary);
    archivo.write((char*) datos.data(), sizeof(DatosClase) * datos.size());
    archivo.close();
}

#endif // !FUNCION_H
