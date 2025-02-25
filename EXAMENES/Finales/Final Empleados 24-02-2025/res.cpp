#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Resolucion de la lectura de archivos;
// Version 1:
struct infoEmpleado{
    int guiones, cod;
    string nombre;
};

class Empleado{
private:
    int codigo;
    string name;
    vector<Empleado*> subordinados;
    Empleado* responsable;
public:
    Empleado(int cod,string name,Empleado* resp);
    void addSubordinado(Empleado*);
    Empleado* getResponsable();
};

class Gestor{
public:
    Gestor(string ruta_archivo);
private:
    vector<Empleado*> empleados;
    infoEmpleado interpretar(string line);
    void recursiveGuard(ifstream &arch, Empleado* father, infoEmpleado info);

    void lectura2(string url);
};

Gestor::Gestor(string ruta_archivo)
{
    ifstream arch(ruta_archivo);
    if (arch.fail()) return;

    string line;
    getline(arch, line);
    recursiveGuard(arch, nullptr, interpretar(line));

    arch.close();
}

void Gestor::recursiveGuard(ifstream &arch, Empleado* father, infoEmpleado info)
{
    auto emp = new Empleado(info.cod, info.nombre, father);
    if (father)
        father->addSubordinado(emp);

    this->empleados.push_back(emp);

    string line;
    if (getline(arch, line)){
        auto temp = interpretar(line);
        if (temp.guiones > info.guiones)    // Para entender mejor esto miren la estructura del archivo, si tiene mas guiones, volvemos a llamar a
            recursiveGuard(arch, emp, temp);    // la funcion, pero esta vez siendo el empleado que acabamos de cargar el padre.
        else if (temp.guiones == info.guiones)
            recursiveGuard(arch, father, temp);
        else{
            // Si tenemos menos guiones, es porque hay que volver pa' tra', asi que volvemos hasta quedar en el nivel adecuado.
            auto padre = father;
            int nivelar = info.guiones - temp.guiones;
            for (int i = 0; i < nivelar && padre; i++)  // && padre, evaluamos que no se nos vaya a un puntero nulo, aunque no es necesario segun la logica del enunciado
                padre = father->getResponsable();

            recursiveGuard(arch, padre, temp); 
        }
    }
}

infoEmpleado Gestor::interpretar(string line)
{
    infoEmpleado temp;
    // Contamos los guiones
    int i;
    for (i = 0; i < line.length() && line[i] == '-'; i++)
        ;
    temp.guiones = i;
    // Obtenemos el codigo
    // Empezando desde donde terminamos anteriormente, buscamos donde empieza y donde termina el numero, luego lo hacemos substr y lo convertimos en codigo.
    auto nombre = line.find_first_not_of('-', i);
    temp.cod = stoi(line.substr(i, nombre-i));
    // Obtenemos el code 
    temp.nombre = line.substr(nombre);

    return temp;
}

void Gestor::lectura2(string url){
    ifstream arch(url);
    if (arch.fail()) return;


}