#ifndef LISTADE_H
#define LISTADE_H

// Lista Doblemente Enlazada
template <class T>
class ListaDE
{
public:
    ListaDE();
    ListaDE(T dato);
    ~ListaDE();

    void insertar(T dato);
    bool eliminar(T dato);
    void obtener(T dato);
    int getSize() const;

    T operator[](int index);

private:
    struct nodo{
        T dato;
        int index;
        nodo * siguiente = nullptr;
        nodo * anterior = nullptr;
    };

    nodo * frente;
    nodo * fondo;
    int size;

    void deleteNodo(nodo * nodo2eliminar);
};

#endif // LISTADE_H
