#include "productoextranjero.h"

void ProductoExtranjero::actualizarPrecio(float cotizacionAnterior, float cotizacionActual)
{
    this->precio = (this->precio/cotizacionAnterior) * cotizacionActual;
}


