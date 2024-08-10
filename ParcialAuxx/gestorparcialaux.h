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

    friend std::ostream& operator<< (std::ostream& os, GestorParcialAux& gp){
        double totalMonto = 0;
        for (int i = 0; i < gp.maxProductos; i++){
            os << *(gp.productos[i]) << std::endl;
            totalMonto += gp.productos[i]->getPrecio();
        }
        os << "Monto total de productos: " << totalMonto << std::endl;
        return os;
    }
private:
    ProductoNacional * productos[50];
    int maxProductos;
};

#endif // GESTORPARCIALAUX_H
