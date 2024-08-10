#include <iostream>
#include <ctype.h>
#include "templates/pila.cpp"
#include "CString/TomiString.h"

using namespace std;
struct TestStructInsano{
    int locura;
    float mega;
    char insana;
};

void test1(){
    //Test de pila int
    pila<int> test;
    test.push(1);
    test.push(3);
    test + 10 + 6 + 3 + 7 ;

    cout << test + 5;
    cout << "\nDato actual: " << test.pop() << endl;

    // Test de pila usando struct
    pila<TestStructInsano> test2;
    test2.push({1, 0.1, 'a'});
    cout << test2;

    TestStructInsano aux;
    aux = test2.pop();
    cout << endl << aux.insana;
}

int main()
{      
    TomiString test;
    TomiString test2("hola");
    char test3[] = "hola";
    test = test3;
    //test = test + " que tal?";

    test[1] = 'a';

    cout << test << endl;

    return 0;
}
