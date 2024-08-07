#include "pilapunteros.h"
template<class Insana>
pilaPunteros<Insana>::pilaPunteros(): size(0), frente(nullptr){}

template<class Insana>
pilaPunteros<Insana>::pilaPunteros(Insana * newLocura)
{
    this->frente = new nodo{newLocura, nullptr};
    this->size = 1;
}

template<class Insana>
pilaPunteros<Insana>::pilaPunteros(const Insana &newLocura)
{
    Insana * aux = new Insana;
    *aux = newLocura;

    this->frente = new nodo{aux, nullptr};
    this->size = 1;
}

template<class Insana>
void pilaPunteros<Insana>::push(Insana *newDato)
{
    nodo * aux = new nodo{newDato, frente};
    frente = aux;
    size++;
}

template<class Insana>
void pilaPunteros<Insana>::push(const Insana &newDato)
{
    Insana * auxDato = new Insana;
    *auxDato = newDato;

    nodo * auxNodo = new nodo{auxDato, frente};
    frente = auxNodo;
    size++;
}

template<class Insana>
Insana *pilaPunteros<Insana>::pop()
{
    nodo * aux = this->frente;
    this->frente = this->frente->link;
    Insana * dato2return = aux->dato;
    delete aux;
    size--;
    return dato2return;
}

template<class Insana>
int pilaPunteros<Insana>::getSize() const
{
    return size;
}
