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


