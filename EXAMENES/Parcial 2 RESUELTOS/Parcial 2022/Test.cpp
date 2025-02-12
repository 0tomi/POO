#include "Resolucion.cpp"

int main(int argc, char const *argv[])
{
    ListaCircular<int> lista;
    lista.insert(1);
    lista.insert(3);
    lista.insert(5);
    cout << lista.get(2);
    return 0;
}
