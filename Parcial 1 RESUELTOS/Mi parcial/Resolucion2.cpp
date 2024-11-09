#include <string.h>
#include <iostream>

// Consigna 1:
// se puede usar int en vez de size_t, pero size_t es mejor.
template <class T>
class Vector{
public:
    Vector();
    ~Vector() { delete[] data; } // no es necesario.
    // Consigna a
    void push_back(T data);
    // Consigna b
    T get(size_t pos);
    T& operator[](size_t pos);    // ALTERNATIVA
    // Consigna c
    void eliminar(T dato);
    void eliminar2(T dato); // ALTERNATIVA MAS SIMPLE
    // metodo util
    size_t size() { return this->size_; }
private:
    void resize(size_t newMax);
    void eliminar(size_t pos);
    T * data;
    size_t max;
    size_t size_;
};

template<class T>
Vector<T>::Vector()
{
    // se puede inicializar en nullptr, o de cualquier otra forma
    // da igual, pero de esta forma es mas optimizado
    this->data = new T[2];
    this->max = 2;
    this->size_ = 0;
}

template<class T>
void Vector<T>::push_back(T data_)
{
    if (size_ == max)
        this->resize(this->max * 2); // lo multiplico por 2 porque es mas optimizado pero lo pueden hacer como quieran
    
    this->data[size_++] = data_; // se incrementa post asignacion
}

template<class T>
T Vector<T>::get(size_t pos)
{
    return data[pos];
}

template<class T>
T& Vector<T>::operator[](size_t pos)
{
    return data[pos];
}

template<class T>
void Vector<T>::resize(size_t newMax)
{
    T * temp = new T[newMax];
    for (int i = 0; i < this->max; i++)
        temp[i] = this->data[i];

    delete[] this->data;
    this->data = temp;
    this->max = newMax;
}

// Otra version alternativa mucha mas simple
template <class T>
void Vector<T>::eliminar2(T dato){
    int j = 0;
    for (int i = 0; i < this->size_; i++)
        if (this->data[i] != dato)
            this->data[j++] = this->data[i];

    // Actualizamos el size con la cantidad nueva.
    this->size_ = j;
}

// Version alternativa, funciona mejor que la que plantee en el parcial.
template<class T>
void Vector<T>::eliminar(T dato)
{
    for (size_t i = 0; i < this->size_; i++)
        while((this->data[i] == dato) && (i < this->size_))
            eliminar(i);
}

template <class T>
void Vector<T>::eliminar(size_t pos){
    for (int i = pos; i < this->size_; i++)
        this->data[i] = data[i+1];

    this->size_--;
}
 
// Consigna 2:
// Superclase abstracta para laburar el parcial
class ProductoBase {
public:
    ProductoBase(int codigo, const char * nombre);
    friend std::ostream& operator<< (std::ostream& os, ProductoBase& p);
    virtual char * getIngredientes() = 0;
    int getCodigo() { return codigo; }  // este tipo de getters no hace falta poner
    char * getNombre();                 

protected:
    char * copyStr(const char *);
    char * append(char *  &primero, const char * segundo);
    int codigo;
    char * nombre;
};

ProductoBase::ProductoBase(int codigo, const char * nombre) {
    this->codigo = codigo;
    this->nombre = this->copyStr(nombre);
}

std::ostream& operator<< (std::ostream& os, ProductoBase& p){
    os << "Producto: " << p.getNombre() << " Codigo: " << p.getCodigo() << std::endl
       << "Ingredientes: \n";
    os << p.getIngredientes();
}

char * ProductoBase::getNombre(){
    return copyStr(this->nombre);
}

char * ProductoBase::copyStr(const char * str){
    int tam = strlen(str);
    char * newStr = new char[tam + 1];
    strcpy(newStr, str);
    return newStr;
}

char * ProductoBase::append(char *  &primero, const char * segundo){
    char * suma = new char[strlen(primero) + strlen(segundo) + 1];
    strcpy(suma, primero);
    strcat(suma, segundo);
    delete primero; 
    primero = suma;
    return primero; // esto no hace falta, podria ser void, pero ante la duda si lo llego a necesitar..
}

// Clases hijas:
class Producto: public ProductoBase
{
private:
    Vector<char*> ingredientes;
public:
    Producto(int codigo, const char * nombre): ProductoBase(codigo, nombre) {}
    void addIngrediente(const char * ing) { ingredientes.push_back(this->copyStr(ing)); }
    char * getIngredientes();
};

char * Producto::getIngredientes(){
    size_t tam = this->ingredientes.size();
    char * ingredientes_ = this->copyStr(ingredientes[0]);
    for (size_t i = 1; i < tam; i++){
        this->append(ingredientes_, ingredientes[i]);
        this->append(ingredientes_, "\n");  // para que salgan separados xd
    }

    return ingredientes_;
}

class ProductoCompuesto: public ProductoBase
{
private:
    Vector<ProductoBase*> productos;
public:
    ProductoCompuesto(int codigo, const char * nombre): ProductoBase(codigo, nombre) {}
    void addProducto(ProductoBase * newprod);
    char * getIngredientes();
};


void ProductoCompuesto::addProducto(ProductoBase * newprod){
    if (dynamic_cast<ProductoCompuesto*> (newprod))
        return; // si es producto compuesto no lo agregamos.

    productos.push_back(newprod);
}

// Aca el tema es que mostrar, podemos mostrar los ingredientes directamente.
// Para que quede mas fachero voy a mostrar el nombre de los productos que componen al compuesto.

char * ProductoCompuesto::getIngredientes(){
    size_t tam = this->productos.size();
    char * compuesto = this->copyStr("");
    for (size_t i = 0; i < tam; i++) {
        this->append(compuesto, productos[i]->getNombre());
        this->append(compuesto, "\n");
        // si no hubiera querido mostrar el nombre del producto, el for solo tendria esta linea.
        this->append(compuesto, productos[i]->getIngredientes());
    }

    return compuesto;
}

// Clase gestora
class Gestor {
private:
    Vector<ProductoBase*> productos;
public:
    Gestor();
    void addProducto(ProductoBase * newProd);
    ProductoBase * getProd(int pos);

    // consigna b
    void mostrarProductos();
};

// la unica que voy a programar es la b porque las otras son medio obvias
void Gestor::mostrarProductos(){
    size_t tam = productos.size();
    for (size_t i = 0; i < tam; i++)
        std::cout << *productos[i] << std::endl;
}


int main(int argc, char const *argv[])
{
    Vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    test.push_back(2);

    std::cout << "Antes de limpiar el 2: ";
    for (size_t i = 0; i < test.size(); i++)
        std::cout << test[i] << " ";

    test.eliminar(2);
    std::cout << "\nDespues de limpiar el 2: ";
    for (size_t i = 0; i < test.size(); i++)
        std::cout << test[i] << " ";

    return 0;
}
