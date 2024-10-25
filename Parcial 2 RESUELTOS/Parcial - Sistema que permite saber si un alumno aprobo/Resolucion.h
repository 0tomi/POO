#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <string>

using namespace std;

struct DatoAlumno{
    int legajo; char nombre[300]; char tipo;
};

struct DatoNota {
    int legajo, nota;
};

class Alumno
{
protected:
    vector <int> notas; // Podria ser una clase Notas
    int legaj;
    string nombr;
public:
    // Metodos y constructor para cargar el alumno:
    Alumno(int legajo_, char nombre_[]): legaj(legajo_), nombr(nombre_) {}
    void addNota(int nota) { notas.push_back(nota); }
    // Metodos para saber si aprobo el alumno
    float getPromedio();
    virtual bool aprueba() = 0;
    // Metodo para la consigna 3
    int getCantidadNotas() { return notas.size(); }
    int legajo() { return legaj; }
    string nombre() { return nombr; }
};

float Alumno::getPromedio(){
    float promedio = reduce(notas.begin(), notas.end(), 0.0);
    return promedio / notas.size();
}

class Regular: public Alumno
{
public:
    Regular(int legajo_, char nombre_[]): Alumno(legajo_, nombre_) {}
    bool aprueba();
};

bool Regular::aprueba(){
    if (getPromedio() < 60)
    return false;

    for (auto nota: notas)
        if (nota < 55)
            return false;

    return true;
} 

class Libre: public Alumno
{
public:
    Libre(int legajo, char nombre[]): Alumno(legajo, nombre) {}
    bool aprueba();
};

bool Libre::aprueba(){
    return (notas.back() < 70) ? false: true;
}

class Curso{
private: 
    map<int, Alumno*> alumnos;  // Legajo, alumno
public:
    // Consigna 1
    Curso(const char * URLAlumnos, const char * URLNotas);
    Alumno* getAlumno(int legajo);
    // Consigna 2
    void makeTxt(const char * URL);
    // Consigna 3:
    vector<Alumno*> Actividad3a();
    pair<float, float> Actividad3b();
    vector<Alumno*> Actividad3c();
};

Curso::Curso(const char * URLAlumnos, const char * URLNotas){
    ifstream arch_alumnos(URLAlumnos, ios::binary), arch_notas(URLNotas, ios::binary);
    if (arch_alumnos.fail() || arch_notas.fail())
        return;

    DatoAlumno temp; DatoNota temp2; 
    while (arch_alumnos.read((char*) &temp, sizeof(DatoAlumno))){
        switch (temp.tipo) {
            case 'R': alumnos[temp.legajo] = new Regular(temp.legajo, temp.nombre);
            break;
            case 'L': alumnos[temp.legajo] = new Libre(temp.legajo, temp.nombre);
            break;
        }
    }

    while (arch_notas.read((char*) &temp2, sizeof(DatoNota)))
        alumnos[temp2.legajo]->addNota(temp2.nota);

    arch_notas.close(); arch_alumnos.close();
}

Alumno* Curso::getAlumno(int legajo){
    // Si se inventa un alumno por no encontrarlo
    // el alumno llegaria como nullptr.
    return alumnos[legajo];
}

void Curso::makeTxt(const char * URL){
    ofstream arch(URL);
    if (arch.fail()) return;
    string veredict[] = {"Aprobó", "No aprobó"};
    for (auto alumno: alumnos){
        int indice = 1; 
        if (alumno.second->aprueba())
            indice = 0;
        arch << "Nombre: " << alumno.second->nombre() << ". " << veredict[indice] << endl;
    }   
    arch.close();
}

vector<Alumno*> Curso::Actividad3a(){
    vector<Alumno*> temp;
    // esto que voy a hacer con un for queda 13092093209 veces mas corto y mejor pero
    // hay que usar stl...
    transform(alumnos.begin(), alumnos.end(), back_inserter(temp), 
    [](const pair <int, Alumno*> &par) { return par.second; });

    sort(temp.begin(), temp.end(), [](Alumno * a, Alumno * b){
        return a->getPromedio() > b->getPromedio();
    });

    vector<Alumno*> alumnosProm;    // esto se puede hacer con un copyif
    int maxProm = temp[0]->getPromedio();
    copy_if(temp.begin(), temp.end(), back_inserter(alumnosProm),
    [maxProm](Alumno* a){ return a->getPromedio() == maxProm; });

    return alumnosProm;
}

pair<float, float> Curso::Actividad3b(){
    pair<float,float> aprobado_desaprobado;
    typedef pair<int, Alumno*> par; 
    // Estoy muy seguro de que con un foreach esto queda MUCHO mas corto.
    aprobado_desaprobado.first = reduce(alumnos.begin(), alumnos.end(), 0.0, 
    [](int acum, par a){ if (a.second->aprueba()) return  acum + a.second->getPromedio(); return acum + float(0.0); });
    aprobado_desaprobado.second = reduce(alumnos.begin(), alumnos.end(), 0.0, 
    [](int acum, par a){ if (!a.second->aprueba()) return  acum + a.second->getPromedio(); return acum + float(0.0); });

    return aprobado_desaprobado;
}
vector<Alumno*> Curso::Actividad3c(){
    // Hubiera sido mucho mejor hacer el parcial sin mapas, asi nos ahorramos esta linea
    // para pasar el mapa a un vector.
    vector<Alumno*> temp;
    transform(alumnos.begin(), alumnos.end(), back_inserter(temp), 
    [](const pair <int, Alumno*> &par) { return par.second; });

    typedef Alumno* al;
    sort(temp.begin(), temp.end(), [](al a, al b) { return a->getCantidadNotas() < b->getCantidadNotas(); });
   
    int min_notas = temp[0]->getCantidadNotas();
    // Buscamos cual alumno tiene una cantidad de notas que se sale del minimo
    auto it = find(temp.begin(), temp.end(), [min_notas](al a) { return a->getCantidadNotas() > min_notas; });
    // Devolvemos un vector de alumnos, copiando hasta el que se sale del minimo.
    return vector<Alumno*>(temp.begin(), it);
}
