#ifndef LISTA_H
#define LISTA_H

#include "08-Nodo.h"

template<class T>
class Lista{
	public:
		Nodo<T> *prim;
		Nodo<T> *ult;
		Nodo<T> *iterador;
		size_t cant;

	public:
		Lista(Nodo<T> *primero = NULL, Nodo<T> *ultimo = NULL, size_t cantidad = 0);
		~Lista();
		
		void agregar_pincipio(T *info);
		void agregar_final(T *info);

		bool eliminar_primero();
		T *eliminar_buscado(const T *, int (*cmp)(const T *, const T *));
		
		void reiniciar_iterador();
		bool avanzar_iterador();
		
};

#endif
