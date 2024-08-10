#ifndef PRODNACIONAL_H
#define PRODNACIONAL_H
#include <string.h>
class ProductoNacional
{
public:
    ProductoNacional(float precio, char * codigo);
    virtual void ajustar(float porcentaje = 10);

    char *getCodigo() const;
    virtual float getPrecio();
protected:
    char * codigo;
    float precio;
    char * setCodigo(const char * str);
};

#endif // PRODNACIONAL_H
