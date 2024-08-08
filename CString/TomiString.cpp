#ifndef TOMISTRING_CPP
#define TOMISTRING_CPP
#include "TomiString.h"

TomiString::TomiString()
{
    length = 0;
    string = nullptr;
}

TomiString::~TomiString()
{
    //std::cout << "String eliminado: " << this->string << std::endl;
    delete[] this->string;
}

TomiString::TomiString(const char *newString)
{
    length = strlen(newString);
    string = new char[length+1];

    strncpy(string, newString, length+1);
}

TomiString::TomiString(char *newString): string(nullptr)
{
    setString(newString);
}

TomiString::TomiString(TomiString &oldString): string(nullptr)
{
    setString(oldString.string);
}

size_t TomiString::getLength() const
{
    return length;
}

TomiString TomiString::operator=(TomiString &otherString)
{
    this->setString(otherString.string);
    return TomiString(otherString.string);
}

TomiString TomiString::operator=(const TomiString &otherString)
{
    this->setString(otherString.string);
    return TomiString(otherString.string);
}

TomiString TomiString::operator= (const char * otherString){
    this->setString(otherString);
    return TomiString(otherString);
}

TomiString TomiString::operator+(TomiString &otherString)
{
    if (this->length == 0)
        return otherString;
    if (otherString.length == 0)
        return *this;

    // Aca tocaria usar strcat para concaternar ambas cadenas, pero no es lo ideal porque es una funcion con errores.
    return TomiString(Concaternar(this->string, otherString.string));
}

char& TomiString::operator[](const size_t numero)
{
    return this->string[numero];
}

const char& TomiString::operator[](size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return string[index];
}

TomiString TomiString::operator+(const TomiString &otherString)
{
    if (this->length == 0)
        return TomiString(otherString.string);
    if (otherString.length == 0)
        return *this;

    // Aca tocaria usar strcat para concaternar ambas cadenas, pero no es lo ideal porque es una funcion con errores.
    return TomiString(Concaternar(this->string, otherString.string));
}

TomiString TomiString::operator+(const char * otherString)
{
    if (this->length == 0)
        return otherString;
    if (strlen(otherString) == 0)
        return *this;

    // Aca tocaria usar strcat para concaternar ambas cadenas, pero no es lo ideal porque es una funcion con errores.
    return TomiString(Concaternar(this->string, otherString));
}

void TomiString::setString(const char * newString)
{
    if (this->string != nullptr)
        delete[] this->string;

    this->length = strlen(newString);
    this->string = new char[length+1];

    strncpy(this->string, newString, length+1);
}

char *TomiString::Concaternar(char *string1, const char *string2)
{
    char * newString = new char[strlen(string1) + strlen(string2) + 1];
    /// Este codigo tirara warnings por todos lados, debido a que strcpy y strcat son
    /// funciones mal hechas, que provocan desbordamiento de buffer.
    /// En este caso no es problema, debido a que previamente creamos un 'string'
    /// con la capacidad suficiente para almacenar todo el texto, por lo que no hay problema.
    strcpy(newString, string1);
    strcat(newString, string2);

    return newString;
}

std::ostream& operator<<(std::ostream& os, const TomiString& obj){
    if (obj.string == nullptr)
        os << "";
    else
        os << obj.string;

    return os;
}
#endif // !TOMISTRING_CPP
