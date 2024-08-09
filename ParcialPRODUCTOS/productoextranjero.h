#ifndef PRODUCTOEXTRANJERO_H
#define PRODUCTOEXTRANJERO_H
#include "productos.h"
class ProductoExtranjero: public Productos
{
public:
    ProductoExtranjero(float precio, char * codigo): Productos(precio, codigo){};
    void actualizarPrecio(float cotizacionAnterior, float cotizacionActual);
};

#endif // PRODUCTOEXTRANJERO_H
