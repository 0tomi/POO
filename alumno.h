#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno{
    private:
        long dni;
        char * nombre;
        int nota;
        int nota2;
        int nota3;
    public:
        Alumno(long dni);
        Alumno(long dni, char* nombre)
};

#endif // ALUMNO_H