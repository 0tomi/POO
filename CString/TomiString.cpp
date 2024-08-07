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
    string = new char[length];

    strncpy(string, newString, length);
}

size_t TomiString::size() const
{
    return length;
}

std::ostream& operator<<(std::ostream& os, const TomiString& obj){
    if (obj.string == nullptr)
        os << "";
    else
        for (size_t i = 0; i < obj.length; i++)
            os << obj.string[i];
    return os;
}
#endif // !TOMISTRING_CPP
