#include <iostream>
#include "alumno.h"
#include <string.h>

using namespace std;

long Alumno::getDNI(long dni)
{
    return dni;
}

char* Alumno::getNombre(char* nombre)
{
    return nombre;
}

Alumno::Alumno(long dni)
{
    this->dni = dni;
}
Alumno::Alumno(long dni, char* nombre){
    this->dni = dni;
    strcpy()
}
