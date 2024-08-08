#ifndef PILA_CPP
#define PILA_CPP
#include "pila.h"
template<class Locura>
// El parentesis es el numero con el cual inicializamos el dato
pila<Locura>::pila(): size(0), frente(nullptr) {}

template<class Locura>
pila<Locura>::pila(Locura dato)
{
    // Usamos las llaves para meter los datos directamente.
    this->frente = new nodo{dato, nullptr};
    this->size = 1;
}

template<class Locura>
pila<Locura>::~pila()
{
    while(this->size)
        this->pop();
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
        return Locura{};
        //std::cout << "Pila vacia";

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

template<class Locura>
pila<Locura> &pila<Locura>::operator+(const Locura &newData)
{
    this->push(newData);
    return *this;
}

template <class LocuraExtreme>
ostream& operator<<(ostream& os, const pila<LocuraExtreme>& p)
{
    os << "Tamanio de la pila: " << p.size;
    return os;
}

#endif
