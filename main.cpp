#include <iostream>
#include "templates/pila.cpp"

using namespace std;

int main()
{
    pila<int> test;
    test.push(1);
    test.push(3);

    cout << test;
    cout << "\nDato actual: " << test.pop() << endl;
    return 0;
}
