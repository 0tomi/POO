char * copyStr(const char * str){

}

template<class T>
void redim(T &array, int max){}

class Examen {
    int nota;
    char tipo; // R o P
    int numero_parcial;
};

class Alumno {
public:
    Alumno(int dni, char * nombre);
    void addExamen(int nota, char tipo, int num_parcail);
    void removerExamen();
    void getExamen(int pos);

    int promedio();
private:
    Examen * examenes;
    int cant_examenes;
};

class Curso{
public:
    Curso(/* parametros */);
    void addAlumno(Alumno);
    Alumno getAlumno(int pos);
    char * getEstado();

private:
    Alumno alumno[50];
    int cant_alumnos;
};

char * Curso::getEstado(){
    for (int i = 0; i < cant_alumnos; i++){
        alumno[i].promedio();
        if ()

    }

    return estados;
}