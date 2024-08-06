#include <iostream>
#include "templates/pila.cpp"

using namespace std;

int main()
{
    pila<int> test;
    test.push(1);
    test.push(3);

    cout << "Tamanio actual: " << test.getSize();
    cout << "\nDato actual: " << test.pop() << endl;
    return 0;
}
