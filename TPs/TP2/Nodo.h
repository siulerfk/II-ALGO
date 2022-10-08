#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

template<class T>
class Nodo{
	private:
		Nodo<T> *sig;
		T *dato;
	public:
		Nodo(Nodo<T> *prox = NULL, T *info = NULL);
        Nodo(const Nodo<T> *);  // Constructor copia
        
        Nodo<T> *get_sig();
        T *get_dato();

        void set_dato(T *);
   	    void set_sig(Nodo<T> *n);
};

// *************************** DEFINICIONES ***************************

template<class T>
Nodo<T>::Nodo(Nodo<T> *prox, T *info){
	this->sig = prox;
	this->dato = info;
}

// Constructor copia
template<class T>
Nodo<T>::Nodo(const Nodo<T> *prox){
    this->sig = prox->sig;
    this->dato = prox->dato;
}

template<class T>
Nodo<T> *Nodo<T>::get_sig(){
    return this->sig;
}

template<class T>
T *Nodo<T>::get_dato(){
    return this->dato;
}

template<class T>
void Nodo<T>::set_dato(T *info){
    this->dato = info;
}

template<class T>
void Nodo<T>::set_sig(Nodo<T> *sig){
    this->sig = sig;
}

#endif
