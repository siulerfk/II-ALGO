/*
 * Como compilar:
		g++ -Wall -pedantic -std=c++98 02.cpp -o var
*/ 

#include <iostream>
#include "06-Nodo.h"

using namespace std;

template<class T>
class Pila{
	private:
		Nodo<T>* prim;
        size_t tope;
	public:
		Pila();
		~Pila();
        
        void push(T *info);  // Referencia a agregar al principio 
        bool pop();         // Referencia a eliminar al primero
        bool vacia()const;
        size_t get_tope();
        void mostrar_datos()const;
};
template<class T>
Pila<T>::Pila(){
    this->prim = NULL;
    tope = 0;
}

template<class T>
Pila<T>::~Pila(){
    while(tope)    
        pop();
}
template<class T>
bool Pila<T>::vacia()const{
    return this->tope == 0;
}

template<class T>
void Pila<T>::push(T *info){
   this->prim = new Nodo<T>(this->prim, info);
    tope++;
}

template<class T>
bool Pila<T>::pop(){
	Nodo<T> *aux = this->prim;
	
	if(this->prim){ // verificamos que la pila no este vacia
		this->prim = this->prim->get_sig();
		delete aux;
        
        tope--;
		return true;
	}
	return false;
}

template<class T>
size_t Pila<T>::get_tope(){
    return this->tope;
}

template<class T>
void Pila<T>::mostrar_datos()const{
	if(this->prim){
		Nodo<T> *aux =this->prim;
		
		cout << "************************************************\n";	
		while(aux){
			cout << *(aux->get_dato()) << " ";
			aux = aux->get_sig();
		}
		cout << endl;
		cout << "************************************************\n";

	}
}
int main(void){
    Pila<int> *enteros = new Pila<int>;
    int numeros[] = {45, 423, 45, 7, 54, 65, 77, 11, 54, 65, 77, 11, 3};
    size_t tope = sizeof(numeros) / sizeof(numeros[0]);

    for(size_t i = 0; i < tope; i++)
        enteros->push(&numeros[i]);

    enteros->mostrar_datos(); 
    
    enteros->pop();

    enteros->pop();

    enteros->mostrar_datos(); 
    
    delete enteros;
    
    Pila<char> *cadena = new Pila<char>;
    
    char *nombres[] = {(char *)"Juanito", (char *)"calos"};

    cadena->push(nombres[0]);

    cadena->mostrar_datos(); 

    delete cadena;
    return 0;
}
