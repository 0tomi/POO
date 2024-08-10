#ifndef PRODUCTOCOMPUESTO_H
#define PRODUCTOCOMPUESTO_H
#include "prodinternacional.h"
class ProductoCompuesto: public ProductoNacional
{
public:
    ProductoCompuesto(char * codigo, ProductoNacional * producto);
    void agregarProducto(ProductoNacional * newProducto);
    void ajustar(float porcentaje) override;
    float getPrecio() override;
private:
    ProductoNacional * productos[10];
    int indice;
};

#endif // PRODUCTOCOMPUESTO_H
