#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

/*
    Resolucion de parcial de 2022
    El enfoque que voy a tomar para la consigna 1, es de gestionar
    todo usando un mapa, que contenga como clave la URL del sitio web
    y luego un vector con las clases que van a representar los datos 
    de las visitas.
*/

struct Datos{
    char url[20]; int permanencia; char origen;
};

class Visita{
public:
    Visita(Datos data);
    virtual long int getPuntuacion() = 0;
    char getOrigen();
protected:
    string url; int permanencia; char origen;
};

Visita::Visita(Datos data){
    this->url = data.url;
    this->permanencia = data.permanencia;
    this->origen = data.origen;
}

class Buscador: public Visita{
public:
    Buscador(Datos data): Visita(data) {}
    long int getPuntuacion();
};

long int Buscador::getPuntuacion(){
    return 10 * this->permanencia;
}

class Directo: public Visita{
public:
    Directo(Datos data): Visita(data) {}
    long int getPuntuacion();
};

long int Directo::getPuntuacion(){
    return 15 * this->permanencia;
}

class Otro: public Visita{
public:
    Otro(Datos data): Visita(data) {}
    long int getPuntuacion();
};

long int Otro::getPuntuacion(){
    // seria lo mismo que retornar directamente la permanencia
    return 1 * this->permanencia;
}

// Clase gestora:
class Gestor{
private:
    map<string, vector<Visita>> URLs;
public:
    Gestor(const char * URLArchivo);
    vector <Visita> getVisitas(string URL);
    long int getPuntaje(string URL);

    // Consigna 3:
    map<string, vector <Visita>> getTop5();
    // Aca podria ser un vector de string, o retornar un mapa como la anterior
    vector <string> getSitiosWebDirectos();
};

