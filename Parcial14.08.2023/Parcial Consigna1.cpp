#include <iostream>
#include <string.h>

class Viaje{
public:
    Viaje(const char * Nombre){
        this->nombre = new char[strlen(Nombre)+1];
        strcpy(this->nombre, Nombre);
    }
    virtual double getMonto() = 0;
    virtual char* getNombre(){
        return nombre;
    }
    friend std::ostream& operator<< (std::ostream& os, Viaje& v){
        os << "Destino: " << v.getNombre() << " Monto: " << v.getMonto();
    }
protected:  
    char * nombre;
    double monto;
};

class ViajeComun: public Viaje{
public:
    ViajeComun(const char * Nombre, double Monto): Viaje(Nombre){
        this->monto = Monto;
    }
    double getMonto(){
        return this->monto;
    }
};

class ViajeDestino: public Viaje{
public:
    ViajeDestino(const char * Nombre, double MontoKm, double Km): Viaje(Nombre){
        this->monto = MontoKm;
        this->km = Km;
    }
    double getMonto(){
        return this->monto * this->km;
    }
private:
    double km;
};

class ViajeMixto: public Viaje{
private:
    Viaje ** viajes;
    int numViajes, maxViajes;
    void modVector(int newMax){
        Viaje ** nuevoVector = new Viaje*[newMax];
        for (int i = 0; i < this->numViajes; i++)
            nuevoVector[i] = this->viajes[i];
        delete[] this->viajes;
        this->viajes = nuevoVector;
        this->maxViajes = newMax;
    }
public:
    ViajeMixto(const char * Nombre): Viaje(Nombre), numViajes(0){
        this->maxViajes = 2;
        this->viajes = new Viaje*[maxViajes];
    }
    void addViaje(Viaje * newViaje){
        if (numViajes == maxViajes)
            modVector(this->maxViajes*2);
         viajes[numViajes++] = newViaje;
    }
    double getMonto(){
        this->monto = 0;
        for (int i = 0; i < this->numViajes; i++)
            this->monto += viajes[i]->getMonto();
        return this->monto;
    }
};

class GestorViajes{
private:
    Viaje * viajes[100];
    int numViaje;
public:
    GestorViajes(): numViaje(0) {}
    void addViaje(Viaje * newViaje){
        if (numViaje == 100)
            return; //para no meter mas de 100 viajes
        viajes[numViaje++] = newViaje;
    }
    Viaje * getViaje(int pos){
        return (pos < numViaje)? viajes[pos]: nullptr;
    }
    friend std::ostream& operator<< (std::ostream& os, GestorViajes& gv){
        for (int i = 0; i < gv.numViaje; i++)
            os << *(gv.viajes[i]) << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
