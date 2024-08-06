#ifndef PILA_H
#define PILA_H

template <class Locura>
class pila
{
public:
    pila();
    pila(Locura dato);
    void push(Locura newDato);
    Locura pop();
    int getSize() const;

private:
    struct nodo{
        Locura dato;
        nodo * link;
    };
    nodo * frente;
    int size;
};

#endif // PILA_H
