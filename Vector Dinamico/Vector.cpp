#ifndef VECTOR_CPP
#define VECTOR_CPP
#include "Vector.h"
template <class T>
Vector<T>::Vector(T data){
    this->max = 2; this->index = 0;
    this->vector = new T[max];
    vector[index++] = data;
}

template <class T>
void Vector<T>::add(T data){
    if (this->index == this->max)
        this->resize(this->max * 2);
    this->vector[this->index++] = data;
}

template <class T>
T Vector<T>::get(int pos){
    return (pos < index)? this->vector[pos]: T{};
}

template <class T>
bool Vector<T>::remove(T data){
    bool removed = false;
    for (int i = 0; i < index; i++)
        if (this->vector[i] == data){
            deletePos(i);
            removed = true;
        }
    return removed;
}

template <class T>
bool Vector<T>::removePos(int pos){
    if (!(pos < index))
        return false;
    deletePos(pos);
    return true;
}

template <class T>
int Vector<T>::getCurrentIndex(){
    return index;
}

template <class T>
T& Vector<T>::operator[](size_t pos){
    return this->vector[pos];
}

template <class T>
const T& Vector<T>::operator[](size_t pos) const{
    return this->vector[pos];
}

template <class T>
void Vector<T>::resize(unsigned int newMax){
    T* newArray = new T[newMax];
    for (unsigned int i = 0; i < index; i++)
        newArray[i] = this->vector[i];
    delete[] this->vector;
    this->max = newMax; this->vector = newArray;
}

template <class T>
void Vector<T>::deletePos(int pos){
    delete this->vector[pos];
    for (int i = pos+1; i < this->max; i++)
        this->vector[i-1] = this->vector[i];
    this->index--;
}

#endif // !VECTOR_CPP

