#include "productos.h"

Productos::Productos(float actualprecio, char * actualcodigo)
{
    this->precio = actualprecio;
    this->codigo = setNewString(actualcodigo);
}

float Productos::getPrecio()
{

}

char *Productos::setNewString(const char *base)
{
    char * newString = new char[strlen(base)+1];
    strcpy(newString, base);

    return newString;
}
