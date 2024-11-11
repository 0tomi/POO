char * copyStr(const char * str){

}

template <class Clase>
void redim(Clase* &arrayViejo, int &max, int nuevoMax)
{
    // Creamos un nuevo array de punteros, pero con el doble de tamanio.
    Clase* newArray = new Clase[nuevoMax]; 
    // Copiamos los datos del array viejo dentro del array nuevo
    for (int i = 0; i < max; i++)
        newArray[i] = arrayViejo[i];
    // Liberamos la memoria del array viejo
    if (arrayViejo)
        delete[] arrayViejo;
    // Actualizamos el max, y el array viejo
    arrayViejo = newArray;
    max = nuevoMax;
}

class Examen {
public:
    Examen(int nota, char tipo, int nparcial);
    int getNota();
    char getTipo();
    int getNumParcial();
private:
    int nota;
    char tipo; // R o P
    int numero_parcial;
};

class Alumno {
public:
    Alumno(int dni, char * nombre);
    void addExamen(Examen);
    void removeExamen(int nota, int num_parcial);
    void getExamen(int pos);

    int promedio();
    int getCantExamenes();
private:
    Examen * examenes = nullptr;
    int cant_examenes = 0;
};

void Alumno::addExamen(Examen ex){
    int indice = ex.getNumParcial()-1;

    if (ex.getTipo() == 'P'){
        if (indice >= cant_examenes)
            redim(this->examenes, cant_examenes, cant_examenes+1);
        examenes[indice] = ex;
        return;
    }

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