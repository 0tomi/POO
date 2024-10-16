#include <iostream>
#include "LeerArchivoBinario.h"

struct EstructuraTest{
    char nombre[35];
    float altura;
    int edad;
    bool validez;
};

int main(int argc, char const *argv[])
{
    auto Prueba = read<EstructuraTest>("archivoBinario.dat");
    cout << Prueba[0].nombre;
    return 0;
}
