# 05-TDA-Lista
## Lista de Ejercicios:
Nota:
	La clase no no cambia tanto en listas enlazadas como en pilas y colas
	usar el archivo 02-Nodo.h como referencia; esté atchivo .h esta usando la
	plantilla template

cd ~/.local/share/nvim/swap/


**01.cpp**
Clases lista enlazada/ligada simple lista nodo (sparado en archivos. Makefile).

    Diseñar la clase ListaEnteros con los siguientes métodos:
        *- Constructor / Destructor
        *- Alta al principio
        *- Alta al final
        *- Alta en posición determinada
        *- Borrar primero
        *- Borrar último
        *- Borrar en determinada posición
        *- Borrar primer elemento (se indica qué elemento quiere ser borrado, y se borra su primera aparición)
        - Borrar elemento (se indica qué elemento quiere ser borrado y se borran todas sus apariciones)
        *- Obtener primero
        - Obtener último
        - Obtener el elemento de una posición determinada
        - Obtener el tamaño de la lista
        *- Listar (muestra todos los elementos de la lista)
        - Listar en forma inversa (muestra desde el último hasta el final)
        
        * Invertir lista funcion externa a la clase lista [1];
        * Escribir una primitiva que reciba una lista y devuelva el elemento
          que esta a k posiciones del final (el ante-k-ultimo), recorriendo la
          lista una sola vez y sin usar estrcturas auxiliares.
        * Dada una lista pasada por argumento, retornar otra que sea la intersecion de ambas
          Crear un método.(ver video 05 - clase)

    - Tener en cuenta que se pueden repetir los elementos.
    - Es importante que cada método tenga explícitas las PRE y POST condiciones.
    - [1] (min 56) https://www.youtube.com/watch?v=0dD0mojBAfI&t=3275s

**02.cpp**
    Se quiso agregar una primitava mas eliminar_buscado con punteros dobles; no se sabe por que 
    falla la asignacion del doble puntero(error). 
	(no terminado similar al 04.cpp)   Iterador
	Lista enlazada con dato (void *), template y lista tiene un contador y un Nodo principio / fin

**03.cpp**
	Entendimiento de como funcionan el pasaje por referencia y punteros (direccion de memoria).
	Diferencia entre:
		void funcion_1(char* &var)
		void funcion_1(char * var)

**04.cpp**
	TDA Lista enlazada itereador, esta hecho en clase con modificaines mias.

**05.cpp** 
	TDA Lista enlazada itereador, esta hecho en clase sin modificaciones. ejemplos

**06.cpp**
	TDA Pila

**07.cpp**
    TDA lista enlazada simple en varios archivos usando (void *dato) para
    guardar la informacion del nodo. Tambien se usa punteros a funciones para
    comparar entre los datos del Nodo.
    Se encontro una manera de compilar mas eficiente, ver archivo principal.


