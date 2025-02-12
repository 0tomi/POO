#ifndef PRODUCTOINTERNACIONAL_H
#define PRODUCTOINTERNACIONAL_H
#include "prodNacional.h"
class ProductoInternacional: public ProductoNacional
{
public:
    ProductoInternacional(float precio, const char * codigo);
    void ajustar(float porcentaje) override;
};

#endif // PRODUCTOINTERNACIONAL_H
