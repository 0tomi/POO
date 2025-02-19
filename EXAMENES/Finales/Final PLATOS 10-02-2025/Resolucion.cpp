#include <vector>
#include <fstream>
#include <string.h>
using namespace std;

class Comida
{
protected:
    float precio;
    char * Id;
public:
    Comida(const char * id, float costo);
    ~Comida();
    char * id() { return this->Id; };

    virtual float costo() = 0;
};

Comida::Comida(const char * id, float costo)
{
}

Comida::~Comida()
{
}

class Ingrediente: public Comida
{
private:
    
public:
    Ingrediente(char * id, float costo);
    ~Ingrediente();
    float costo();
};

Ingrediente::Ingrediente(char * id, float costo): Comida(id, costo)
{
}

Ingrediente::~Ingrediente()
{
}

float Ingrediente::costo()
{
    return this->precio;
}

class Plato: public Comida
{
private:
    vector<Comida*> ingredientes;
public:
    Plato(char * id, float costo = 0);
    ~Plato();
    float costo();
    void guardar(ofstream &plato, ofstream &ingrediente, ofstream &relacion);
};

/*
    Disenio del archivo de relaciones:
    id_origen -> id_destino
    id_origen -> id_destino
    id_origen -> id_destino

    Por eso siempre escribo esos 2 writes al principio, se podria reducir y 
    solamente indicar el id de origen, la cantidades de destino que tiene, y 
    luego solamente copiar las IDs de origen; pero de la forma que esta programado, al funcionar como 
    un barrido que no va por niveles, es imposible.

    Si guardase los platos en una cola o una pila (o en un vector si quisieramos hacer desastre),
    y los recorriera luego de escribir todas las IDs, se podria guardar de la forma optima que mencione 
    anteriormente, pero no tenia ganas, asi se entiende la idea.
*/

void Plato::guardar(ofstream &platos, ofstream &ingredientes_, ofstream &relaciones){
    for (auto ing: ingredientes){
        // Escribimos la relacion entre el plato actual y el ingrediente
        relaciones.write(this->Id, sizeof(char) * 20);
        relaciones.write(ing->id(), sizeof(char) * 20); // voy a suponer que los char estos ocupan 20 bytes

        auto plato = dynamic_cast<Plato*>(ing);
        if (plato){
            platos.write(this->Id, sizeof(char) * 20);
            // aca iria el costo y otras cosas si hubiera
            plato->guardar(platos, ingredientes_, relaciones);
        }
        
        ingredientes_.write(ing->id(), sizeof(char) * 20);
        auto costo = ing->costo();
        ingredientes_.write(reinterpret_cast<char*>(&costo), sizeof(float));
    }
}

Plato::Plato(char * id, float costo): Comida(id, costo)
{

}

Plato::~Plato()
{
}

float Plato::costo()
{
    float total = 0;
    for (auto ing: ingredientes)
        total += ing->costo();

    return total;
}

class Gestor
{
private:
    vector<Plato> platos;
public:
    Gestor(/* args */);
    void guardar();
    ~Gestor();
};

void Gestor::guardar(){
    ofstream fplatos, ingredientes, relaciones;
    // aca abrimos los archivos y bla bla

    for (auto plato: platos){
        fplatos.write(plato.id(), sizeof(char) * 20);
        plato.guardar(fplatos, ingredientes, relaciones);
    }

    fplatos.close(); ingredientes.close(); relaciones.close();
}

Gestor::Gestor(/* args */)
{
}

Gestor::~Gestor()
{
}
