#ifndef PILAPUNTEROS_H
#define PILAPUNTEROS_H

// Como la pila anterior pero que el nodo tiene un puntero
template <class Insana>
class pilaPunteros
{
public:
    pilaPunteros();
    pilaPunteros(Insana * newLocura);
    pilaPunteros(const Insana &newLocura);
    void push(Insana * newDato);
    void push(const Insana &newDato);
    Insana * pop();
    int getSize() const;

private:
    struct nodo{
        Insana * dato;
        nodo * link;
    };
    nodo * frente;
    int size;
};

#endif // PILAPUNTEROS_H
