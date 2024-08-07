#ifndef TOMISTRING_CPP
#define TOMISTRING_CPP
#include "TomiString.h"

TomiString::TomiString()
{
    length = 0;
    string = nullptr;
}

TomiString::TomiString(const char *newString)
{
    length = strlen(newString);
    string = new char[length+1];

    strncpy(string, newString, length+1);
}

TomiString::TomiString(char *newString)
{
    setString(newString);
}

TomiString::TomiString(TomiString &oldString)
{
    setString(oldString.string);
}

TomiString::~TomiString()
{
    delete this->string;
}

size_t TomiString::size() const
{
    return length;
}

TomiString TomiString::operator=(TomiString &otherString)
{
    this->setString(otherString.string);
    return TomiString(otherString.string);
}

TomiString TomiString::operator= (char * otherString){
    this->setString(otherString);
    return TomiString(otherString);
}

void TomiString::setString(char *newString)
{
    length = strlen(newString);
    string = new char[length+1];

    strncpy(string, newString, length+1);
}

std::ostream& operator<<(std::ostream& os, const TomiString& obj){
    if (obj.string == nullptr)
        os << "";
    else
        os << obj.string;

    return os;
}
#endif // !TOMISTRING_CPP
