#include <iostream>
#include "gestorparcialaux.h"

using namespace std;

int main()
{
    GestorParcialAux gestor;
    char locura[] = "popo";
    gestor.agregarProducto(new ProductoNacional(200.0, locura));
    gestor.agregarProducto(new ProductoNacional(100.0, "Hola")); //$110 post ajuste
    gestor.agregarProducto(new ProductoInternacional(150.0, "Pesticida")); //$180 post ajuste

    ProductoCompuesto test("OfertaLocura", new ProductoNacional(51.99, "Koala"));
    test.agregarProducto(new ProductoInternacional(150.0, "Prueba"));

    gestor.agregarProducto(&test);
    gestor.ajustarProductos(20.0);

    cout << gestor;

    return 0;
}
