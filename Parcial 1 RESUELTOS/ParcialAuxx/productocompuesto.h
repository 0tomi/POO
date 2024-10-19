#ifndef PRODUCTOCOMPUESTO_H
#define PRODUCTOCOMPUESTO_H
#include "prodinternacional.h"
class ProductoCompuesto: public ProductoNacional
{
public:
    ProductoCompuesto(const char * codigo, ProductoNacional * producto);
    ProductoCompuesto(const char * codigo): ProductoNacional(0.0, codigo){}

    void agregarProducto(ProductoNacional * newProducto);
    void ajustar(float porcentaje) override;
    float getPrecio() override;
private:
    ProductoNacional * productos[10];
    int indice;
};

#endif // PRODUCTOCOMPUESTO_H
