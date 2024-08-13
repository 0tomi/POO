#include <iostream>
#include "Vector.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Vector<int> locura;
    for (int i = 0; i < 10; i++)
    {
        locura.add(i*2);
    }
    
    cout << locura[2];
    return 0;
}
