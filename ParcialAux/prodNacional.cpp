#include "prodNacional.h"
ProductoNacional::ProductoNacional(float newPrecio, char * newCode)
{
    this->precio = newPrecio;
    this->codigo = this->setCodigo(newCode);
}

void ProductoNacional::ajustar(float porcentaje)
{
    this->precio = (this->precio * (100 + porcentaje)) / 100;
}

char *ProductoNacional::getCodigo() const
{
    return codigo;
}

float ProductoNacional::getPrecio()
{
    return precio;
}

char *ProductoNacional::setCodigo(const char *str)
{
    char * newString = new char[strlen(str)+1];
    strcpy(newString, str);
    return newString;
}
