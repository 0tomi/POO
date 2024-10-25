#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <string>

using namespace std;

struct Alumnos{
    int legajo; char nombre[300]; char tipo;
};

struct Notas {
    int legajo, nota;
};

class Alumno
{
protected:
    vector <int> notas; // Podria ser una clase Notas
    int legajo;
    string nombre;
public:
    // Metodos y constructor para cargar el alumno:
    Alumno(int legajo_, char nombre_[]): legajo(legajo_), nombre(nombre_) {}
    void addNota(int nota) { notas.push_back(nota); }
    // Metodos para saber si aprobo el alumno
    float getPromedio();
    virtual bool aprueba() = 0;
    // Metodo para la consigna 3
    int getCantidadNotas() { notas.size(); }
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

