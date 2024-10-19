/*
    Resolucion del parcial de 2022
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numbers>
#include <fstream>

using namespace std;

// Primer consigna:
struct DatosBienes{
    int codigo;
    char tipo;
    double valor;
};

// Superclase abstracta
class Bienes {
public:
    Bienes(int cod, char tip, double val): codigo(cod), tipo(tip), valor(val) {}
    Bienes(DatosBienes datos): codigo(datos.codigo), tipo(datos.tipo), valor(datos.valor) {}
    int getCodigo() {return codigo;}
    char getTipo() {return tipo;}
    double getValor() {return valor;}
    virtual void amortizar() = 0;

protected:
    int codigo;
    char tipo;
    double valor;
};

// Clases hijas
// Lo ideal seria usar el constructor con el struct, para escribir menos.
// Osea que es al pedo el constructor con los datos por separado.
class Terrenos: public Bienes{
public:
    // Inicializamos el constructor de la clase padre con el :, de esta forma
    // no hay que programar el constructor de cada clase hija.
    Terrenos(int Codigo, char Tipo, double Valor): Bienes(Codigo, Tipo, Valor) {}
    Terrenos(DatosBienes datos): Bienes(datos) {}
    // Terrenos no amortiza asi que no hacemos nada.
    void amortizar() {};
};

class Comunes: public Bienes{
public:
    Comunes(int Codigo, char Tipo, double Valor): Bienes(Codigo, Tipo, Valor) {}
    Comunes(DatosBienes datos): Bienes(datos) {}
    void amortizar();
};

class Muebles: public Bienes{
public:
    Muebles(int Codigo, char Tipo, double Valor): Bienes(Codigo, Tipo, Valor) {}
    Muebles(DatosBienes datos): Bienes(datos) {}
    void amortizar();
};

// Metodos de las clases hijas
void Comunes::amortizar() {
    this->valor *= 0.95;    // Le restamos el 5%
}

void Muebles::amortizar(){
    if (this->valor < 10000)
        this->valor *= 0.98; // Le restamos el 2%
    else this->valor *= 0.978; // Le restamos el 2.2%
}

// Gestor
// Usaremos el gestor para leer los datos y asi inicializar las clases
// Ademas de gestionarlas obviamente.
class GestorBienes{
public:
    GestorBienes(const char* RutaArchivo);
    Bienes* getBien(int pos);
    void amortizarBienes();
    // Para la consigna 2:
    void crearArchivo(const char* RutaArchivo);
    // Para la consigna 3:
    vector<Bienes*> getBienesMayorValor();
    // Para el punto 3b vamos a usar un mapa, aunque calculo que con un struct que contenga
    // el tipo y el valor ya puede funcionar para el profe.
    map<char, double> getTotalPorTipo();
private:
    vector<Bienes*> bienes;
};

/*
    Para el tema de leer los archivos hay 2 formas.
    La eficiente y la ineficiente, la diferencia 
    entre una y otra, son la cantidad de lineas que
    toman en escribirse, pero ambas son igual de faciles de 
    hacer. En el parcial yo recomendaria la ineficiente, ya que
    la idea es no perder tiempo. La parte eficiente estara marcada 
    como EFICIENTE, para que vean que se pueden saltear.
*/ 
GestorBienes::GestorBienes(const char* Ruta){
    ifstream archivo (Ruta, ios::binary | ios::ate); // La parte de ate es para EFICIENTE.

    if (archivo.fail())  // Obligatorio
        return;          // Si el archivo falla en abrirse terminamos la funcion.

    long tamanio = archivo.tellg(); // EFIICENTE
    tamanio /= sizeof(DatosBienes); // EFICIENTE
    archivo.seekg(0, ios::beg); // EFICIENTE
    this->bienes.reserve(tamanio); // EFICIENTE

    /*
        El chiste de lo que vieron hasta aca es obtener el tamanio total del archivo, y 
        dividirlo por el espacio que ocupa nuestro struct con datos, asi obtenemos
        el total de datos que se leeran del archivo. Seekg sirve para poner el puntero
        al principio del archivo devuelta asi lo podemos leer correctamente.
        Reserve hace que el vector reserve la cantidad de memoria necesaria para guardar
        todo, haciendo push_back mucho mas eficiente.
        Sin embargo como ven, son varias lineas de codigo que tranquilamente se pueden
        ahorrar porque capaz no da tiempo en el parcial.
    */

    DatosBienes aux;
    // Como es una variable, hace falta poner el &
    while( archivo.read((char*) &aux, sizeof(DatosBienes)) ){
        // Como pueden ver, el unico constructor que usamos es el del struct, es mas eficiente.
        // Basicamente leemos de el archivo un struct, y nos fijamos segun el tipo que clase crear.
        switch (aux.tipo){
            case 'T': bienes.push_back(new Terrenos(aux));
            break;
            case 'C': bienes.push_back(new Comunes(aux));
            break;
            case 'M': bienes.push_back(new Muebles(aux));
            break;
        }
    }

}

