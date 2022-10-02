#include <iostream>

#include "09-Lista.h"

int main(int argc, char *argv[])
{
    Lista<int> *Notas = new Lista<int>();

    Notas->agregar(1);
    Notas->agregar(2);
    Notas->agregar(3);
    Notas->agregar(4);
    return 0;
}
