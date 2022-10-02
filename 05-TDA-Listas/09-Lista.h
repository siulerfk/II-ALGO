#ifndef LISTA_H_
#define LISTA_H_

#include "09-Nodo.h"

/*
 * Una Lista es una colecci�n din�mica de elementos dispuestos en una secuencia.
 *
 * Define operaciones para agregar, remover, acceder y cambiar elementos
 * en cualquier posici�n.
 *
 * Tiene un cursor que permite recorrer todos los elementos secuencialmente.
 *
 */
template<class T> 
class Lista {
    private:
        Nodo<T>* primero;
        unsigned int tamanio;
        Nodo<T>* cursor;
    public:
        Lista();
        Lista(Lista<T>& otraLista);

        bool estaVacia();

        unsigned int contarElementos();

        void agregar(T elemento);
        void agregar(T elemento, unsigned int posicion);
        void agregar(Lista<T> &otraLista);

        T obtener(unsigned int posicion);

        void asignar(T elemento, unsigned int posicion);
        void remover(unsigned int posicion);

        void iniciarCursor();
        bool avanzarCursor();
        T obtenerCursor();

        ~Lista();

    private:
        Nodo<T>* obtenerNodo(unsigned int posicion); // NOTA: primitiva PRIVADA
};

/*
 * post: Lista vacía.
 */
template<class T> 
Lista<T>::Lista(){
    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;
}

/*
 * post: Lista que tiene los mismos elementos que otraLista.
 *       La instancia resulta en una copia de otraLista.
 */
template<class T> 
Lista<T>::Lista(Lista<T>& otraLista) {
    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;

    /* copia los elementos de otraLista */
    this->agregar(otraLista);
}
/*
 * post: indica si la Lista tiene algún elemento.
 */
template<class T>
bool Lista<T>::estaVacia() {
    return (this->tamanio == 0);
}

/*
 * post: devuelve la cantidad de elementos que tiene la Lista.
 */
template<class T>
unsigned int Lista<T>::contarElementos() {
    return this->tamanio;
}

/*
 * post: agrega el elemento al final de la Lista, en la posición:
 *       contarElementos() + 1.
 */
template<class T>
void Lista<T>::agregar(T elemento) {
    this->agregar(elemento, this->tamanio + 1);
}

/*
 * pre : posición pertenece al intervalo: [1, contarElementos() + 1]
 * post: agrega el elemento en la posición indicada.
 *
 */
template<class T>
void Lista<T>::agregar(T elemento, unsigned int posicion) {
    if((posicion > 0) && (posicion <= this->tamanio + 1)){
        Nodo<T>* nuevo = new Nodo<T>(elemento);

        if(posicion == 1){
            nuevo->cambiarSiguiente(this->primero);
            this->primero = nuevo;
        }
        else{
            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
            anterior->cambiarSiguiente(nuevo);
        }

        this->tamanio++;

        /* cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }

}

/*
 * post: agrega todos los elementos de otraLista
 *       a partir de la posición contarElementos() + 1.
 */
template<class T>
void Lista<T>::agregar(Lista<T> &otraLista) {
    otraLista.iniciarCursor();

    while(otraLista.avanzarCursor())
        this->agregar(otraLista.obtenerCursor());
}

/*
 * pre : posición pertenece al intervalo: [1, contarElementos()]
 * post: devuelve el elemento en la posición indicada.
 */
template<class T>
T Lista<T>::obtener(unsigned int posicion) {
    T elemento;

    if ((posicion > 0) && (posicion <= this->tamanio)) 
        elemento = this->obtenerNodo(posicion)->obtenerDato();

    return elemento;
}

/*
 * pre : posicioó pertenece al intervalo: [1, contarElementos()]
 * post: cambia el elemento en la posición indicada por el
 *       elemento dado.
 */
template<class T> 
void Lista<T>::asignar(T elemento, unsigned int posicion) {
    if ((posicion > 0) && (posicion <= this->tamanio)) 
        this->obtenerNodo(posicion)->cambiarDato(elemento);
}

/*
 * pre : posición pertenece al intervalo: [1, contarElementos()]
 * post: remueve de la Lista el elemento en la posición indicada.
 */
template<class T> 
void Lista<T>::remover(unsigned int posicion) {
    if ((posicion > 0) && (posicion <= this->tamanio)){
        Nodo<T>* removido;

        if (posicion == 1){
            removido = this->primero;
            this->primero = removido->obtenerSiguiente();
        } 
        else{
            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            removido = anterior->obtenerSiguiente();
            anterior->cambiarSiguiente(removido->obtenerSiguiente());
        }

        delete removido;
        this->tamanio--;

        /* cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }
}
/*
 * post: deja el cursor de la Lista preparado para hacer un nuevo
 *       recorrido sobre sus elementos.
 */
template<class T> 
void Lista<T>::iniciarCursor(){
    this->cursor = NULL;
}

/*
 * pre : se ha iniciado un recorrido (invocando el método
 *       iniciarCursor()) y desde entonces no se han agregado o
 *       removido elementos de la Lista.
 * post: mueve el cursor y lo posiciona en el siguiente elemento
 *       del recorrido.
 *       El valor de retorno indica si el cursor quedó posicionado
 *       sobre un elemento o no (en caso de que la Lista esté vacía o
 *       no existan más elementos por recorrer.)
 */
template<class T>
bool Lista<T>::avanzarCursor() {
    if (this->cursor == NULL) 
        this->cursor = this->primero;
    else 
        this->cursor = this->cursor->obtenerSiguiente();
    
    /* pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);
}

/*
 * pre : el cursor est� posicionado sobre un elemento de la Lista,
 *       (fue invocado el m�todo avanzarCursor() y devolvi� true)
 * post: devuelve el elemento en la posici�n del cursor.
 *
 */
template<class T>
T Lista<T>::obtenerCursor() {
    T elemento;

    if (this->cursor != NULL) 
        elemento = this->cursor->obtenerDato();

    return elemento;
}

/*
 * post: libera los recursos asociados a la Lista.
 */
template<class T>
Lista<T>::~Lista() {
    while (this->primero != NULL){
        Nodo<T>* aBorrar = this->primero;
        this->primero = this->primero->obtenerSiguiente();

        delete aBorrar;
    }
}

/*
 * pre : posición pertenece al intervalo: [1, contarElementos()]
 * post: devuelve el nodo en la posición indicada.
 */
template<class T>
Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion) {
    Nodo<T>* actual = this->primero;
    for (unsigned int i = 1; i < posicion; i++) 
        actual = actual->obtenerSiguiente();

    return actual;
}

#endif /* LISTA_H_ */
