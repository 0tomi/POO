#ifndef PRODNACIONAL_H
#define PRODNACIONAL_H
#include <string.h>
#include <iostream>
class ProductoNacional
{
public:
    ProductoNacional(float precio, const char * nombre);
    virtual void ajustar(float porcentaje = 10);

    char *getCodigo() const;
    virtual float getPrecio();
    friend std::ostream& operator<<(std::ostream& os, ProductoNacional& obj){
        os << "Codigo: " << obj.getCodigo() << " Precio:" << obj.getPrecio();
        return os;
    }
protected:
    char * nombre;
    char * codConsigna;
    float precio;
    char * setNombre(const char * str);
    char * getCodigoConsigna(const char * codigo);
};

#endif // PRODNACIONAL_H
