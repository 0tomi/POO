#include <iostream>
#include "templates/pila.cpp"
#include "templates/pilapunteros.h"

using namespace std;

int main()
{
    pilaPunteros<int> test2(new int);

    pila<int> test;
    test.push(1);
    test.push(3);
    test + 10 + 6 + 3 + 7 ;

    cout << test + 5;
    cout << "\nDato actual: " << test.pop() << endl;
    return 0;
}
