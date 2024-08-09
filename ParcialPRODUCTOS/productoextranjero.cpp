#include "productoextranjero.h"

ProductoExtranjero::ProductoExtranjero(float precio, char *codigo): Productos(precio, codigo)
{

}

float ProductoExtranjero::getPrecio()
{
    return this->precio;
}

void ProductoExtranjero::actualizarPrecio(float cotizacionAnterior, float cotizacionActual)
{
    this->precio = (this->precio/cotizacionAnterior) * cotizacionActual;
}


