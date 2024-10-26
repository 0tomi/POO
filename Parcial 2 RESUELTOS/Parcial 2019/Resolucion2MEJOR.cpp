/*
    Resolucion 2 mejorada con tips del profe
*/

#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

struct Datos{
    char url[20];
    int permanencia;
    char origen;
};

class Visita{
protected:
    int permanencia; char origen;
public:
    Visita(Datos data): permanencia(data.permanencia), origen(data.origen) {}
    virtual int getPuntuacion() = 0;
    char getOrigen() {return origen;}
};

class Buscador: public Visita{
public:
    Buscador(Datos data):  Visita(data) {}
    int getPuntuacion() { return 10 * this->permanencia; }
};

class Directo: public Visita{
public:
    Directo(Datos data):  Visita(data) {}
    int getPuntuacion() { return 15 * this->permanencia; }
};

class Otro: public Visita{
public:
    Otro(Datos data):  Visita(data) {}
    int getPuntuacion() { return 1 * this->permanencia; }
};

class Web {
public:
    Web(string URL): url(URL) {}
    void addVisita(Visita* v) { visitas.push_back(v); } 
    string getURL() { return url; }
    vector<Visita*> getVisitas() { return visitas; }
    // Para consigna 2:
    int getPuntaje();
    // Para consigna 3:
    bool lookIfAccessed(char Tipo);
private:
    string url;
    vector<Visita*> visitas;
};

int Web::getPuntaje(){
    auto puntaje = reduce(visitas.begin(), visitas.end(), 0, [](int sumatoria, Visita* &v) 
    { return sumatoria + v->getPuntuacion();});
    return puntaje;
}

bool Web::lookIfAccessed(char tipo){
    bool accesed;
    accesed = any_of(visitas.begin(), visitas.end(), [tipo](Visita* v){
        return v->getOrigen() == tipo;
    });
    return accesed;
}

// Gestor:
// Nota: Lo ideal seria guardar las webs en un mapa<String,Web>, queda mas comodo asi.
class GestorWeb{
public:
    GestorWeb(const char * URLarchivo);
    Web getWeb(string url);
    // Consigna 2:
    void escribirPuntajes(const char* URLarchivo);
    // Consigna 3:
    vector<Web> getTop5();
    vector<Web> getSitiosWebIndexadosDirecto(); // esta podria retornar vector<string> nomas
private:
    vector<Web> webs;
};

GestorWeb::GestorWeb(const char* URLar){
    ifstream arch(URLar, ios::binary);
    Datos temp;
    map<string,vector<Datos>> mapalectura;
    while (arch.read((char*) &temp, sizeof(Datos))){
        string url = temp.url;
        mapalectura[url].push_back(temp);
    }
    arch.close();

    for (auto &aux: mapalectura){
        Web pagina(aux.first);
        for (auto &visita: aux.second){
            switch (visita.origen){
                case 'B': pagina.addVisita(new Buscador(visita));
                break;
                case 'D': pagina.addVisita(new Directo(visita));
                break;
                case 'O': pagina.addVisita(new Otro(visita));
                break;
            }
        }
        this->webs.push_back(pagina);
    }
}

Web GestorWeb::getWeb(string url){
    // Si no encuentra la web, se inventa una
    for (auto &web: webs)
        if (web.getURL() == url)
            return web;
    return Web(url);
}

// Consigna 2
void GestorWeb::escribirPuntajes(const char* URLar){
    ofstream archivo(URLar);
    if (archivo.fail())
        return;
    
    for (auto &web: webs){
        archivo << "url: " << web.getURL() << " puntaje: " << web.getPuntaje() << endl;
    }
    archivo.close();
}

// Consigna 3:
vector<Web> GestorWeb::getTop5(){
    sort(webs.begin(), webs.end(), [](Web &a, Web &b){ return a.getPuntaje() > b.getPuntaje(); });
    vector<Web> top5(webs.begin(), webs.begin() + 5);
    return top5;
}

vector<Web> GestorWeb::getSitiosWebIndexadosDirecto(){
    vector<Web> indexados;
    copy_if(webs.begin(), webs.end(), back_inserter(indexados), 
    [](Web &w){ return w.lookIfAccessed('D'); });
    return indexados;
}