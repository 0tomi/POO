#include "prodinternacional.h"

ProductoInternacional::ProductoInternacional(float precio, const char * codigo):
    ProductoNacional(precio,  codigo) {}

void ProductoInternacional::ajustar(float porcentaje)
{
    ProductoNacional::ajustar(porcentaje);
}
