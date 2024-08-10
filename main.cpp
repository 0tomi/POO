#include <iostream>
#include <ctype.h>
#include "templates/pila.cpp"
#include "CString/TomiString.h"
#include "templates/listade.cpp"

using namespace std;
struct TestStructInsano{
    int locura;
    float mega;
    char insana;
};

template <class T>
T sumar(T a, T b){
    return a + b;
}

void test1(){
    //Test de pila int
    pila test(5);
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

void test2(){
    ListaDE<int> lista;
    lista.insertar(5);
    lista.insertar(7);
    cout << lista[1];
}

int main()
{
    test2();

    TomiString test;
    TomiString test2("hola");
    char test3[] = "hola";
    test = test3;
    //test = test + " que tal?";

    test[1] = 'a';

    cout << test << endl;

    return 0;
}
