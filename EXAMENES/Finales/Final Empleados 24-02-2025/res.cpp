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
    // Solucion A
    Gestor(string ruta_archivo);
private:
    vector<Empleado*> empleados;
    infoEmpleado interpretar(string line);
    void recursiveGuard(ifstream &arch, Empleado* father, infoEmpleado info);

    // Solucion B
    void lectura2(string url);
};

// ########## Solucion A ############## ########## Solucion A ############## ########## Solucion A ############## ########## Solucion A ##############

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
    // --45-Pedro
    infoEmpleado temp;
    // Contamos los guiones
    int i;
    for (i = 0; i < line.length() && line[i] == '-'; i++)
        ;
    temp.guiones = i;
    // Obtenemos el codigo
    // Empezando desde donde terminamos anteriormente, buscamos donde empieza y donde termina el numero, luego lo hacemos substr y lo convertimos en codigo.
    size_t separator = line.find('/', i); // Buscar el guión que separa código y nombre
    temp.cod = stoi(line.substr(i, separator - i));
    temp.nombre = line.substr(separator + 1);

    return temp;
}

// ########## Solucion B ############## ########## Solucion B ##############  
/*
    Solucion un poco mas compleja:
    La estructura del archivo es asi:
        [Guiones][Codigo]-[Nombre]

    Si asumimos que el siguiente nombre que vamos a encontrar tiene un guion mas que el anterior, por ejemplo
        45-Pedro
        -47-Antonio
        --48-Pepe
    Podemos guardar constantemente un empleado asignandolo como subordinado del anterior (Parte2), a excepcion del primero (Parte1).
    Esto lo podemos hacer mediante una "pila", que usamos un vector para representarla porque nos simplifica el trabajo,
    donde cargamos el primer empleado que nos encontramos, si este esta en el nivel 0 (0 guiones, quiere decir que es jefe),
    lo cargamos sin un padre, y lo agregamos a la pila, como se puede ver en la parte 1a y 1b.

    Luego procedemos a hacer el loop anteriormente mencionado, donde cargamos empleados y automaticamente ponemos como
    padre el anterior cargado, en este caso si cargo a Antonio, se cargaria a Pedro como su padre, y asi lo mismo con Pepe,
    Como se alcanza a ver en la Parte2.

    Pero tenemos un problema, no siempre el archivo sigue esta estructura, por lo que tenemos otro caso: 
        45-Pedro
        -47-Antonio
        --48-Pepe
        --44-Juan

    Al leer a Juan, juan no es subordinado de pepe, por lo que hay que proceder a solucionarlo.
    Si prestamos atencion, el tamanio de la pila condice con el nivel del empleado a cargar (los guiones),
    por lo que podemos estar evaluando constantemente si hay un desface, es decir, si la pila almacena mas empleados
    que el nivel en el que estamos.
    En este caso al querer cargar a Juan, la pila tendria 3 empleados, pero el nivel seria 2, por lo que mediante
    la parte 3, vamos retirando empleados hasta que la cantidad de empleados en la pila se equipare al nivel, es decir
    es como si volvieramos para atras.
    
    En la pila veeriamos esto: 
        45-Pedro
        -47-Antonio
        --48-Pepe
    Para no sacar a pepe de la pila y cargarlo como jefe de Juan, primero lo eliminamos de la pila, mediante lo que 
    vemos en la parte 2, donde la pila nos quedaria asi:
        45-Pedro
        -47-Antonio
    Finalmente, podriamos sacar a Antonio y asignarlo como jefe de Juan con tranquilidad. 
    Esto funciona debido a como se comporta el archivo, si estuviera estructurado de otra forma no se podria hacer.

    Por ultimo nos queda explicar la parte 4, hacemos un clear a la pila, ya que en un caso donde volvemos a empezar con un jefe: 
        45-Pedro    -> En la pila
        -47-Antonio -> En la pila
        --48-Pepe
        --44-Juan
        31-Sofia
    En la pila se encontrarian estos 2 empleados, los cuales al haber pasado ya su arbol, no es mas necesario que esten,
    por lo que vaciamos la pila para poder cargar el arbol de Sofia.

    Este proceso se repite constantemente hasta terminar de cargar el archivo, es medio complicado de entender al principio
    debido a como se ubican las partes del algoritmo, pero funciona y es mas corta y "eficiente" que la solucion recursiva.
*/
void Gestor::lectura2(string url){
    vector <Empleado*> pilaEmpleados;
    ifstream arch(url);
    if (arch.fail()) return;

    string line;
    while (getline(arch, line)){
        auto info_emp = interpretar(line);
        // Parte 1a:
        if (info_emp.guiones == 0) {
            // Parte 4.
            pilaEmpleados.clear();
            // Parte 1b.
            this->empleados.push_back(new Empleado(info_emp.cod, info_emp.nombre, nullptr));
            pilaEmpleados.push_back(empleados.back());
        } else {
        // Parte 3:
            while (pilaEmpleados.size() > info_emp.guiones)
                pilaEmpleados.pop_back();
            
        // Parte 2:
            this->empleados.push_back(new Empleado(info_emp.cod, info_emp.nombre, pilaEmpleados.back()));                
            pilaEmpleados.back()->addSubordinado(this->empleados.back());
            pilaEmpleados.push_back(this->empleados.back());
        }
    }
}