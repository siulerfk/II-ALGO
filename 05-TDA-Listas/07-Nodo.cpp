#include "07-Nodo.h"
// Constructor
Nodo::Nodo(Nodo *sig, void *dato){
    this->sig = sig;
    this->dato = dato;
}
// Constructor copia
Nodo::Nodo(const Nodo *copia){
    this->sig = copia->sig;
    this->dato = copia->dato;
}
Nodo *Nodo::get_sig(){
    return this->sig;
}
void *Nodo::get_dato(){
    return this->dato;
}
void Nodo::set_dato(void *dato){
    this->dato = dato;
}
void Nodo::set_sig(Nodo *sig){
    this->sig = sig;
}
