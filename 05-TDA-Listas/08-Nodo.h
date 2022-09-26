#ifndef NODO_H
#define NODO_H

#include <iostream>

template<class T>
class Nodo{
	private:
        Nodo<T> *sig;
        Nodo<T> *ante;
        T *dato;
	
	public:
        Nodo(Nodo<T> *prox = NULL, Nodo<T> *ante = NULL, T *info = NULL);
        Nodo(const Nodo<T> *);  // Constructor copia
        ~Nodo();
        
        Nodo<T> *get_sig();
        Nodo<T> *get_anterior();
        T *get_dato();
        
   	    void set_sig(Nodo<T> *n);
   	    void set_anterior(Nodo<T> *n);
        void set_dato(T *);
};
// *************************** DEFINICIONES ***************************

template<class T>
Nodo<T>::Nodo(Nodo<T> *sig, Nodo<T> *ante, T *dato){
	this->sig = sig;
	this->ante = ante;
	this->dato = dato;
}

// Constructor copia
template<class T>
Nodo<T>::Nodo(const Nodo<T> *prox){
    this->sig = prox->sig;
    this->ante = prox->ante;
    this->dato = prox->dato;
}

template<class T>
Nodo<T> *Nodo<T>::get_sig(){
    return this->sig;
}

template<class T>
Nodo<T> *Nodo<T>::get_anterior(){
    return this->ante;
}

template<class T>
T *Nodo<T>::get_dato(){
    return this->dato;
}

template<class T>
void Nodo<T>::set_sig(Nodo<T> *sig){
    this->sig = sig;
}

template<class T>
void Nodo<T>::set_anterior(Nodo<T> *ante){
    this->ante = ante;
}

template<class T>
void Nodo<T>::set_dato(T *info){
    this->dato = info;
}
#endif
