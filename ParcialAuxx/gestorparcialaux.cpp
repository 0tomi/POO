#include "gestorparcialaux.h"

GestorParcialAux::GestorParcialAux(): maxProductos(0) {}

void GestorParcialAux::agregarProducto(ProductoNacional *newProducto)
{
    if (this->maxProductos == 50)
        return;     // si se excede no hace nada
    this->productos[maxProductos] = newProducto;
    this->maxProductos++;
}

void GestorParcialAux::ajustarProductos(float ajuste)
{
    for (int i = 0; i < this->maxProductos; i++)
        if (dynamic_cast<ProductoInternacional*>(productos[i]) or dynamic_cast<ProductoCompuesto*>(productos[i]))
            this->productos[i]->ajustar(ajuste);
        else this->productos[i]->ajustar();
}

ProductoNacional *GestorParcialAux::getProducto(int indice)
{
    return (indice < this->maxProductos)? this->productos[indice]: nullptr;
}
