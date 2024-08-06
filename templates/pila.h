#ifndef PILA_H
#define PILA_H
template <class Locura>
class Pila{
public:
    Pila();
    Pila (Locura dato);
    void push(Locura newDato);
    Locura pop();
    int getSize();
    
private:
    struct nodo{
        Locura dato;
        nodo * link;
    };
    nodo * frente = nullptr;
    int size;
};

template<class Locura>
Pila<Locura>::Pila()
{
    
}


#endif