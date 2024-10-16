#include <iostream>
#include "FuncionGuardarVectorClase.h"

/*
    Test de la funcion para guardar archivos de forma automatica
*/

struct DatosAlumno{
    int Edad;
    char nombre[50];
    float altura;
};

class Alumno{
public:
    Alumno(): edad(20), nombre("juanceto"), altura(1.50) {}
    DatosAlumno dato();
private:
    int edad;
    string nombre;
    float altura;
};

DatosAlumno Alumno::dato(){
    DatosAlumno aux;
    aux.Edad = this->edad;
    nombre.copy(aux.nombre, 50);
    aux.nombre[nombre.length() - 1] = '\0';
    aux.altura = this->altura;

    return aux;
}

int main(int argc, char const *argv[])
{
    Alumno prueba;
    vector <Alumno> Test;
    Test.push_back(prueba);
    write<Alumno, DatosAlumno>(Test, "archivoTestFuncion.dat");
    return 0;
}
