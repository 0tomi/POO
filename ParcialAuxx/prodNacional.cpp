#include "prodNacional.h"
ProductoNacional::ProductoNacional(float newPrecio, const char * newCode)
{
    this->precio = newPrecio;
    this->nombre = this->setNombre(newCode);
    this->codConsigna = this->getCodigoConsigna(this->nombre);
}

void ProductoNacional::ajustar(float porcentaje)
{
    this->precio = (this->precio * (100 + porcentaje)) / 100;
}

char *ProductoNacional::getCodigo() const
{
    return this->codConsigna;
}

float ProductoNacional::getPrecio()
{
    return precio;
}

char *ProductoNacional::setNombre(const char *str)
{
    char * newString = new char[strlen(str)+1];
    strcpy(newString, str);
    return newString;
}

char *ProductoNacional::getCodigoConsigna(const char *nombre)
{
    char * code = new char[4];
    int tamanioCodigo = strlen(nombre); // Por si el nombre tiene menos de 3 letras
    for (int i = 0; (i < 3) && (i < tamanioCodigo); i++)
        code[i] = tolower(nombre[i]);
    code[3] = 0;    // Caracter de final de cadena
    return code;
}
