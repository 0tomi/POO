#include <algorithm>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

struct DatosEjemplar{
    int identificacion_libro;
    int isbn;
    int anio_impresion;
    char editorial[50];
};

struct DatosLibro{
    int identificacion;
    char nombre[50];
    char autor[50];
};

class Ejemplar{
public:
    Ejemplar(DatosEjemplar datos): isbn(datos.isbn), 
    anio_impresion(datos.anio_impresion), editorial(datos.editorial) {}
    DatosEjemplar getDatos();
    string getEditorial() { return editorial; }
private:
    int isbn, anio_impresion;
    string editorial;
};

DatosEjemplar Ejemplar::getDatos(){
    DatosEjemplar datos {0, this->isbn, this->anio_impresion};
    this->editorial.copy(datos.editorial, 50);
    return datos;
}

class Libro
{
private:
    int identificacion;
    string nombre, autor;
    vector<Ejemplar> ejemplares;
public:
    Libro(DatosLibro libro);
    void addEjemplar(Ejemplar);
    vector<DatosEjemplar> getDatosEjemplares();
    DatosLibro getDatos();
    int getCantidadEjemplares() { return ejemplares.size(); }
    bool impresoPorDiferentesEditoriales();
    map<string, int> getCantidadEjemplaresPorEditorial();
};

Libro::Libro(DatosLibro libro): identificacion(libro.identificacion), 
nombre(libro.nombre), autor(libro.autor) {}

void Libro::addEjemplar(Ejemplar ej){ ejemplares.push_back(ej); }

vector<DatosEjemplar> Libro::getDatosEjemplares()
{
    vector<DatosEjemplar> datos;
    datos.reserve(ejemplares.size());
    for (auto &ejemplar: ejemplares)
        datos.push_back(ejemplar.getDatos());
    return datos;
}   

DatosLibro Libro::getDatos()
{
    DatosLibro datos{this->identificacion};
    this->autor.copy(datos.autor, 50);
    this->nombre.copy(datos.nombre, 50);
    return datos;
}

bool Libro::impresoPorDiferentesEditoriales(){
    string primerEditorial = ejemplares[0].getEditorial();
    bool masDeUnEditorial = any_of(ejemplares.begin(), ejemplares.end(), 
    [primerEditorial](Ejemplar &a){ return primerEditorial != a.getEditorial(); });
    return masDeUnEditorial;
}

map<string, int> Libro::getCantidadEjemplaresPorEditorial(){
    map<string, int> editoriales;
    
}