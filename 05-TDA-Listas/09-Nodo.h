#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T> 
class Nodo{
    private:
        Nodo<T>* siguiente;
        T dato;
    public:
        Nodo(T dato);
        T obtenerDato();
        void cambiarDato(T nuevoDato);
        Nodo<T>* obtenerSiguiente();
        void cambiarSiguiente(Nodo<T>* nuevoSiguiente);
};
/*
 * post: el Nodo resulta inicializado con el dato dado
 *       y sin un Nodo siguiente.
 */
template<class T> 
Nodo<T>::Nodo(T dato){
    this->dato = dato;
    this->siguiente = NULL;
}

/*
 * post: devuelve el valor del dato.
 */
template<class T> 
T Nodo<T>::obtenerDato(){
    return this->dato;
}

/*
 * post: cambia el valor del dato.
 */
template<class T> 
void Nodo<T>::cambiarDato(T nuevoDato){
    this->dato = nuevoDato;
}

/*
 * post: devuelve el siguiente Nodo.
 */
template<class T> 
Nodo<T>* Nodo<T>::obtenerSiguiente() {
    return this->siguiente;
}

/*
 * post: cambia el siguiente Nodo por nuevoSiguiente.
 */
template<class T> 
void Nodo<T>::cambiarSiguiente(Nodo<T>* nuevoSiguiente) {
    this->siguiente = nuevoSiguiente;
}

#endif /* NODO_H_ */
