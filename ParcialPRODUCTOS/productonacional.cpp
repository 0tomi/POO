#include "productonacional.h"

ProductoNacional::ProductoNacional(float newPrecio, char *codigo):
    Productos(newPrecio, codigo){}

void ProductoNacional::actualizarPrecio(float porcentaje)
{
    this->precio = (this->precio * (100+porcentaje)) / 100;
}
