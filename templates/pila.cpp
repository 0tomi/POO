#include "pila.h"
#include <iostream>

template<class Locura>
// El parentesis es el numero con el cual inicializamos el dato
pila<Locura>::pila(): size(0), frente(nullptr)
{

}

template<class Locura>
pila<Locura>::pila(Locura dato)
{
    // Usamos las llaves para meter los datos directamente.
    this->frente = new nodo{dato, nullptr};
    this->size = 1;
}

template<class Locura>
void pila<Locura>::push(Locura newDato)
{
    nodo * aux = new nodo{newDato, frente};
    frente = aux;
    size++;
}

template<class Locura>
Locura pila<Locura>::pop()
{
    // Si la pila esta vacia no deberia retornar nada, pero como esta armado sin punteros
    // directamente no tengo idea que se retorna (sin usar throw)
    if (size == 0)
        std::cout << "Pila vacia";

    nodo * aux = frente;
    frente = frente->link;
    Locura dato2retornar = aux->dato;
    delete aux; size--;

    return dato2retornar;
}

template<class Locura>
int pila<Locura>::getSize() const
{
    return size;
}


