#include <stdio.h>
#include <iostream>
using namespace std;

class Zero{};

int main(int argc, char** argv)
{
    Zero z;
    int a = 3;
    short int b = 1;
    int c = 2;
    cout << sizeof(z) << endl;

    char *pz = (char*)(&z);
    printf("%hhx\n", *pz);
    cout << *pz << " " << &a << " "  << &b << " " << &c << endl;

    return 0;
}
