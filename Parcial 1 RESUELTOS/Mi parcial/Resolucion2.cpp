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
    this->size_ -= (this->size_ - j);
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
class ProductoBase {
public:
    ProductoBase(int codigo, const char * nombre);
    friend std::ostream& operator<< (std::ostream& os, ProductoBase& p);
    virtual char * getIngredientes() = 0;
    int getCodigo() { return codigo; }
    char * getNombre();

protected:
    int codigo;
    char * nombre;
};

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