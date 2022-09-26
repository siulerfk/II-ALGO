#ifndef LISTA_H
#define LISTA_H

#include "02-Nodo.h"

template<class T>
class Lista{
    public:
        Nodo<T> *prim;
        Nodo<T> *ult;
        Nodo<T> *iter;
        size_t cant;

    public:
        Lista(Nodo<T> *primero = NULL, Nodo<T> *ultimo = NULL, Nodo<T> *iterador = NULL, size_t cantidad = 0);
        ~Lista();
        
        void agregar_pincipio(T *info);
        void agregar_final(T *info);

        bool eliminar_primero();
        T *eliminar_buscado(const T *, int (*cmp)(const T *, const T *));
        
        void reiniciar_iterador();
        bool avanzar_iterador();
        
    };

// *************************** DEFINICIONES ***************************

template<class T>
Lista<T>::Lista(Nodo<T> *primero, Nodo<T> *ultimo, Nodo<T> *iterador, size_t cantidad){
	this->prim = primero;
	this->ult = ultimo;
    this->iter = iterador;
	this->cant = cantidad;
}

template<class T>
Lista<T>::~Lista(){
    this->ult = this->prim;
    for(size_t i = 0; i < this->cant; i++){
        this->prim = this->prim->get_sig(); 
        
        delete  this->ult;
        this->ult = this->prim;
    }
}

template<class T>
void Lista<T>::agregar_pincipio(T *info){
    this->prim = new Nodo<T>(this->prim, info);
    if(this->cant == 0)
    	this->ult = this->prim;
    this->cant++;
}

template<class T>
void Lista<T>::agregar_final(T *info){
	this->ult->set_sig(new Nodo<T>(NULL, info));
	this->ult = this->ult->get_sig();
	this->cant++;
}

template<class T>
bool Lista<T>::eliminar_primero(){
	Nodo<T> *aux = this->prim;
	
	if(this->prim){
		this->prim = this->prim->get_sig();

		delete aux;

		return true;
	}
	return false;
}

template<class T>
T *Lista<T>::eliminar_buscado(const T *dato, int (*cmp)(const T *a, const T *b)){
	Nodo<T> **pactual = &(this->prim);
	while(*pactual != NULL){
		Nodo<T> *actual = *pactual;

		if(cmp(actual->get_dato(), dato)){
			T *temp = actual->get_dato();
			*pactual = actual->get_sig();
			delete actual;
			return temp;
		}

		*pactual = &(actual->get_sig());
	}

	return NULL;
}


// ************ ITERADOR *******************
/* POST: Leaves iterador ready for new iteration. */
template<class T> 
void Lista<T>::reiniciar_iterador(){
	this->iterador = NULL;
}
/*
	Pre: Si no se inicializo o esta al final de la lista se lo coloca al
		inicio
	Post: Si esta en medio se avanza al siguiente. Retorna true si esta 
		posicionado en un Nodo
 */
template<class T>
bool Lista<T>::avanzar_iterador(){
	if(this->iterador == NULL){
		this->iterador = this->prim;
	}
	else{
		this->iterador = this->iterador->get_sig();
	}
	return (this->iterador != NULL);
}

#endif
