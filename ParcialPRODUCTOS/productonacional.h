#ifndef PRODUCTONACIONAL_H
#define PRODUCTONACIONAL_H
#include "productos.h"

class ProductoNacional: public Productos
{
public:
    ProductoNacional(float precio, char * codigo);
    void actualizarPrecio(float porcentaje);
};

#endif // PRODUCTONACIONAL_H
