#include "07-Lista.h"

Lista::Lista():prim(NULL){}

Lista::~Lista(){
    if(prim){
        Nodo *aux = prim;
        while(aux){
            prim = prim->get_sig();
            delete aux;
            aux = prim;
        }
    }
}

void Lista::agregar_pincipio(void *dato){
    prim = new Nodo(prim, dato);
}

void Lista::agregar_final(const void *dato){
    Nodo *actual = prim;

    if(prim == NULL)        // Validacion Lista vacia.
        prim = new Nodo(prim, (void *)dato);
    else{
        while(actual->get_sig() != NULL)
            actual = actual->get_sig();
        
        actual->set_sig(new Nodo(NULL, (void *)dato));
    }

}
/* 
 * Pre: Las posiciones de los Nodos comienzan desde cero.
 * Post: Retorna "true" si se agrego correctamente "false" sino.
 */
bool Lista::agregar_posicion(void *dato, const size_t pos){
	Nodo *nuevo = new Nodo(NULL, dato);
	
	Nodo *anterior = NULL;
	Nodo *actual = prim;
	
	size_t contador = 0;

	if(pos == 0){							// Si la posicion esta al principio
        nuevo->set_sig(prim);
        prim = nuevo;

        return true;
	}
	else if(prim){
        while(contador < pos && actual){
            anterior = actual;
            actual = actual->get_sig();
            contador++;
        }

        if(actual != NULL){					// Si la posicion esta en medio		
            anterior->set_sig(nuevo);
            nuevo->set_sig(actual);

            return true;
        }
        else if(pos == contador && actual == NULL){ // Si la posicion esta al final
            anterior->set_sig(nuevo);

            return true;
        }
        
    }

    return false;
}

bool Lista::eliminar_primero(){
    Nodo *aux = prim;

    if(prim){
        prim = prim->get_sig();

        delete aux;

        return true;
    }
	return false;
}
/*
	Pre: Recibe argumento entero positivo, incluyendo el cero.
	Post: Si elimino algo retorna true sino false y no modifica la lista.
*/
bool Lista::eliminar_posicion(const size_t pos){
    Nodo *anterior = NULL;
    Nodo *actual = prim;

    size_t contador = 0;

    if(pos == 0 && eliminar_primero()) // Elimina el primero.
        return true;
    else if(prim){
        while(contador < pos && actual->get_sig()){
            anterior = actual;
            actual = actual->get_sig();

            contador++;
        }
        if(contador == pos){
            anterior->set_sig(actual->get_sig());
            delete actual;

            return true;	
        }

    }

    return false;
}
/*
 * Pre: La posicion recibida debe ser mayor que cero.
 * Post: Si la posicion esta fuera de rango (tamaño de 
 *       la lista), se retona NULL.
 */
void *Lista::obtener_dato(const size_t pos)const{
    size_t n = 0;
    Nodo *actual = this->prim;

    while(n < pos && actual != NULL){
        n++;
        actual = actual->get_sig(); 
    }
    
    if(actual == NULL)
        return NULL;

    return actual->get_dato();
}
void *Lista::buscar_dato(const void *dato, int (*cmp)(const void *a, const void *b)){
    Nodo *actual = prim;

    while(actual != NULL){
        if(cmp(actual->get_dato(), dato) == 0)
            return actual->get_dato();

        actual = actual->get_sig();
    }

    return NULL;
}
/* 
 * Post: Retorna la cantidad de Nodos en la Lista.
 */
size_t Lista::lista_largo()const{
    size_t n = 0;
    Nodo *actual = this->prim;

    while(actual != NULL){
        n++;
        actual = actual->get_sig(); 
    }
           
    return n; 
}


