/*
	Nota las plantillas template no se pueden separar en archivos .h y .cpp
	ver apunte de clase "template".

	Como compilar:
		g++ -Wall -pedantic -std=c++98 02.cpp -o var
*/

#include <iostream>
#include <cstring>

#include "02-Nodo.h"
#include "02-Lista.h"

int cmp(const void *s1, const void *s2){
    return strcmp((char *)s1, (char *)s2);
}

int main(void){
	Lista<void> *datos = new Lista<void>();

	datos->agregar_pincipio((char *)"fernado");
	datos->agregar_pincipio((char *)"Matias");
	datos->agregar_pincipio((char *)"Juan");
	datos->agregar_pincipio((char *)"Maria");
	datos->agregar_pincipio((char *)"Jose");

    cout << (char *)datos->eliminar_buscado((char *)"Juan", cmp);

	delete datos;
	
	return 0;
}
