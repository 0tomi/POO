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

int Alumno::getNota3() const
{
    this->nota3 = newNota3;
}

Alumno::Alumno(long dni)
{
    this->dni = dni;
}
Alumno::Alumno(long dni, char* nombre){
    this->dni = dni;
    strcpy()
}

double Alumno::promedio(){
    return (this->nota1 + this->nota2 + this->nota3) / 3.0;
}