#ifndef LISTADE_H
#define LISTADE_H

// Lista Doblemente Enlazada
template <class T>
class ListaDE
{
public:
    ListaDE();
    ~ListaDE();

    void insertar();
    bool eliminar(T dato);
    void obtener(T dato);
    unsigned int getSize() const;

private:
    struct nodo{
        T dato;
        nodo * link = nullptr;
    };

    nodo * frente;
    nodo * fondo;
    unsigned int size;
};

#endif // LISTADE_H
