// ejemplo de como haria el guardado de archivos
#include <fstream>
#include <vector>
#include <string.h>

// ### Ejemplo clase base ###
struct data_alumno{
    char nya[200]; // nombre y apellido
    int code;
    std::vector<float> notas; // 1: invitado, 3: medio, 5: premium
};

class Alumno
{
protected:
    std::string nya;
    int code;
    /* data */
public:
    Alumno(/* args */);
    virtual data_alumno data();
    virtual float promedio() = 0;
    // + otros metodos para otras cosas 
    ~Alumno();
};

data_alumno Alumno::data()
{
    data_alumno datos;
    strcpy(datos.nya, this->nya.c_str());
    datos.code = this->code;
    
    return datos;
}

// ### Ejemplo de como lo implementaria una clase hija ###
class Alumno_Premium: public Alumno
{
private:
    float notas[5]; // tiene 5 notas
    /* data */
public:
    Alumno_Premium(/* args */);
    ~Alumno_Premium();
    data_alumno data();
};

data_alumno Alumno_Premium::data()
{
    auto datos = Alumno::data();
    for (int i = 0; i < 5; i++)
        datos.notas.push_back(this->notas[i]);

    return datos;
}

// ### Ejemplo como lo implementaria el gestor: ###
class Gestor
{
private:
    std::vector<Alumno*> alumnos;
public:
    Gestor(/* args */);
    ~Gestor();
};

Gestor::Gestor(/* args */)
{
}

Gestor::~Gestor()
{
}
