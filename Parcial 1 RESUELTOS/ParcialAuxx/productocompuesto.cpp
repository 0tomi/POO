#include "productocompuesto.h"

ProductoCompuesto::ProductoCompuesto(const char * codigo, ProductoNacional * producto):
    ProductoNacional(producto->getPrecio(), codigo)
{
    this->indice = 0;
    agregarProducto(producto);
}

void ProductoCompuesto::agregarProducto(ProductoNacional *newProducto)
{
    if (indice == 10)
        return; // para no meter mas de 10 productos
    if (dynamic_cast<ProductoCompuesto*>(newProducto))
        return; // para no meter productos compuestos
    this->productos[indice++] = newProducto;
}

void ProductoCompuesto::ajustar(float porcentaje)
{
    for (int i = 0; i < indice; i++)
        if (dynamic_cast<ProductoInternacional*>(productos[i]))
            productos[i]->ajustar(porcentaje);
        else
            productos[i]->ajustar();
}

float ProductoCompuesto::getPrecio()
{
    this->precio = 0.0;
    for (int i = 0; i < indice; i++)
        this->precio += this->productos[i]->getPrecio();
    return this->precio;
}
