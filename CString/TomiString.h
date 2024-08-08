#ifndef TOMISTRING_H
#define TOMISTRING_H
#include <string.h>
#include <iostream>

class TomiString{
public:
    // Constructores
    TomiString();
    TomiString(const char * newString);
    TomiString(char * newString);
    TomiString(TomiString &string);
    ~TomiString();

    // Getters
    size_t getLength() const;

    // Operadores sobrecargados
    friend std::ostream& operator<<(std::ostream& os, const TomiString& cadena);

    TomiString operator= (TomiString &otherString);
    TomiString operator= (const char * otherString);
    TomiString operator= (const TomiString &otherString);

    TomiString operator+ (TomiString& otherString);
    TomiString operator+ (const TomiString& otherString);
    TomiString operator+ (const char * otherString);

    char& operator[](size_t index);
    const char& operator[](size_t index) const; // Para acceso const
private:
    void setString(const char * newString);
    char * Concaternar(char * string1, const char * string2);
    char * string;
    size_t length;
};
#endif // !TOMISTRING_H
