#include "productooferta.h"


ProductoOferta::ProductoOferta(char * newCodigo): Productos(0.0, newCodigo)
{
    this->maxProductos = 2;
    this->productos = new Productos*[this->maxProductos];
    this->indice = 0;
}

void ProductoOferta::cargarProducto(Productos *newProducto)
{
    if (dynamic_cast<ProductoOferta*>(newProducto))
        return; // El producto es de tipo oferta, no puede ir.

    if (this->indice == this->maxProductos)
        modificarVector(this->maxProductos*2);

    this->productos[indice] = newProducto;
    indice++;
}

void ProductoOferta::eliminarProducto(char *buscarcodigo)
{
    for (int i = 0; i < this->maxProductos; i++)
        if (strcmp(this->codigo, buscarcodigo) == 0)
            eliminarProducto(i);
}

void ProductoOferta::eliminarProducto(int indice)
{
    Productos ** aux = new Productos*[this->maxProductos];
    int i = 0, j =0;
    while (j < this->maxProductos){
        if (i != indice){
            aux[i] = this->productos[j];
            i++;
        }
        j++;
    }
    delete[] this->productos;
    this->productos = aux;
    indice--;
}

float ProductoOferta::getPrecio()
{
    float precioActual = 0.0;
    for (int i = 0; i < this->maxProductos; i++)
        precio += this->productos[i]->getPrecio();

    // Descuento del 10%; 100 - 10 = 90.
    return (precio * 90) / 100;
}

void ProductoOferta::modificarVector(int max)
{
    Productos ** aux = this->productos;
    this->maxProductos = max;
    this->productos = new Productos*[this->maxProductos];
    for (int i = 0; i < this->maxProductos; i++)
        this->productos[i] = aux[i];
    delete[] aux;
}
