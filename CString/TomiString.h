#ifndef TOMISTRING_H
#define TOMISTRING_H
#include <string.h>
#include <iostream>

class TomiString{
public:
    TomiString();
    TomiString(const char * newString);
    TomiString(char * newString);


    // Operadores sobrecargados
    friend std::ostream& operator<<(std::ostream& os, const TomiString& cadena);
    size_t size() const;

private:
    char * string;
    size_t length;
};
#endif // !TOMISTRING_H
