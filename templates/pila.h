#ifndef PILA_H
#define PILA_H
#include <iostream>
using namespace std;

template <class Locura>
class pila
{
public:
    pila();
    pila(Locura dato);
    ~pila();
    void push(Locura newDato);
    Locura pop();
    int getSize() const;
    // Test de sobrecarga de operadores
    template <class LocuraExtreme>
    friend ostream& operator<<(ostream& os, const pila<LocuraExtreme>& p);

    pila<Locura>& operator+(Locura const& newData);

private:
    struct nodo{
        Locura dato;
        nodo * link;
    };
    nodo * frente;
    int size;
};

#endif // PILA_H
