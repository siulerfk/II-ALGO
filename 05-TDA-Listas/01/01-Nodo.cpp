#include "01-Nodo.h"
// Constructor
Nodo::Nodo(){
    sig = NULL;
    dato = 0;
}
// Constructor
Nodo::Nodo(Nodo *ptr, int info){
    sig = ptr;
    dato = info;
}
// Constructor copia
Nodo::Nodo(const Nodo *ptr){
    sig = ptr->sig;
    dato = ptr->dato;
}
Nodo *Nodo::get_sig(){
    return sig;
}
int Nodo::get_dato(){
    return dato;
}
void Nodo::set_dato(int info){
    dato = info;
}
void Nodo::set_sig(Nodo *n){
    sig = n;
}