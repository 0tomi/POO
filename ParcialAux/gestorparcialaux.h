#ifndef GESTORPARCIALAUX_H
#define GESTORPARCIALAUX_H
#include "productocompuesto.h"
class GestorParcialAux
{
public:
    GestorParcialAux();
    void agregarProducto(ProductoNacional * newProducto);
    void ajustarProductos(float ajuste);
    ProductoNacional * getProducto(int indice);
private:
    ProductoNacional * productos[50];
    int maxProductos;
};

#endif // GESTORPARCIALAUX_H
