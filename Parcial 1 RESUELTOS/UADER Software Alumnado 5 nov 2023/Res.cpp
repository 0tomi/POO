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
    void addExamen(Examen);
    void removerExamen();
    void getExamen(int pos);

    int promedio();
    int getCantExamenes();
private:
    Examen * examenes;
    int cant_examenes;
};

void Alumno::addExamen(Examen ex){
    int indice = ex.getNro()-1;

    if (ex.getTipo() == 'P'){
        if (cant_examenes < indice)
            redim<Examen*>(this->examenes, cant_examenes+1);
        examenes[indice] = ex;
        cant_examenes++;
        return;
    }

    if (cant_examenes < indice){
        redim<Examen*>(this->examenes, cant_examenes+1);
        examenes[indice] = ex;
        return;
    }
       
    if (examenes[indice].getNota() < ex.getNota())
        examenes[indice] = ex;
}

int Alumno::getCantExamenes() {
    int cantidad;


}

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