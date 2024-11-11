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
    Examen();
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
    Examen * examenes = new Examen[max];
    int cant_examenes = 0;
    int max = 2;
};

void Alumno::removeExamen(int nota, int num_parcial){
    int j = 0;
    for (int i = 0; i < cant_examenes; i++)
        if (this->examenes[i].getNota() != nota && this->examenes[i].getNumParcial() != num_parcial){
            examenes[j] = examenes[i];
            j++;
        }

    this->cant_examenes = j;            
}

void Alumno::addExamen(Examen ex){
    int indice = ex.getNumParcial()-1;

    if (ex.getTipo() == 'P'){
        if (indice >= max)
            redim(this->examenes, max, max*2);
        examenes[indice] = ex;
        this->cant_examenes++;
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