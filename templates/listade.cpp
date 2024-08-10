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
ListaDE<T>::~ListaDE()
{
    if (frente) {
        nodo * aux = frente;
        nodo * aux2 = aux;
        while (aux){
            aux2 = aux->siguiente;
            delete aux;
            aux = aux2;
        }
    }
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

template<class T>
bool ListaDE<T>::eliminar(T _dato)
{
    nodo * aux = frente;
    while (aux != nullptr)
        if (aux->dato == _dato){
            deleteNodo(aux);
            return true;
        }
    return false;
}

template<class T>
void ListaDE<T>::deleteNodo(nodo *nodo2eliminar)
{
    nodo * aux = nodo2eliminar->siguiente;
    while (aux){
        aux->index--;
        aux = aux->siguiente;
    }

    if (aux->anterior)
        aux->anterior->siguiente = aux->siguiente;
    if (aux->siguiente)
        aux->siguiente->anterior = aux->anterior;

    delete aux;
    this->size--;
}

template <class T>
int ListaDE<T>::getSize() const
{
    return this->size;
}

template<class T>
T ListaDE<T>::operator[](int index)
{
    nodo * aux = frente;
    while (aux != nullptr)
        if (aux->index == index)
            return aux->dato;
    return T{};
}

#endif
