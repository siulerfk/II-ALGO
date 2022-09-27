/*
	Diseñar la clase ListaEnteros con los siguientes métodos:
		*- Constructor / Destructor
		*- Alta al principio
		*- Alta al final
		*- Alta en posición determinada
		*- Borrar primero
		*- Borrar último
		*- Borrar en determinada posición
		*- Borrar primer elemento (se indica qué elemento quiere ser borrado, y se borra su primera aparición)
		- Borrar elemento (se indica qué elemento quiere ser borrado y se borran todas sus apariciones)
		*- Obtener primero
		- Obtener último
		- Obtener el elemento de una posición determinada
		- Obtener el tamaño de la lista
		*- Listar (muestra todos los elementos de la lista)
		- Listar en forma inversa (muestra desde el último hasta el final)
		
		Consideraciones:
		- Tener en cuenta que se pueden repetir los elementos.
		- Es importante que cada método tenga explícitas las PRE y POST
		condiciones.

		Como compilar:
			make		// compila solo las lineas que faltan actulizarse
			make main 	// compila todos los archivos
			make 01.o 	// complila solo el archivo 01.o
*/

#include <iostream>

#include "01-Nodo.h"
#include "01-Lista.h"

void invertir_lista(Lista *lista);
int lista_ante_k_ultimo(Lista *lista, size_t k);
Lista **crear_matriz_lista(size_t fil, size_t col);
void destruir_matriz_listas(Lista **lista, size_t filas);
Lista ***crear_cubo_lista(size_t filas, size_t col);
void destruir_cubo_lista(Lista ***lista, size_t filas);

int main(void){
/* 
	Lista *enteros = new Lista();
  
	enteros->agregar_pincipio(5);
	enteros->agregar_pincipio(4);
	enteros->agregar_pincipio(3);
	enteros->agregar_pincipio(2);
	enteros->agregar_pincipio(1);
	enteros->mostrar_datos();
    
    Lista *numeros = new Lista();
	numeros->agregar_pincipio(2);
	numeros->agregar_pincipio(5);
	numeros->agregar_pincipio(8);
	numeros->mostrar_datos();

    Lista *intersec = enteros->interseccion(numeros);
	intersec->mostrar_datos();

    delete enteros;
	delete numeros;	
    delete intersec;
   
    // Creamos un vector de punteros Listas.(seria una matriz)
    Lista **matriz = crear_matriz_lista(3, 4);

    matriz[0]->agregar_pincipio(76);
    matriz[0]->agregar_pincipio(77);
    matriz[0]->agregar_pincipio(78);
    
    matriz[1]->agregar_pincipio(4);
    matriz[1]->agregar_pincipio(7);
    matriz[1]->agregar_pincipio(5);

    destruir_matriz_listas(matriz, 3);
*/    
    // Matriz de punteros a Lista.(seria un cubo)
    Lista ***cubo = crear_cubo_lista(4, 5);
    
    cubo[0][0] = new Lista();
    (cubo[0][0])->agregar_pincipio(5);
    cubo[0][0]->mostrar_datos();

 
    

    destruir_cubo_lista(cubo, 4);

	return 0;
}
Lista ***crear_cubo_lista(size_t filas, size_t col){
    Lista ***lista = new Lista**[filas];

    for(size_t i = 0; i < filas; i++)
        lista[i] = new Lista*[col];

    return lista;
}
void destruir_cubo_lista(Lista ***lista, size_t filas){
    for(size_t i = 0; i < filas; i++)
        delete[] lista[i];

    delete[] lista;
}
Lista **crear_matriz_lista(size_t filas, size_t col){
    Lista **lista = new Lista*[filas];
    
    for(size_t i = 0; i < filas; i++)
       lista[i] = new Lista();

    return lista;
}
void destruir_matriz_listas(Lista **lista, size_t filas){
    for(size_t i = 0; i < filas; i++)
        delete lista[i];
    delete lista;
}
/* 
 * Pre: La lista debe estar creada e inicializada.
 * Post: Invierte la lista.
 */
void invertir_lista(Lista *lista){
    Nodo *anterior = NULL;
    Nodo *actual = lista->get_prim();
    Nodo *siguiente = actual ? actual->get_sig() : NULL;
    
    while(actual){
        actual->set_sig(anterior);
        anterior = actual;
        actual = siguiente;
        siguiente = actual ? actual->get_sig() : NULL;
    }
    lista->set_prim(anterior);
}

/*
 * Pre: Recibe como parametro la un estero positivo (k)
 */

int lista_ante_k_ultimo(Lista *lista, size_t k){
    Nodo *anterior = lista->get_prim();
    Nodo *actual = lista->get_prim();

    for(size_t i = 0; i < k; i++)
        actual = actual->get_sig();

    while(actual){
        anterior = anterior->get_sig();
        actual = actual->get_sig();
    }

    return anterior->get_dato();
}
/* 
 * Notas:
 * usar (cubo[0][0])->agregar_pincipio(5); es un error el 
 * cuadrado es bloque de memoria (un puntero a una lista)
 * para solucionarlo hacemos cubo[0][0] = new Lista();
 */