void GestorBienes::amortizarBienes(){
    for (auto &bien: bienes)
        bien->amortizar();
}

// Hasta aca la consigna 1, parece mucho pero es casi todo comentarios
// y como lo aclare, hay varias cosas que se pueden quitar para no tener que 
// escribir tanto. Ahora vamos con la 2:

vector <Bienes*> GestorBienes::getBienesMayorValor(){
    /* 
        Usamos sort de <algorithm>, que nos permite ordenar el vector
        automaticamente. Pero la consigna nos pide obtener las cosas con mayor valor,
        sort por default ordena de menor a mayor, asi que con este lambda (funcion sin nombre)
        no solo le decimos que ordene de mayor a menor, si no que tambien ordene basandose en
        el valor del objeto.
    */
    sort(bienes.begin(), bienes.end(), [](Bienes* a, Bienes* b) {
        return (a->getValor()) > (b->getValor());
    });

    vector<Bienes*> bienesMayorValor;
    double mayorValor = bienes[0]->getValor();
    /*
        Usaremos copyif, que copia bajo una condicion, le pasamos primero donde arranca
        y donde termina el vector de bienes, y le decimos que vaya insertando
        los bienes en bienesMayorValor, solo si el valor del bien equivale al mayor.
        mayorValor lo ponemos dentro del corchete porque es una variable de afuera, de
        esta forma la metemos dentro del lambda.
        Bienes* bien es lo que recibe la funcion yq ue usamos para obtneer su valor.
    */
    copy_if(bienes.begin(), bienes.end(), back_inserter(bienesMayorValor), [mayorValor](Bienes* bien){
        return bien->getValor() == mayorValor;
    });
}

/*
    Aprovechamos la caracteristica de que los mapas si no tienen un dato se lo inventan
    para directamente inicializar los datos que queremos.
    Luego recorremos el vector de bienes, y segun el tipo, que lo buscamos en el mapa,
    le vamos aumentando el valor.
*/
map<char, double> GestorBienes::getTotalPorTipo(){
    map<char, double> totalBienes;
    totalBienes['T'] = 0.0;
    totalBienes['C'] = 0.0;
    totalBienes['M'] = 0.0;

    for (auto &bien: bienes)
        totalBienes[bien->getTipo()] += bien->getValor();

    return totalBienes;
}

// Consigna 4:
template <class T>
class ListaCircular{
private:
struct Nodo{
    T dato;
    Nodo * link;
    Nodo * back;
}
Nodo * first;
Nodo * last;

public:
    ListaCircular(): first(nullptr), last(nullptr) {}
    ListaCircular(T dato): first(new Nodo{first, T}), last(first) {}
    void insert(T dato);
    T get(int pos);
};

template <class T>
void ListaCircular<T>::insert(T dato){
    if (first == nullptr){
        first = new Nodo{first, T};
        return;
    }
}