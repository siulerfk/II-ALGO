#include <cstring>
#include <iostream>

#define MAX_NOMBRE 15

using namespace std;

typedef struct nodo nodo_t;

// en c++ no existe deferecia entre struct y tyedef struct
typedef struct{
	nodo_t *prim;
}lista_t;

typedef struct nodo {
	void *prox;
	void *dato;
} nodo_t;

typedef struct datos {
	char nombre[MAX_NOMBRE];
	int padron;
	float sueldo;
} datos_t;

lista_t *crear_lista() {
	lista_t *L = new lista_t(); // new(lista_t); new pone L->prim = NULL;
	if (L == NULL)
			return NULL;
	L->prim = NULL;

	return L;
}
nodo_t *nodo_cear(nodo_t *prox, void *dato) {
	nodo_t *nuevo = new nodo_t();
	if (nuevo == NULL)
		return NULL;

	nuevo->prox = prox;
	nuevo->dato = dato;

	return nuevo;
}

bool lista_agregar_al_principio(lista_t *L, void *dato) {
	nodo_t *nuevo = nodo_cear(L->prim, dato);
	if (nuevo == NULL)
		return false;

	L->prim = nuevo;

	return true;
}

int main(void) {
	lista_t *L = crear_lista();

	datos_t datos;
	strcpy(datos.nombre, "fernando");
	datos.padron = 98237;
	datos.sueldo = 45680;

	std::cout << "fer: " << lista_agregar_al_principio(L, (void *)&datos);

	return 0;
}
