#ifndef PRODUCTONACIONAL_H
#define PRODUCTONACIONAL_H
#include "productos.h"

class ProductoNacional: public Productos
{
public:
    ProductoNacional(float newPrecio, char * codigo);
};

#endif // PRODUCTONACIONAL_H
