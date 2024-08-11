class Padre{
public:
    virtual const char * Hablar(){
        return "Hola";
    }
};

class Hijo: public Padre{
    const char * Hablar() override{
        return "Chau";
    }
};

class Hija: public Padre{
    const char * Hablar() override{
        return "Todo bien?";
    }
};

int main(int argc, const char** argv) {
    Padre * puntero = new Padre[50]; // MAL

    Padre ** ejemploBIEN = new Padre* [50];
    ejemploBIEN[30] = new Hijo;
    ejemploBIEN[25] = new Hija;


    return 0;
}