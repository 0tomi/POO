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
    size_t size() const;

    // Operadores sobrecargados
    friend std::ostream& operator<<(std::ostream& os, const TomiString& cadena);
    TomiString operator= (TomiString &otherString);
    TomiString operator= (char * otherString);

private:
    void setString(char * newString);
    char * string;
    size_t length;
};
#endif // !TOMISTRING_H
