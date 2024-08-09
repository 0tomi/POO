#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include <string.h>

class Productos
{
public:
    Productos(float precio, char * codigo);
    virtual float getPrecio() = 0;
private:
    float precio;
    char * codigo;
    // Funcion para obtener un nuevo string xq usamos CString (zzz)
    char * setNewString(const char * base);
};

#endif // PRODUCTOS_H
