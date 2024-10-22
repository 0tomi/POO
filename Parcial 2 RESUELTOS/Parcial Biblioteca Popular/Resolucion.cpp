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
    string getNombre() { return nombre; }
};

Libro::Libro(DatosLibro libro): identificacion(libro.identificacion), 
nombre(libro.nombre), autor(libro.autor) {}

void Libro::addEjemplar(Ejemplar ej){ ejemplares.push_back(ej); }

vector<DatosEjemplar> Libro::getDatosEjemplares()
{
    vector<DatosEjemplar> datos;
    datos.reserve(ejemplares.size());
    for (auto &ejemplar: ejemplares){
        auto dato = ejemplar.getDatos();
        dato.identificacion_libro = this->identificacion;
        datos.push_back(dato);
    }
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
    for (auto &ejemplar: ejemplares)
        editoriales[ejemplar.getEditorial()]++;
    return editoriales;
}

class Biblioteca
{
private:
    vector<Libro> libros;
public:
    Biblioteca();
    void addLibro(Libro lib) { libros.push_back(lib); }
    void guardarDatos(const char * URLLibros, const char * URLEjemplares);
    void consultarEjemplares(string nombreLibro, const char * direccionTxt);
    vector<string> getLibroMayorCantidadEjemplares();
    string getEditorialConMasEjemplares();
};

Biblioteca::Biblioteca() {}

void Biblioteca::guardarDatos(const char * URLLibros, const char * URLEjemplares){
    ofstream arch_libros(URLLibros, ios::binary);
    ofstream arch_ejem(URLEjemplares, ios::binary);

    if (arch_ejem.fail() || arch_libros.fail())
        return;

    for (auto &libro: libros){
        auto datos_libro = libro.getDatos();
        auto datos_ejemplares = libro.getDatosEjemplares();
        arch_libros.write((char*) &datos_libro, sizeof(DatosLibro));
        arch_ejem.write((char*) datos_ejemplares.data(), sizeof(DatosEjemplar) * datos_ejemplares.size());
    }
    arch_ejem.close(); arch_libros.close();
}

void Biblioteca::consultarEjemplares(string nombreLibro, const char * direccionTxt){
    ofstream arch(direccionTxt);
    if (arch.fail())
        return;

    auto libro = find(libros.begin(), libros.end(), [nombreLibro] (Libro &libro){
        return nombreLibro == libro.getNombre();
    });

    if (libro == libros.end())
        return;

    for (auto& ejemplar: libro->getDatosEjemplares()) {
        // esto deberia ir con espacios
        arch << ejemplar.identificacion_libro << ejemplar.editorial << ejemplar.isbn << ejemplar.anio_impresion  << endl;
    }
    arch.close();
}

vector<string> Biblioteca::getLibroMayorCantidadEjemplares(){
    sort(libros.begin(), libros.end(), [](Libro &a, Libro& b){
        return a.getCantidadEjemplares() > b.getCantidadEjemplares();
    });

    vector<string> librosmayor;
    int mayorCantidadEjemplares = libros[0].getCantidadEjemplares();
    for (auto &libro: libros)
        if (mayorCantidadEjemplares == libro.getCantidadEjemplares())
            librosmayor.push_back(libro.getNombre());

    return librosmayor;
}

string Biblioteca::getEditorialConMasEjemplares() {
    map<string, int> editoriales;
    for (auto &lib: libros) {
        auto lib_edit = lib.getCantidadEjemplaresPorEditorial();
        for (auto &edit: lib_edit)
            editoriales[edit.first] += edit.second;
    }
    typedef pair<string, int> par;  // para escribir menos
    vector<par> temp(editoriales.begin(), editoriales.end());
    sort(temp.begin(), temp.end(), [](par &a, par &b){
        return a.second > b.second;
    });
    
    return temp[0].first;
}