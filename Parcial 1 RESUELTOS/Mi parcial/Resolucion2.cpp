#include <string.h>
#include <iostream>

// Consigna 1:
// se puede usar int en vez de size_t, pero size_t es mejor.
template <class T>
class Vector{
public:
    Vector();
    ~Vector() { delete[] data } // no es necesario.
    // Consigna a
    void push_back(T data);
    // Consigna b
    T get(size_t pos);
    T& operator[](size_t pos);    // ALTERNATIVA
    // Consigna c
    void eliminar(T dato);
    // metodo util
    size_t size() { return this->size_};
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
    for (int i = pos; i < this->size; i++)
        this->data[i] = data[i+1];

    this->size--;
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