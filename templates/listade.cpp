#ifndef LISTADE_CPP
#define LISTADE_CPP
#include "listade.h"

template<class T>
ListaDE<T>::ListaDE()
{
    frente = fondo = nullptr;
    this->size = 0;
}

template<class T>
ListaDE<T>::ListaDE(T dato)
{
    this->size = 0;
    insertar(dato);
}

template<class T>
void ListaDE<T>::insertar(T dato)
{
    if (size == 0){
        frente = fondo = new nodo{dato, 0};
        this->size = 1;
    } else {
        this->fondo->siguiente = new nodo{dato, this->size};
        this->fondo = this->fondo->siguiente;
        size++;
    }
}

template <class T>
int ListaDE<T>::getSize() const
{
    return this->size;
}

template<class T>
T& ListaDE<T>::operator[](int index)
{
    nodo * aux = frente;
    while (aux != nullptr)
        if (aux->index == index)
            return aux->dato;
    return T{};
}



#endif
