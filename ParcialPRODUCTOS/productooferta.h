#ifndef PRODUCTOOFERTA_H
#define PRODUCTOOFERTA_H
#include "productos.h"

class ProductoOferta: public Productos
{
public:
    ProductoOferta(char * codigo);
    void cargarProducto(Productos * newProducto);
    void eliminarProducto(char * codigo);
    float getPrecio() override;

private:
    Productos ** productos;
    int maxProductos;
    int indice;
    void modificarVector(int max);
    void eliminarProducto(int indice);
};

#endif // PRODUCTOOFERTA_H
