/*

    Resolucion de como le gustaria mas guardar los datos usando Structs al profe

*/

#include <vector>
#include <map>
#include <string.h>
#include <fstream>

using namespace std;

struct DatosPlato{
    int id;
    char nombre[200];
    // En el caso de libres podemos aniadir los impuestos y toda esa bola aca
};

struct DatosIngrediente{
    int id;
    float price;
    char nombre[200];
};

struct PackDatos{
    vector<DatosPlato> platos;
    vector<DatosIngrediente> ingredientes;
    map<int,vector<int>> arcos;    
};

/*
    En PackDatos se va a guardar todos los platos y ingredientes que tenga un plato;
    en arcos se guardaran las relaciones, es decir, con que esta relacionada cada comida, mediante el id.
    Ejemplo

    001 -> 002, 003.
    003 -> 056, 058.

    (Traducido)
    Milanesa con Pure -> Milanesa, Pure
    Pure -> Leche, Papa
*/

class Comida {
    // imaginense como que aca hay cosas programadas maravillosas
    public:
        Comida(int Id_, const char * name, float Price = 0);
        int id(); 
        virtual float costo() = 0;
    
    protected:
        int Id;
        float price;
        char * nombre;
};

class Ingrediente: public Comida{
    // imaginense como que aca hay cosas programadas maravillosas 
    public:
    Ingrediente(int Id_, const char * name, float Price = 0);
    DatosIngrediente getDatos();  
};

DatosIngrediente Ingrediente::getDatos() {
    DatosIngrediente temp;
    temp.id = this->Id;
    strcpy(temp.nombre, this->nombre);
    temp.price = this->price;

    return temp;
}

class Plato: public Comida{
    // imaginense como que aca hay cosas programadas maravillosas
    private:
    vector<Comida*> ingredientes;

    public:
    Plato(int Id_, const char * name, float Price = 0);
    DatosPlato getDatos();
    PackDatos data();
};

DatosPlato Plato::getDatos()
{
    DatosPlato temp;
    temp.id = this->Id;
    strcpy(temp.nombre, this->nombre);

    return temp;
}

PackDatos Plato::data()
{
    PackDatos pack;
    pack.platos.push_back(this->getDatos());

    for (auto ing: ingredientes){
        // En el mapa, nos ubicamos en nuestro plato, y le asociamos la ID del ingrediente que estamos mirando.
        pack.arcos[this->Id].push_back(ing->id());

        auto ingrediente = dynamic_cast<Ingrediente*> (ing);
        if (ingrediente)
            pack.ingredientes.push_back(ingrediente->getDatos());
        else{
            // Caso de sacar otro plato, le pedimos los datos y los acoplamos a este.
            auto plato = dynamic_cast<Plato*> (ing);
            auto auxPack = plato->data();

            // Aca acoplamos los nuevos datos en los mapas ya existenes.
            pack.platos.insert(pack.platos.end(), auxPack.platos.begin(), auxPack.platos.end());
            pack.ingredientes.insert(pack.ingredientes.end(), auxPack.ingredientes.begin(), auxPack.ingredientes.end());
            pack.arcos.insert(auxPack.arcos.begin(), auxPack.arcos.end());
        }
    }

    return pack;
}

class GestorLocuraRestaurante{
    private:
    vector<Plato> platos;
    public:
    // imaginense que esto por alguna razon tiene un constructor
    void guardar();        
};

void GestorLocuraRestaurante::guardar(){
    ofstream fPlatos, fIngredientes, fArcos;
    // inicializacion de los archivos bla bla blaaaaaaaaaaaaaaaaaa

    for (auto plato: platos){
        auto temp = plato.data();
        fPlatos.write(reinterpret_cast<char*>(temp.platos.data()), sizeof(DatosPlato) * temp.platos.size());
        fIngredientes.write(reinterpret_cast<char*>(temp.ingredientes.data()), sizeof(DatosIngrediente) * temp.ingredientes.size());

        // Aca viene lo mas complicado, que es guardar el mapa, abajo explico la estructura del archivo binario.
        for (auto relacion: temp.arcos){
            int id = relacion.first;
            int size = relacion.second.size();
            fArcos.write(reinterpret_cast<char*> (&id), sizeof(int));
            fArcos.write(reinterpret_cast<char*> (&size), sizeof(int));

            fArcos.write(reinterpret_cast<char*> (relacion.second.data()), sizeof(int) * size);
        }
    }
    // NO SE OLVIDEN DE CERRAR LOS ARCHIVOSSSSSSSSSSSSSSSSSSS
}


// La estructura en la que se guardaria el archivo con las relaciones/arcos seria asi:
/*
    ID, Cantidad de IDs asociadas, [Lista de IDs]
    ID, Cantidad de IDs asociadas, [Lista de IDs]
    ID, Cantidad de IDs asociadas, [Lista de IDs]
*/