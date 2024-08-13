#ifndef VECTOR_H
#define VECTOR_H
#include <cstddef>
template <class T>
class Vector{
public:
    Vector(): max(2), index(0) {vector = new T[max];};
    Vector(T data);
    void add(T data);
    T get(int pos);
    bool remove(T data);
    bool removePos(int pos);
    int getCurrentIndex();
    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;
private:
    void resize(unsigned int newMax);
    void deletePos(int pos);
    T* vector;
    unsigned int max, index;
};
#endif // !VECTOR_H