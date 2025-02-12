#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <string>
#include <fstream>

using namespace std;

/*
    Resolucion de parcial de 2019
    El enfoque que voy a tomar para la consigna 1, es de gestionar
    todo usando un mapa, que contenga como clave la URL del sitio web
    y luego un vector con las clases que van a representar los datos 
    de las visitas.
    
    Este parcial es bastante similar al de 2022 asi que no tendra tantas explicaciones.
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
    map<string, vector<Visita*>> URLs;
public:
    Gestor(const char * URLArchivo);
    vector <Visita*> getVisitas(string URL);
    long int getPuntaje(string URL);

    // Consigna 3:
    vector <pair<string, long int>> getTop5();
    // Aca podria ser un vector de string, o retornar un mapa como la anterior
    vector <string> getSitiosWebDirectos();
};

Gestor::Gestor(const char * URL){
    ifstream archivo(URL, ios::binary);
    if (archivo.fail())
        return;

    Datos aux; string link; 
    while (archivo.read((char*) &aux, sizeof(Datos))){
        switch (aux.origen) {
            link = aux.url;
            case 'B': URLs[link].push_back(new Buscador(aux));
            break;
            case 'D': URLs[link].push_back(new Directo(aux));
            break;
            case 'O': URLs[link].push_back(new Otro(aux));
            break;
        }
    }
    archivo.close();
}

vector <Visita*>  Gestor::getVisitas(string URL){
    return URLs[URL];
}

long int Gestor::getPuntaje(string URL){
    auto buscar = URLs.find(URL);
    if (buscar == URLs.end())
        return 0;

    auto &vector = URLs[URL];
    long int puntaje = reduce(vector.begin(), vector.end(), 0);
    return puntaje;
}

vector <pair<string, long int>> Gestor::getTop5(){
    vector <pair<string, long int>> sites;
    for (auto &visitas: URLs)
        sites.push_back(pair(visitas.first, reduce(visitas.second.begin(), visitas.second.end(), 0))); 
    
    sort(sites.begin(), sites.end(), 
    [](pair<string, long int> Sitio1, pair<string, long int> Sitio2) {
        return Sitio1.second > Sitio2.second;
    }); 

    sites.resize(5);
    sites.shrink_to_fit();
    return sites;
}

vector <string> Gestor::getSitiosWebDirectos(){
    vector<string> Sitios;
    for (auto &sitio: URLs){
        bool Directo = any_of(sitio.second.begin(), sitio.second.end(), 
        [](Visita * visita){ return 'D' == visita->getOrigen(); });

        if (Directo)
            Sitios.push_back(sitio.first);
    }

    return Sitios;
}

class Vector {
    
};