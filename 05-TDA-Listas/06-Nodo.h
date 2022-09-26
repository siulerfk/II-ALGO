#ifndef NODO_H
#define NODO_H

#include <iostream>

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
	sig = prox;
	dato = info;
}

// Constructor copia
template<class T>
Nodo<T>::Nodo(const Nodo<T> *prox){
    sig = prox->sig;
    dato = prox->dato;
}

template<class T>
Nodo<T>* Nodo<T>::get_sig(){
    return sig;
}

template<class T>
T *Nodo<T>::get_dato(){
    return dato;
}

template<class T>
void Nodo<T>::set_dato(T *info){
    dato = info;
}

template<class T>
void Nodo<T>::set_sig(Nodo<T> *n){
    sig = n;
}

#endif
