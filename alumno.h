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
        void setNota3(int newNota3);
};

#endif // ALUMNO_H