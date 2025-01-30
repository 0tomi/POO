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


class Alumno_Medio: public Alumno
{
private:
    float notas[3]; // tiene 5 notas
    /* data */
public:
    Alumno_Medio(/* args */);
    ~Alumno_Medio();
    data_alumno data();
};

data_alumno Alumno_Medio::data()
{
    auto datos = Alumno::data();
    for (int i = 0; i < 3; i++)
        datos.notas.push_back(this->notas[i]);

    return datos;
}


class Alumno_Invitado: public Alumno
{
private:
    float nota; // tiene 5 notas
    /* data */
public:
    Alumno_Invitado(/* args */);
    ~Alumno_Invitado();
    data_alumno data();
};

data_alumno Alumno_Invitado::data()
{
    auto datos = Alumno::data();
    datos.notas.push_back(this->nota);

    return datos;
}

// ### Ejemplo como lo implementaria el gestor: ###
class Gestor
{
private:
    std::vector<Alumno*> alumnos;
    void guardarArchivo(std::string direc, std::vector<data_alumno> &alum, int cant_Notas);
public:
    Gestor(/* args */);
    void guardarDatos();
    // + otros metodos para otras cosas 
    ~Gestor();
};

void Gestor::guardarArchivo(std::string direc, std::vector<data_alumno> &alum, int cant_Notas) {
    std::ofstream archivo(direc, std::ios::binary);
    for (auto alumno: alum) {
        archivo.write((char*) alumno.nya, sizeof(alumno.nya));
        archivo.write((char*) alumno.code, sizeof(int));
        archivo.write((char*) alumno.notas.data(), sizeof(float) * cant_Notas);
    }
    archivo.close();
}

void Gestor::guardarDatos() {
    std::vector<data_alumno> datos[3]; // 0: Free, 1: medium, 2: premium
    for (auto alumno: this->alumnos) {
        int i = 0;  // arrancamos asumiendo que es free, si no lo llega a ser se cambia.
        if (dynamic_cast<Alumno_Medio*>(alumno))
            i = 1;
        else if (dynamic_cast<Alumno_Premium*>(alumno))
            i = 2;
        
        datos[i].push_back(alumno->data());
    }

    this->guardarArchivo("/alumnos_invitados.dat", datos[0], 1);
    this->guardarArchivo("/alumnos_medio.dat", datos[1], 3);
    this->guardarArchivo("/alumnos_premium.dat", datos[2], 5);
}